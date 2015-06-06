//
// Created by m on 5/06/15.
//

#ifndef MWBARCODE_PROCESSIMAGES_H
#define MWBARCODE_PROCESSIMAGES_H


#include <vector>
#include <mutex>
#include <atomic>
#include <thread>

#include "BoostHeaders.h"
#include "MagickHeaders.h"

#include "MwImage.h"

using namespace std;
using namespace boost::filesystem;

class ProcessImages {
public:

    struct out_struct
    {
        MwColor mwc;
    };


    explicit ProcessImages(size_t _no_of_threads, const vector<path>& _paths);

    void start_threads();
    void join_threads();
    


private:
    size_t no_of_threads {1};
    vector<thread> processing_threads;
    vector<path> file_paths;
    size_t no_of_files;
    vector<out_struct> out_values;
    mutex process_mutex;
    atomic<size_t> i {0};

    void execute();

};


#endif //MWBARCODE_PROCESSIMAGES_H
