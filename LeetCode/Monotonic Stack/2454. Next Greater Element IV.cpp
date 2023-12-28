class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {

        int n = nums.size();
        stack<int> notFound, firstGreater, tmp;
        vector<int> res(n, -1);
        //notFound.push(nums[n-1]);

        for(int i=0;i<n;i++){

            while(!firstGreater.empty() and nums[firstGreater.top()]<nums[i]){
                res[firstGreater.top()] = nums[i];
                firstGreater.pop();
            }
            while(!notFound.empty() and nums[notFound.top()]<nums[i]){
                tmp.push(notFound.top());
                notFound.pop();
            }
            while(!tmp.empty()){
                firstGreater.push(tmp.top());
                tmp.pop();
            }
            notFound.push(i);
        }
        return res;
    }
};
