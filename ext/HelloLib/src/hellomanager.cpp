/*****************************************************************************************
 *                                                                                       *
 * Copyright (c) 2014                                                                    *
 *                                                                                       *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this  *
 * software and associated documentation files (the "Software"), to deal in the Software *
 * without restriction, including without limitation the rights to use, copy, modify,    *
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to    *
 * permit persons to whom the Software is furnished to do so, subject to the following   *
 * conditions:                                                                           *
 *                                                                                       *
 * The above copyright notice and this permission notice shall be included in all copies *
 * or substantial portions of the Software.                                              *
 *                                                                                       *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,   *
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A         *
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT    *
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  *
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE  *
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                         *
 ****************************************************************************************/
 
#include <hellolib/hellomanager.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <random>

namespace hlib {

    void helloFunction(Hello* speaker, std::mutex* printMutex) {
        for (int i = 0; i < 5; ++i) {
        
            // lock mutex to prevent errors in out stream
            printMutex->lock();
            speaker->sayHello(std::cout);
            printMutex->unlock();
            
            // Sleep for a random time
            std::default_random_engine generator;
            std::uniform_int_distribution<int> distribution(1,100);
            int sleepTime = distribution(generator);
            std::chrono::milliseconds dura( sleepTime );
            std::this_thread::sleep_for( dura );
        }
    }
    
    HelloManager::HelloManager() {}
    HelloManager::~HelloManager() {
        for(auto speaker: _speakers) {
            delete speaker;
        }
    }
    
    void HelloManager::addSpeaker(Hello* s) {
        if (s) {
            _speakers.push_back(s);
        }
    }
    
    void HelloManager::sayHello() {
    
        const int numThreads = _speakers.size();
        std::thread *t = new std::thread[numThreads];
        
        // Spawn a group of threads
        for (int i = 0; i < numThreads; ++i) {
            t[i] = std::thread(helloFunction, _speakers.at(i), &_printMutex);
        }
        
        // join threads
        for (int i = 0; i < numThreads; ++i) {
            t[i].join();
        }
    }
}