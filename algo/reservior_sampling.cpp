/* 
 * Reservoir sampling 
 * Randomly select k items from a stream of items of unknown length. 
 * Step 1: Save the first k items in an array of size k. 
 * Step 2: For each item j, j > k, choose a random integer M from 1 to j (inclusive). 
 *         If M ≤ k, replace item M of the array with item j. 
 * Analysis: 
 *      http://blogs.msdn.com/b/spt/archive/2008/02/05/reservoir-sampling.aspx
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <new>
#include "algo.hpp"

void reservior_sample(const Item* stream, const unsigned& stream_len,
                      Item* samples, unsigned sample_size) 
{
    Item curItem;                       // current item
    unsigned sample_idx = 0;

    bool sampling_flag = true;

    do {
        /* fetch the item from stream */
        curItem = *(stream+sample_idx);
        
        if (sample_idx <= sample_size) {
            /* build the reservior
             * add_item_to_sample(curItem);
             */
            samples[sample_idx] = curItem;
        } else {
            /* random sample */
            srand(time(NULL));
            unsigned r = rand() % sample_idx;
            if (r < sample_size) {
                samples[r] = curItem;
            }
        }

        sample_idx++;

        /* Could be unbound. But for test purpose, 
         * stop sampling after sample all items in stream
         */
        if (sample_idx == stream_len) {
            sampling_flag = false;
        }
    } while (sampling_flag);
}

Item* stream_source(const int &stream_len)
{
    Item* stream = new Item[stream_len];
    int pos=0;

    do {
        stream[pos] = pos;
        pos++;
    } while (pos<stream_len);

    return stream;
}

void display_samples(const Item* samples, unsigned sample_size) 
{
    unsigned i;

    for(i=0; i<sample_size; i++) {
        std::cout << samples[i] << " ";
    }

    std::cout << "\n";
}

void TEST_reservoir_sampling()
{
    unsigned stream_len;
    unsigned sample_size;
    std::cout << "\n *** TEST for Reservoir Sampling ***\n"
              << "Enter the stream length: ";
    std::cin >> stream_len; 
    
    std::cout << "\n Enter the number of samples: ";
    std::cin >> sample_size;
    
    // generate stream
    Item* stream = stream_source(stream_len);
    Item samples[sample_size];
    
    reservior_sample(stream, stream_len, samples, sample_size);
    
    display_samples(samples, sample_size);

    delete[] stream;
}
