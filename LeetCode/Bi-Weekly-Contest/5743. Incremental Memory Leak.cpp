class Solution {
  
public:
    vector<int> memLeak(int memory1, int memory2) {
        
        vector<int> res(3);
        
        int i=1;
        for(int j=0;;j++){
            // cout<<j<<" "<<memory1<<" "<<memory2<<endl;;
            if(memory1>=memory2){
                if(i<=memory1){
                    memory1-=i;
                }
                else break;
            }
            else {
                if(i<=memory2){
                    memory2-=i;
                }
                else break;
            }
            i++;
        }
        
        
        res[0] = i;
        res[1] = memory1;
        res[2] = memory2;
        
        return res;
    }
};
