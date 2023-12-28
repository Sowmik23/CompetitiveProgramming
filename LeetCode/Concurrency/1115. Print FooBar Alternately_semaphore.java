// 1115. Print FooBar Alternately

// 1. Using Semaphore
class FooBar {
    private int n;

    // Method-01: Using Semaphore 
    Semaphore foo = new Semaphore(1); //it has one permit
    Semaphore bar = new Semaphore(0); //it has no permit

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {

            foo.acquire(); //initially it has one permission so doesn't have to wait
            
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();

            bar.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            bar.acquire(); //initiall it has no permit so have to wait

            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();

            foo.release();
        }
    }
}


// 2. Using synchronized
class FooBar {
    private int n;

    // Method-01: Using Synchronized(monitor exit happens before monitor enter)

    private int flag = 0; //0 for foo and 1 for bar

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {

            synchronized(this){
                while(flag==1) this.wait();

                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();

                flag = 1;
                this.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            synchronized(this){
                while(flag==0) this.wait();

                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();

                flag = 0;
                this.notifyAll();
            }
        }
    }
}


// 3. Using Volatile Integer 
class FooBar {
    private int n;

    // Method-03: Using Voatile(volatile write happens-before volatile read)

    private volatile int flag = 0;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            while(true){
                if(flag==0){

                    // printFoo.run() outputs "foo". Do not change or remove this line.
                    printFoo.run();

                    flag = 1;
                    break;
                }
                Thread.sleep(1);
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            while(true){
                if(flag==1){

                    // printBar.run() outputs "bar". Do not change or remove this line.
                    printBar.run();
                    
                    flag = 0;
                    break;
                }
                Thread.sleep(1);
            }
        }
    }
}


// 4. Using Atomic Integer 
class FooBar {
    private int n;

    //Method-04: Atomic Integer

    private AtomicInteger flag = new AtomicInteger(0);//initial 0 -> foo , 1 -> bar

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while(!flag.compareAndSet(0, 1)) Thread.sleep(1);

            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            while(!flag.compareAndSet(1, 0)) Thread.sleep(1);

            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
        }
    }
}

