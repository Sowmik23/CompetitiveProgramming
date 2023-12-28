class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int res = 0;

        //abaaaaaaccccccde

        int i = 0;
        while(i<colors.size()){
            int sum = 0;
            int mx = INT_MIN;
            if(i+1<colors.size() and colors[i]==colors[i+1]){
                while(i+1<colors.size() and colors[i]==colors[i+1]){
                    sum+=neededTime[i];
                    mx = max(mx, neededTime[i]);
                    i++;
                }
                sum+=neededTime[i];
                mx = max(mx, neededTime[i]);
                //cout<<sum<<" "<<mx<<endl;
                res+=(sum-mx);
            }
            else i++;
        }

        return res;
    }
};
