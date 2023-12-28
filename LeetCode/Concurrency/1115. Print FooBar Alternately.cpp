// 1115. Print FooBar Alternately



/*This is basically a semaphore. We use the flag fooTurn in the predicate of wait() to determine if the lock should be freed.

Because there are only two states (foo and bar), we can get away with using a boolean for the flag and notify_one(). 
If there were more states, we could scale this using an int flag and notify_all().

If you're wondering why foo runs for the first time at all despite the cv.wait(), it's because the line is actually a shorthand 
for while (!fooTurn) { cv.wait(lock); }. Since fooTurn is initialized as true, the cv.wait() gets ignored.*/
	

class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool fooTurn = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {

            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this] {return fooTurn; });
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();


            fooTurn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {

            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this] {return !fooTurn;});
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            fooTurn = true;
            cv.notify_one();
        }
    }
};