///Time: O(PlogP)
///Memory: O(1) except output vector<vector>>res

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> res;
        
        sort(products.begin(), products.end());
        int left = 0, right=products.size()-1;
            
        for(int i=0;i<searchWord.size();i++){
            
            char c = searchWord[i];
            
            vector<string> tmp;
            
            while(left<=right and (products[left].size()==i or products[left][i]<c)) left++;
            while(left<=right and (products[right].size()==i or products[right][i]>c)) right--;
            
            for(int j=0;j<3 and left+j<=right;j++){
                tmp.push_back(products[left+j]);
                // cout<<products[left+j]<<endl;
            }
            // cout<<"\n\n";
            
            res.push_back(tmp);
        }
        
        return res;
    }
};
