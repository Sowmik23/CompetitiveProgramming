// 1114. Print in Order


//Method-01: using std::promise in c++
class Foo {
private:
    std::promise<void> p1, p2;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        p1.set_value();
    }

    void second(function<void()> printSecond) {
        p1.get_future().wait();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        p2.set_value();
    }

    void third(function<void()> printThird) {
        p2.get_future().wait();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};



// Method-02: using mutex and semaphore(condition variable)

class Foo {
private:
    int cnt;
    mutex mtx; //mutex: are used for mutual exclusion i.e to safe gaurd the critical sections of a code
    condition_variable cv; //semaphore: are used for thread synchronisation(which is what we want to achieve here).

//     Mutex have ownership assigned with them, that is to say, the thread that locks a 
//      mutex must only unlock it. Also, we must not unlock a mutex that has not been 
//      locked (This is what most programs have got wrong).
//      If the mutex is not used as said above, the behavior is undefined, 
//      which however in our case produces the required result.
public:
    Foo() {
        cnt = 0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        cnt = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);
        while(cnt!=1){
            cv.wait(lck);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        cnt = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);
        while(cnt!=2){
            cv.wait(lck);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};