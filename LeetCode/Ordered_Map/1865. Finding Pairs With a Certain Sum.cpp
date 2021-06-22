class FindSumPairs {
public:
    vector<int> num2;
    map<int, int> first;
    unordered_map<int, int> second;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->num2 = nums2;
        for(auto i: nums1){
            first[i]++;
        }
        for(auto i: num2){
            second[i]++;
        }
    }
    
    void add(int index, int val) {
        second[num2[index]]--;
        num2[index] += val;
        second[num2[index]]++;
    }
    
    int count(int tot) {
    
        int res = 0;
        for(auto it = first.begin();it!=first.end() and it->first<tot;it++){
            
            int val = tot - it->first;
            
            if(second.count(val)){
                res += (it->second * second[val]); ///nums1 er frequency * nums2 er frequency
            }
        }
        
        
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
