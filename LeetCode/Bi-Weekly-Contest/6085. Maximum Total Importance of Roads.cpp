class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, vector<int> > mp;
        
        for(int i=0;i<roads.size();i++){
            mp[roads[i][0]].push_back(roads[i][1]);
            mp[roads[i][1]].push_back(roads[i][0]);           
        }
        
        vector<pair<int, int>> num;
        for(auto& i: mp){
            num.push_back({i.second.size(), i.first});
        }

        sort(num.begin(), num.end(), greater<pair<int, int>>() );
        
        // for(auto& i: num) cout<<i.first<<" "<<i.second<<endl;
        // cout<<"kldjf"<<endl;
        
        unordered_map<int, int> mp2;
        
        for(auto& i: num){
            mp2[i.second] = n;
            n--;
        }
        
       // for(auto& i: mp2) cout<<i.first<<" "<<i.second<<endl;
        
        
        
        long long sum = 0;
        
        for(auto& i: mp){
            int x= i.first;
           // cout<<"x: "<<x;
            for(auto& j: i.second){
              //  cout<<" "<<j<<" ";
                if(j<x){
                    sum+=mp2[x];
                    sum+=mp2[j];
                }
            }
          //  cout<<endl;
        }
        
        
        return sum;
    }
};
