// 1226. The Dining Philosophers
class DiningPhilosophers {
public:

    int n;
    vector<std::mutex> mtx;

    DiningPhilosophers() {
        n = 5;
        mtx = vector<std::mutex> (n);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int leftFork = philosopher%n;
        int rightFork = (philosopher + 1)%n;

        //for Even philosopher's first pick left then right and keep in that order
        if(philosopher%2==0){
            mtx[leftFork].lock();
            mtx[rightFork].lock();

            pickLeftFork();
            pickRightFork();
            eat();
            putLeftFork();
            putRightFork();

            mtx[leftFork].unlock();
            mtx[rightFork].unlock();
        }
        //for Odd philosopher's first pick right then left and keep in that order
        else {
            mtx[rightFork].lock();
            mtx[leftFork].lock();

            pickRightFork();
            pickLeftFork();
            eat();
            putRightFork();
            putLeftFork();

            mtx[rightFork].unlock();
            mtx[leftFork].unlock();
        }
    }
};