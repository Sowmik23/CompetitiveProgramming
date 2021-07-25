class Solution {
private:
    vector<int> original, changed;
    
public:
    Solution(vector<int>& nums) {
        this->original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        vector<int> changed(original);
        for(int i=0;i<changed.size();i++){
            int pos = rand()%(changed.size()-i);
            swap(changed[i], changed[pos+i]);
        }
        
        
        return changed;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
