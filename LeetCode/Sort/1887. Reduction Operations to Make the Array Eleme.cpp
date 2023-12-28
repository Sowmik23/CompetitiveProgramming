// 1887. Reduction Operations to Make the Array Elements Equal

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        /*
        int n = nums.size();
        //sort(nums.begin(), nums.end());
        set<int> st;
        set<int>::reverse_iterator it;
        unordered_map<int, int> mp;

        for(auto&num: nums){
            st.insert(num);
            mp[num]++;
        }

        int res = 0;

        for(it=st.rbegin();it!=prev(st.rend());it++){
            cout<<*it<<endl;
            int cnt = mp[*it] + res;
            res += cnt;
        }
       
        return res;
        */

        sort(nums.begin(), nums.end());
        int cnt = 0;
        int _cnt = 0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]) _cnt++;
            cnt+=_cnt;
        }
        return cnt;
    }
};