class Solution {
public:
    int captureForts(vector<int>& forts) {

        int res = 0;
        int cnt = 0;
        int flag = 0;

        for(int i=0;i<forts.size();i++){

            if(forts[i]==0 and flag){
                cnt++;
                continue;
            }
            else if(forts[i]==-1 or forts[i]==1){

                if((forts[i]==-1 and flag==1) or (forts[i]==1 and flag==-1)) res = max(res, cnt);
                if(forts[i]==1) flag = 1;
                else if(forts[i]==-1) flag = -1;
                cnt = 0;
            }
        }
        return res;
    }
};
