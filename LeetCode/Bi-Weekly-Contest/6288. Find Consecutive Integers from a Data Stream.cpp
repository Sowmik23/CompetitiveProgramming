class DataStream {
public:
    int val, t;
    int i = 0;
    unordered_map<int, int> mp;
    const int n = 1e5+9;
    vector<int> nums;

    DataStream(int value, int k) {
        val = value;
        t = k;
        nums = vector<int> (n, 0);
    }

    bool consec(int num) {
        //cout<<i<<" "<<t<<" " <<num<<endl;
        if(i>=t){
           // cout<<nums[i-t]<<"  "<<mp[nums[i-t]]<<endl;
            if(mp.find(nums[i-t])!=mp.end()){
                if(mp[nums[i-t]]>0) mp[nums[i-t]]--;
                else mp.erase(nums[i-t]);
            }
        }
        mp[num]++;
        nums[i] = num;

        bool res = true;
        if(i+1<t) res = false;
        i++;
        if(res==false) return res;
        return mp[num]==t and num==val;
    }
};
// 0, 1, 2, 3

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
