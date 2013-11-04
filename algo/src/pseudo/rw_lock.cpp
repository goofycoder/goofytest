class RWLock 
{
public:
    RWAcquire() : lockers_(0), lock_free_(&mu_) {}
    ~RWAcquire() {}
  
    void WriteAcquire()             // acquire a write lock
    {
        this->mu_.Acquire();
        while (this->lockers_ != 0) {
            this->lock_free_.Wait();
        }
        
        this->lockers_ = -1;
        this->mu_.Release();
    }
  
    void ReadAcquire()               // acquire a read lock
    {
        this->mu_.Acquire();
        
        while (this->lockers_ < 0) {
            this->lock_free_.Wait();
        }
        
        this->lockers_++;
        this->mu_.Release();
    }
    
    void Release()                 // release lock (either mode)
    {
        this->mu_.Acquire();
        this->lockers_ = (this->lockers_ == -1? 0 : this->lockers_ - 1);
        
        if (this->lockers_ == 0) {        // if lock became free, wake all waiters
            this->lock_free_.Broadcast();
        }
        
        this->mu_.Release();
    }
    
private:
    Lock mu_;                       // protects lockers_
    int lockers_;                   // 0 => free, -1 => writer, +ve => reader count
    ConditionVariable lock_free_;   // signalled when lockers_ becomes 0
};
