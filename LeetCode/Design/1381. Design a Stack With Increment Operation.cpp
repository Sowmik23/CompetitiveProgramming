// 1381. Design a Stack With Increment Operation
class CustomStack {
public:
    int n;
    vector<int> nums;
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(nums.size()==n) return;
        nums.push_back(x);
    }
    
    int pop() {
        if(nums.size()) {
            int x = nums[nums.size()-1];
            nums.pop_back();
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int m = nums.size();
        for(int i=0;i<min(k, m);i++){
            nums[i]+=val;
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