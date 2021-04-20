class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
     
        
        int mx = candies[0];
        for(int i=1;i<candies.size();i++){
            if(candies[i]> mx){
                mx = candies[i];
            }
        }
        
        vector<bool> ans;
        
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies >= mx){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        
        return ans;
    }
};
