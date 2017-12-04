// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// ThreadPool.h

#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <functional>
#include <chrono>

using namespace std;

class ThreadPool {
    public:
        ThreadPool();
        ThreadPool( size_t threads );
        ~ThreadPool();

        void initializeWithThreads( size_t threads );
        void schedule( const function<void()>& );

    private:
        vector <thread> workers;
        queue <function<void()>> taskQueue;
        atomic_uint taskCount;
        mutex _mutex;
        condition_variable condition;
        atomic_bool stop;
};
#endif // THREAD_POOL_H
