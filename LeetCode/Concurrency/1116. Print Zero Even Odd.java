// 1116. Print Zero Even Odd

class ZeroEvenOdd {
    private int n;

    //using Semaphore
    Semaphore smZero, smOdd, smEven;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
        smZero = new Semaphore(1);
        smOdd = new Semaphore(0);
        smEven = new Semaphore(0);
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i<=n;i++){
            smZero.acquire();
            printNumber.accept(0);
            if(i%2==0) smEven.release();
            else smOdd.release();
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for(int i=2;i<=n;i+=2){
            smEven.acquire();
            printNumber.accept(i);
            smZero.release();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i<=n;i+=2){
            smOdd.acquire();
            printNumber.accept(i);
            smZero.release();
        }
    }
}