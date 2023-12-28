// 1195. Fizz Buzz Multithreaded


// 1. Using Mutex, Condition Variable, Uniqueu Lock
class FizzBuzz {
private:
    int n;

    //Approach-01: Using Condition Variable, Mutex and Unique Lock
    std::mutex mtx;
    std::condition_variable cv;
    bool flag;
    int i;


public:
    FizzBuzz(int n) {
        this->n = n;
        flag = 0;
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {

        while(i<=n){
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this]{return (i%15!=0 and i%3==0) or i>n;});

            if(i>n) return;
            printFizz();
            i++;

            lck.unlock();
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {

        while(i<=n){ 
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this]{return (i%15!=0 and i%5==0) or i>n;});

            if(i>n) return;
            printBuzz();
            i++;
        
            lck.unlock();
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {

        while(i<=n){
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this]{return (i%3==0 and i%5==0) or i>n;});

            if(i>n) return;
            printFizzBuzz();
            i++;
         
            lck.unlock();
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {

        while(i<=n){
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this]{return i>n or (i%3!=0 and i%5!=0);});

            if(i>n) return;
            printNumber(i);
            i++;

            lck.unlock();
            cv.notify_all();
        }
    }
};







	