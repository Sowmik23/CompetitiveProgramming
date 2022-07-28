class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
     
        //first of all sort the array in decreasing order of height
        sort(people.begin(), people.end(), [](auto &a, auto &b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]>b[0];
        });
        
        
        vector<vector<int>> res;
        
        
        for(auto i: people){
            //cout<<i[0]<<" "<<i[1]<<endl;
            res.insert(res.begin()+i[1], i);
        }
        
        return res;
    }
};
