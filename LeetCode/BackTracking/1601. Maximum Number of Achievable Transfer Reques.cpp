// 1601. Maximum Number of Achievable Transfer Requests
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        //TODO
        //Backtracking
        /*
        vector<int> indegree(n, 0);
        maxRequest(requests, indegree, n, 0, 0);
        
        return res;
        */
        // Bit manipulation
        int answer = 0; 
        
        for (int mask = 0; mask < (1 << requests.size()); mask++) {
            vector<int> indegree(n, 0);
            int pos = requests.size() - 1;
            // Number of set bits representing the requests we will consider.
            int bitCount = __builtin_popcount(mask);
            
            // If the request count we're going to consider is less than the maximum request 
            // We have considered without violating the constraints; then we can return it cannot be the answer.
            if (bitCount <= answer) {
                continue;
            }
            
            // For all the 1's in the number, update the array indegree for the building it involves.
            for (int curr = mask; curr > 0; curr >>= 1, pos--) {
                if (curr & 1) {
                    indegree[requests[pos][0]]--;
                    indegree[requests[pos][1]]++;
                }
            }
            
            int flag = 1;
            // Check if it doesn;t violates the constraints
            for (int i = 0; i < n; i++) {
                if (indegree[i]) {
                    flag = 0;
                    break;
                }
            }
            
            if (flag)  {
                answer = bitCount;
            }
        }
        
        return answer;
    }
private:
    int res = 0;
    void maxRequest(vector<vector<int>>& requests, vector<int>& indegree, int n, int index, int count){
        if (index == requests.size()) {
            // Check if all buildings have an in-degree of 0.
            for (int i = 0; i < n; i++) {
                if (indegree[i]) {
                    return;
                }
            }
            
            res = max(res, count);
            return;
        }
        
        // Consider this request, increment and decrement for the buildings involved.
        indegree[requests[index][0]]--;
        indegree[requests[index][1]]++;
        // Move on to the next request and also increment the count of requests.
        maxRequest(requests, indegree, n, index + 1, count + 1);
        // Backtrack to the previous values to move back to the original state before the second recursion.
        indegree[requests[index][0]]++;
        indegree[requests[index][1]]--;
        
        // Ignore this request and move on to the next request without incrementing the count.
        maxRequest(requests, indegree, n, index + 1, count);
    }
};