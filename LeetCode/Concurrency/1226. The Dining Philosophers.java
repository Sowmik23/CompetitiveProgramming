// 1226. The Dining Philosophers

class DiningPhilosophers {

    private int n;
    private ReentrantLock[] rntLck;
    private Semaphore eating;

    public DiningPhilosophers() {
        n = 5;
        eating = new Semaphore (n-1);
        rntLck = new ReentrantLock[n];
        for(int i = 0; i < n; i++) {
            rntLck[i] = new ReentrantLock();
        }   
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {

        int leftFork = philosopher % n;
        int rightFork = (philosopher + 1) % n;
        
        eating.acquire();

        rntLck[leftFork].lock();
        rntLck[rightFork].lock();

        pickLeftFork.run();
        pickRightFork.run();
        eat.run();
        putLeftFork.run();
        putRightFork.run();

        rntLck[leftFork].unlock();
        rntLck[rightFork].unlock();
       
        eating.release();
    }
}