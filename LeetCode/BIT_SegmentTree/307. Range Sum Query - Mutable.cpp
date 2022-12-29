class NumArray {
public:
    //solve it using Fenwick Tree/Binary Indexed Tree
    vector<int> bit;
    vector<int> tmp;
    int n ;

    NumArray(vector<int>& nums) {
        tmp = nums;
        bit = vector<int> (nums.size()+1, 0);
        n = nums.size();

        for(int i=1;i<=nums.size();i++){
            bit[i] = 0;
        }
        for(int i=0;i<nums.size();i++){
            updateBit(i, nums[i]);
        }
    }

    void updateBit(int index, int val) {
        int idx = index+1;
        while(idx<=n){
            bit[idx]+=val;
            idx += idx&(-idx);
        }
    }

    void update(int index, int val) {
        updateBit(index, val-tmp[index]);
        tmp[index] = val;
    }

    int getSum(int idx){
        idx = idx+1;
        int sum = 0;
        while(idx>0){
            sum+=bit[idx];
            idx -= idx&(-idx);
        }

        return sum;
    }
    int sumRange(int left, int right) {
        return getSum(right)-getSum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
