class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        //Approach: Binary Search
        //Time: O(nlog(m)) ...> n = array lengh, m = max pile size
        //Space: O(1)
        
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        while(low<high){
            int mid = low+(high-low)/2;
            
            int k = 0;
            for(auto& banana: piles){
                k+=(banana/mid) + (banana%mid==0 ? 0: 1);
            }
            //cout<<k<<endl;
            
            if(k<=h) high = mid;
            else low = mid+1;
        }
        
        return high;
    }
};
