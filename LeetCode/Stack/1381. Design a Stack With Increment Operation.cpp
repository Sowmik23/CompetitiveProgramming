class CustomStack {
public:
    int i = 0;
    int n ;
    int arr[1001];
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(i<n){
            arr[i] = x;
            i++;
        }
    }
    
    int pop() {
        if(i>0){
            int x = arr[i-1];
            i--;
        
            return x;    
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if(k>i) k = i;
        for(int j=0;j<k;j++){
            arr[j]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
