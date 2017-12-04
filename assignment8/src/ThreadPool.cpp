// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// ThreadPool.cpp

#include "ThreadPool.h"

/*
    Default constructor with basic default data member setups
*/

ThreadPool::ThreadPool()
    :   workers(),
        taskQueue(),
        taskCount(0),
        _mutex(),
        condition(),
        stop(false) {}

/*
    Thread pool constructor with number of threads
    Parameters: threads
*/

ThreadPool::ThreadPool( size_t threads ) : ThreadPool() {
    initializeWithThreads( threads );
}

/*
    Destructor: joins all threads
*/

ThreadPool::~ThreadPool() {
    stop = true;
    condition.notify_all();
    for ( thread& w: workers ) {
        w.join();
    }
}

/*
    Creates worker threads based on the size given from the constructor
    Parameters: threads
*/

void ThreadPool::initializeWithThreads(size_t threads) {
    for (size_t i = 0; i < threads; i++) {
        workers.emplace_back( [this]() -> void {
            while (true) {
                function<void()> task;
                {
                    unique_lock<mutex> lock( _mutex );
                    condition.wait( lock, [this]() -> bool {
                        return !taskQueue.empty() || stop;
                    });

                    if ( stop && taskQueue.empty() ) {
                        return;
                    }

                    task = move( taskQueue.front() );
                    taskQueue.pop();
                }
                task();
                taskCount--;
            }
        });
    }
}

/*
    Schedules a new task by inserting it into the queue
    Parameters: function to be inserted
*/

void ThreadPool::schedule(const function<void()>& task) {
    {
        unique_lock<mutex> lock(_mutex);
        taskQueue.push(task);
    }
    taskCount++;
    condition.notify_one();
}
