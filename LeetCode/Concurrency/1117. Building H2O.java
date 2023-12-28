// 1117. Building H2O
class H2O {

    //Approach-01: Using Semaphore
    Semaphore sm1, sm2;

    public H2O() {
        sm1 = new Semaphore(2, true);
        sm2 = new Semaphore(0, true);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		
        sm1.acquire();

        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        
        sm2.release();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        
        sm2.acquire(2);

        // releaseOxygen.run() outputs "O". Do not change or remove this line.
		releaseOxygen.run();

        sm1.release(2);
    }
}

// 2. Using Synchronized

class H2O {

    //Approach-02: Using Synchronized
    private int h, o;

    public H2O() {
        h = 2;
        o = 0;
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		
        synchronized(this){
            while(h<1) this.wait();

            // releaseHydrogen.run() outputs "H". Do not change or remove this line.
            releaseHydrogen.run();

            h--;
            if(h<1) o = 1;
            this.notifyAll();
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        
        synchronized(this){
            while(o==0) this.wait();

             // releaseOxygen.run() outputs "O". Do not change or remove this line.
		    releaseOxygen.run();

            o--;
            h = 2;
            this.notifyAll();
        }
    }
}