class PCQ           // a bounded, blocking FIFO producer-consumer queue
{
public:
    PCQ(int n) : max_count_(n), non_full_(&mu_), non_empty_(&mu_) {}
    ~PCQ() { CHECK_EQ(this->queue_.size(), 0); }        // error if queue is not empty

    // waits until queue is not full, then adds value to its end
    void Add(void *value) {
        this->mu_.Acquire();
        while (this->queue_.size() == this->max_count_) {
            this->non_full_.Wait();
        }
        this->non_empty_.Signal(); // no need to Broadcast.
                                   // (only one remover can consume this item)
                                   // Could use:
                                   // if (this->queue_.size() == 0) { this->non_empty_.Broadcast(); }
        this->queue_.push_back(value);
        this->mu_.Release();
    }

    // waits until this queue is non-empty, then removes and returns first value
    void *Remove() {
        this->mu_.Acquire();
        while (this->queue_.size() == 0) {
            this->non_empty_.Wait();
        }
        this->non_full_.Signal(); // no need to Broadcast.
                                  // (only one adder can consume this gap)
                                  // Could use:
                                  // if (this->queue_.size() == this->max_count_) { this->non_full_.Broadcast(); }
        void *value = this->queue_.front();
        this->queue_.pop_front();
        this->mu_.Release();
        return value;
    }

private:
    Lock mu_;                // protects *queue_
                             // protects invariant 0 <= queue_.size() <= max_count_
    deque<void *> queue_; // list of queued items
    const int max_count_;  // max number of items in *queue_ (readonly after init)
  
    ConditionVariable non_full_;    // signalled when queue becomes non-full
    ConditionVariable non_empty_;   // signalled when queue becomes non-empty
};
