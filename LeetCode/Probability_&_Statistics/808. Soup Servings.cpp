// 808. Soup Servings
class Solution {
public:
    double soupServings(int n) {

        //Dynamic programming with probability
        //Time: O(1)
        //Space: O(1)

        int m = ceil(n/25.0);
        
        
        /**/
        // for(int i=1;i<=m;i++){
        //     if(recursive(i, i)>1- 1e-5) return 1.0;
        // }   
        // return recursive(m, m);
        /**/

        //recursion with memoization
        for(int i=1;i<=m;i++){
            if(recursionWithMemo(i, i)>1- 1e-5) return 1;
        }   
        return recursionWithMemo(m, m);
    }
private:
    unordered_map<int, unordered_map<int, double>> mp;
    
    double recursive(int i, int j){
        if(i<=0 and j<=0) return 0.5;
        if(i<=0) return 1;
        if(j<=0) return 0;

        return (recursive(i-4, j)+recursive(i-3, j-1)+recursive(i-2, j-2)+recursive(i-1, j-3))/4.0;
    }

    double recursionWithMemo(int i, int j){
        if(i<=0 and j<=0) return 0.5;
        if(i<=0) return 1;
        if(j<=0) return 0;
        if(mp[i].count(j)) return mp[i][j];

        return mp[i][j] = (recursionWithMemo(i-4, j)+recursionWithMemo(i-3, j-1)+recursionWithMemo(i-2, j-2)+recursionWithMemo(i-1, j-3))/4;
    }

};