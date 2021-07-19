class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
    
    int minSetSize(vector<int>& arr) {
        
        map<int, int> mp;
        
        for(auto i: arr){
            mp[i]++;
        }
        
        
        // for(auto i: mp){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        ///sort the map frequency wise
        vector<pair<int, int>> v;
        for(auto i: mp){
            v.push_back(i);
        }
        
        sort(v.begin(), v.end(), comp);
        
        // for(auto i: v){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        int n = arr.size();
        int cnt=0;
        int res = 0;
        for(auto i: v){
            cnt+=i.second;
            res++;
            
           // arr.erase(remove(arr.begin(), arr.end(), i.first), arr.end());
            
            if(cnt>=n/2){
                break;
            }
        }
        
        // for(auto i: arr){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        
        
        return res;
    }
};
