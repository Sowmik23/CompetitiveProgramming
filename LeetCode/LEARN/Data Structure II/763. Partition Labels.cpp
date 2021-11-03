class Solution {
public:
    vector<int> partitionLabels(string s) {
     
        unordered_map<char, int> mp;
        
        for(int i=0;i<s.size();i++){
            mp[s[i]] = i;
        }
        
        vector<int> res;
        int last_point = 0;
        int prev_point = -1;
        
        int i = 0;
        while(i<s.size()){
            
            int last = mp[s[i]];
            last_point = last;
            
            for(int j =i;j<last_point;j++){
                int others_last = mp[s[j]];
                last_point = max(others_last, last_point);
            }
            cout<<last_point<<endl;
            int size = last_point-prev_point;
            res.push_back(size);
            prev_point = last_point;
            
            i = last_point;
            i++;
        }
        
        return res;
    }
};
