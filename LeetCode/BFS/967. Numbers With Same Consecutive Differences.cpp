class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {

        //can be solved with bfs/dfs
        //Time: if(k>=5) then O(n);
        //else if(k<4) then O(2^n)

        vector<int> init = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        //build n digit
        for(int i=1;i<n;i++){
            //build 1 digit
            vector<int> res;
            for(int x: init){
                int y = x%10;
                if(y+k<10) res.push_back(x*10+y+k);
                if(k>0 and y-k>=0) res.push_back(x*10+y-k);
            }
            init = res;
        }
        return init;


    }
};
