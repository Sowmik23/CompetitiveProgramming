// 2551. Put Marbles in Bags
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        //Time: nlogn
        // Sorting + Greedy
        
        int n = weights.size();
        vector<int> pairWeights(n-1, 0);
        for(int i=0;i<n-1;i++){
            pairWeights[i] = weights[i] + weights[i+1];
        }

        sort(pairWeights.begin(), pairWeights.end());

        long long res = 0;
        for(int i=0;i<k-1;i++){
            res += pairWeights[n-2-i] - pairWeights[i];
        }
        return res;
    }
};