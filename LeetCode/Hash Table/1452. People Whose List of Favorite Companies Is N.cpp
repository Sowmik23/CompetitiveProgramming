// 1452. People Whose List of Favorite Companies Is Not a Subset of Another List
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        
        int n = favoriteCompanies.size();
        vector<int> res;

        for(int i=0;i<n;i++){
            sort(favoriteCompanies[i].begin(), favoriteCompanies[i].end());
        }
        
        for(int i=0;i<n;i++){
            vector<string> tmpList = favoriteCompanies[i];

            bool flag = false;   
            for(int j=0;j<n and !flag;j++){
                if(i==j) continue;
                if(favoriteCompanies[i].size()>favoriteCompanies[j].size()) continue;
                //True, if every element of 2nd container lies in 1st container
                flag = includes(favoriteCompanies[j].begin(), favoriteCompanies[j].end(), 
                                favoriteCompanies[i].begin(), favoriteCompanies[i].end());
            }
            if(!flag) res.push_back(i);
        }
        return res;
    }
};