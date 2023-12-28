class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {

        if(k == 0){
            if(nums1==nums2) return 0L;
            return -1L;
        }

        long long x=0, y=0;
        for(int i=0;i<nums1.size();i++){
            long long d = abs(nums1[i]-nums2[i]);
            if(d%k!=0) return -1;

            if(nums1[i]<=nums2[i]){
                x += (nums2[i]-nums1[i])/k;
            }
            else {
                y += (nums1[i]-nums2[i])/k;
            }
        }
        //cout<<x<<" "<<y<<endl;
        if(x!=y) return -1;
        return x;
    }
};
