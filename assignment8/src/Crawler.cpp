// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// Crawler.cpp

#include "Crawler.h"

/*
    Constructor
    Parameters: url roots, whitelist filename, blacklist filename, destination directory,
    number of pages to crawl if reached, concurrency limit 
*/

Crawler::Crawler(
    unordered_set <string> inputRoots,
    const string &hostWhitelistFilename = "",
    const string &hostBlacklistFilename = "",
    const string &destDir = "data",
    const int numPagesToCrawl = 50,
    const size_t concurrencyLimit = 2
) : pool(concurrencyLimit) {
    roots = inputRoots;
    dataDirectory = destDir;
    readFileToSet(hostWhitelistFilename, hostWhitelist);
    readFileToSet(hostBlacklistFilename, hostBlacklist);
    startCrawl();
}

/*
    Crawler destructor
*/

Crawler::~Crawler() {

}

/*
    Reads input file into set
    Parameters: filename, string set
*/

void Crawler::readFileToSet(const string &filename, unordered_set <string> set) {
    if (filename.length() > 0) {
        ifstream file (filename);
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                set.insert(line);
            }
            file.close();
        }
    }
}

/*
    Begins the crawling by scheduling the root urls
*/

void Crawler::startCrawl() {
    for (unordered_set <string>::iterator it = roots.begin(); it != roots.end(); it++) {
        pool.schedule([this, it] {
            this->crawlTask(*it);
        });
    }
}

/*
    Crawls a url with curl and schedules urls found on that page for later crawling
    Parameters: url
*/

void Crawler::crawlTask(string url) {
    this->numPagesCrawled++;
    seenUrls.insert(url);
    stringstream ss;
    size_t generatedHash = h(url);
    ss << generatedHash;
    string filename = ss.str();
    string command = "curl -Ls " + url + " | tee " + this->dataDirectory + "/" + filename.c_str();
    string body = this->exec(command.c_str());
    cout << url << endl;
    smatch sm;
    const regex r("(http|https)://([\\w_-]+(?:(?:\\.[\\w_-]+)+))([\\w.,@?^=%&:/~+#-]*[\\w@?^=%&/~+#-])?");
    if (regex_search(body, sm, r)) {
        for (int i = 0; i < sm.size(); i++) {
            string url = sm[i];
            unordered_set <string>::iterator it = seenUrls.find(url);
            if (hostBlacklist.size() > 0 && hostWhitelist.size() > 0) {
                unordered_set <string>::iterator itBlack = hostBlacklist.find(url);
                unordered_set <string>::iterator itWhite = hostWhitelist.find(url);
                if (it == seenUrls.end() && itBlack == hostBlacklist.end() && itWhite != hostWhitelist.end()) {
                    this->pool.schedule([this, url] {
                        this->crawlTask(url);
                    });
                }
            }
            else {
                if (it == seenUrls.end()) {
                    this->pool.schedule([this, url] {
                        this->crawlTask(url);
                    });
                }
            }
        }
    }
    cout << "Crawled " + to_string(numPagesCrawled) + " total web pages. " << endl;
}

/*
    Executes bash function and returns standard output as a string
    Parameters: command
    Returns: standard output as a string
*/

string Crawler::exec(const char* cmd) {
    array<char, 128> buffer;
    string result;
    shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr) {
            result += buffer.data();
        }
    }
    return result;
}
