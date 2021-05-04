class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
     
        vector<int> ans;
      
        int sum =0;
        if(k>0){
            for(int i=0;i<k;i++){
                sum+=code[i+1];
            }
            for(int i=0;i<code.size();i++){
                ans.push_back(sum);
                sum-=code[(i+1)%code.size()];
                sum+=code[(i+k+1)%code.size()];
            }
        }
        else if(k<0){
            k = abs(k);
            for(int i=code.size()-1;i>=code.size()-k;i--){
                sum+=code[i];
            }
            for(int i=0;i<code.size();i++){
                ans.push_back(sum);
                sum-=code[(code.size()-k+i)%code.size()];
                sum+=code[(code.size()+i)%code.size()];
            }
        }
         if(k==0){
            for(int i=0;i<code.size();i++){
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};
