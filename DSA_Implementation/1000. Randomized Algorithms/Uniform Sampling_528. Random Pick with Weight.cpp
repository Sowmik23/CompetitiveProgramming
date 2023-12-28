// 528. Random Pick with Weight


/*
Algorithm Explanation:
say we have the numbers 1, 5, 2 easiest solution is to construct the following array
arr[] = {0,1,1,1,1,1,2,2}
then generate a random number between 0 and 7 and return the arr[rnd]. This is 
solution is not really good though due to the space requirements it has (imagine a number beeing 2billion).

The solution here is similar but instead we construct the following array (accumulated sum)
{1, 6, 8} generate a number between 1-8 and say all numbers generated up to 1 is index 0. all 
numbers generated greater than 1 and up to 6 are index 1 and all numbers greater than 6 and up to 8 are index 2. 
After we generate a random number to find which index to return we use binary search.
*/



class Solution {
public:
    vector<int> preSum;

    Solution(vector<int>& w) {
        preSum.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            preSum.push_back(preSum[i-1]+w[i]);
        }
    }
    
    int pickIndex() {
        
        int x =rand()%preSum[preSum.size()-1];
        int res = upper_bound(preSum.begin(), preSum.end(), x)-preSum.begin();
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */