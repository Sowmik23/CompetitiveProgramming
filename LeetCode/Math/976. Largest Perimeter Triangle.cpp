class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        sort(nums.begin(), nums.end(),  greater<int> ());

        //because of sorting it won't take O(n^3) to check if 3 value makes. triangle or not
        //so we just need to check if arr[i]<arr[j]+arr[k]

        for(int i=0;i<=nums.size()-3;i++){

            if(isTriangle(nums[i], nums[i+1], nums[i+2])){
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }

        return 0;
    }
private:
    bool isTriangle(int a, int b, int c){
        return (a+b>c and b+c>a and c+a>b);
    }
};
