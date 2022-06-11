class Solution {
public:
    bool digitCount(string num) {
        
        vector<int> memo(10, 0);
        for(auto& i: num){
            memo[i-'0']++;
        }
        
        for(int i=0;i<num.size();i++){
            //cout<<memo[i]<<" ";
           if(memo[i]!=num[i]-'0') return false;
        }
        
        return true;
    }
};
