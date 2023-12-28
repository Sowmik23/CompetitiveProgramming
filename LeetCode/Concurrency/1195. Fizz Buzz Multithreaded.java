// 1195. Fizz Buzz Multithreaded

//1. Approach-01: Using Semaphore
class FizzBuzz {
    private int n;

    //Approach-01: Using Semaphore
    Semaphore smFizz, smBuzz, smFB, smNum;
    private int i;

    public FizzBuzz(int n) {
        this.n = n;
        smFizz = new Semaphore(0);
        smBuzz = new Semaphore(0);
        smFB = new Semaphore(0);
        smNum = new Semaphore(1);
        i = 1;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        
        while(i<=n){
            smFizz.acquire();
            if(i<=n) printFizz.run();
            i++;
            updateSem(i);
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        
        while(i<=n){
            smBuzz.acquire();
            if(i<=n) printBuzz.run();
            i++;
            updateSem(i);
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        
        while(i<=n){
            smFB.acquire();
            if(i<=n) printFizzBuzz.run();
            i++;
            updateSem(i);
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        
        while(i<=n){
            smNum.acquire();
            if(i<=n) printNumber.accept(i);
            i++;
            updateSem(i);
        }
    }

    private void updateSem(int num){
        if(num<=n){
            if(num%15==0) smFB.release();
            else if(num%3==0) smFizz.release();
            else if(num%5==0) smBuzz.release();
            else smNum.release();
        }
        else {
            smFizz.release();
            smBuzz.release();
            smFB.release();
            smNum.release();
        }
    }
}

// 2. Using Synchronized 
class FizzBuzz {
    private int n;

    //Approach-02: Using Synchronized
    private int i;

    public FizzBuzz(int n) {
        this.n = n;
        this.i = 1;
    }

    // printFizz.run() outputs "fizz".
    synchronized public void fizz(Runnable printFizz) throws InterruptedException {
        
        while(i<=n){
             if(i%15!=0 && i%3==0){
                printFizz.run();
                i++;
                this.notifyAll();
            }
            else this.wait();
        }
    }

    // printBuzz.run() outputs "buzz".
    synchronized public void buzz(Runnable printBuzz) throws InterruptedException {
        
        while(i<=n){
            if(i%15!=0 && i%5==0){
                printBuzz.run();
                i++;
                this.notifyAll();
            }
            else this.wait();
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    synchronized public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        
        while(i<=n){
            if(i%15==0){
                printFizzBuzz.run();
                i++;
                this.notifyAll();
            }
            else this.wait();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    synchronized public void number(IntConsumer printNumber) throws InterruptedException {
        
        while(i<=n){
            if(i%15!=0 && i%5!=0 && i%3!=0){
                printNumber.accept(i);
                i++;
                this.notifyAll();
            }
            else this.wait();
        }
    }
}