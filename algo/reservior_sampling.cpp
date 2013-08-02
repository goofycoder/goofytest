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

typedef int Item;
#define SAMPLE_NUM 10
#define STREAM_LEN 100

/* Helper functions */
void display_samples(const Item* samples, unsigned sample_size);
Item* stream_source();

/* MAJOR function */
void reservior_sample(const Item* stream) 
{
    Item samples[SAMPLE_NUM] = {0};     // short-cut: by default int type
    Item curItem;                       // current item
    int  sample_idx = 0;

    bool sampling_flag = true;

    do {
        /* fetch the item from stream */
        curItem = *(stream+sample_idx);
        
        if (sample_idx <= SAMPLE_NUM) {
            /* build the reservior
             * add_item_to_sample(curItem);
             */
            samples[sample_idx] = curItem;
        } else {
            /* random sample */
            srand(time(NULL));
            int r = rand() % sample_idx;
            if (r < SAMPLE_NUM) {
                samples[r] = curItem;
            }
        }

        sample_idx++;

        display_samples(samples, SAMPLE_NUM);

        /* Could be unbound. But for test purpose, 
         * stop sampling after sample all items in stream
         */
        if (sample_idx == STREAM_LEN) {
            sampling_flag = false;
        }

    } while (sampling_flag);
}

int main() 
{
    Item* stream = stream_source();
    
    reservior_sample(stream);
 
    delete[] stream;     // just for test purpose
   
    return 0;
}

Item* stream_source()
{
    Item* stream = new Item[STREAM_LEN];
    int pos=0;

    do {
        stream[pos] = pos;
        pos++;
    } while (pos<STREAM_LEN);

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
