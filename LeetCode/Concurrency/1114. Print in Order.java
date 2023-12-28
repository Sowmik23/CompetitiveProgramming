// 1114. Print in Order
class Foo {

    /*
    // Source: https://leetcode.com/problems/print-in-order/solutions/332890/java-basic-semaphore-solution-8ms-36mb/?orderBy=most_votes
// "Semaphore is a bowl of marbles" - Professor Stark

// Semaphore is a bowl of marbles (or locks in this case). If you need a marble, and 
// there are none, you wait. You wait until there is one marble and then you take it. 
// If you release(), you will add one marble to the bowl (from thin air). 
// If you release(100), you will add 100 marbles to the bowl. run2.release(); will 
// add one "run2" marble to the "run2 bowl".
// The thread calling third() will wait until the end of second() when it 
// releases a 'run3' marble. The second() will wait until the end of **first() **when it 
// releases a 'run2' marble. Since first() never acquires anything, it will never wait. 
// There is a forced wait ordering.
// With semaphores, you can start out with 1 marble or 0 marbles or 100 marbles.
//  A thread can take marbles (up until it's empty) or put many marbles at a time.

TODO: solve this using:

- volatile keyword.
- locks
- conditions (they are like sub-locks)
- atomic variables
- java's concurrent data structures

*/

    private Semaphore semaphore;
    public Foo() {
        semaphore = new Semaphore(0);
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        semaphore.release(1);
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while(!semaphore.tryAcquire(1));

        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        semaphore.release(2);
    }

    public void third(Runnable printThird) throws InterruptedException {
        while(!semaphore.tryAcquire(2));

        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
        semaphore.release();
    }
}