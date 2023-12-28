// 1117. Building H2O


// 1. Approach-01: Using Mutex, condition_variable, unique_lock
class H2O {
public:

    std::mutex mtx;
    std::condition_variable cv;
    int h;
    int o;

    H2O() {
        h = 0;
        o = 1;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [this] { return h<2;});

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        h++;
        if(h==2) o = 0;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [this]{ return o==0;});

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        o = 1;
        h = 0;
        cv.notify_all();
    }
};