// 1116. Print Zero Even Odd


// 1. Using promise
class ZeroEvenOdd {
private:
    int n;

    //Approach-01: Using promise in C++
    std::promise<void> p0, p1, p2;
    int ev = 2;
    int od = 1;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        p0.set_value();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        p0.get_future().wait();
        std::cout<<0;
        p1.set_value();
    }

    void even(function<void(int)> printNumber) {
        p1.get_future().wait();
        std::cout<<ev;
        ev++;
        p2.set_value();
    }

    void odd(function<void(int)> printNumber) {
        p2.get_future().wait();
        std::cout<<od;
        od++;
        p0.set_value();
    }
};


// 2. Using Only Mutex

class ZeroEvenOdd {
private:
    int n;

    //Approach:-02: Using mutex only
    std::mutex mtx0, mtxEven, mtxOdd;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        mtxEven.lock();
        mtxOdd.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {

        for(int i=1;i<=n;i++){
            mtx0.lock();
            printNumber(0);
            if(i%2!=0) mtxOdd.unlock();
            else mtxEven.unlock();
        }
    }

    void even(function<void(int)> printNumber) {

        for(int i=2;i<=n;i+=2){
            mtxEven.lock();
            printNumber(i);
            mtx0.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1;i<=n;i+=2){
            mtxOdd.lock();
            printNumber(i);
            mtx0.unlock();
        }
    }
};


///*********** Working code start here

// 3. using mutex, condition variable, unique_lock
class ZeroEvenOdd {
private:
    int n;

    //Approach:-02: Using mutex, condition variable, unique pointer lock
    std::mutex mtx;
    std::condition_variable cv;
    int i;
    int flag;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        i = 1;
        flag = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {

        for(int i=1;i<=n;i++){
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this] {return flag==0;});

            printNumber(0);
            if(i%2==0) flag = 2;
            else flag = 1;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {

        for(int i=2;i<=n;i+=2){
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this] {return flag==2;});

            printNumber(i);
            flag = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        
        for(int i=1;i<=n;i+=2){
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this]{return flag==1;});
            
            printNumber(i);
            flag = 0;
            cv.notify_all();
        }
    }
};


// 4. Using Semaphore

class ZeroEvenOdd {
private:
    int n;

    //Approach:-02: Using Semaphore
    sem_t sem_zero, sem_even, sem_odd; 

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&sem_zero, 0, 1);
        sem_init(&sem_even, 0, 0);
        sem_init(&sem_odd, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=1;i<=n;i++){
            sem_wait(&sem_zero);
            printNumber(0);
            if(i%2==0) sem_post(&sem_even);
            else sem_post(&sem_odd);
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=2;i<=n;i+=2){
            sem_wait(&sem_even);
            printNumber(i);
            sem_post(&sem_zero);
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1;i<=n;i+=2){
            sem_wait(&sem_odd);
            printNumber(i);
            sem_post(&sem_zero);
        }
    }
};





