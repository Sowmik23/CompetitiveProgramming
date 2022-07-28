class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> m;
        int arraySize = nums.size(), i=0;
        if(arraySize == 0) return 0;
        
        for(auto& num:nums) m[num] = false;
        int maxLen = 1;
        
        while(i<arraySize){
            int ele = nums[i];
			
			//An element once visited, won't be visited again, therefore its time complexity is O(n).
            if(m[ele] == false){
			
			//Find increasing sequence
                int inc = ele+1, curLen = 0;
			
                while(m.find(inc) != m.end()){
                    m[inc] = true;
                    curLen++;
                    inc++;
                }

			//Find Decreasing sequence
                int dec = ele-1;
                while(m.find(dec) != m.end()){
                    m[dec] = true;
                    curLen++;
                    dec--;
                }
				
				//curLen+1, plus one for current element.
                maxLen = max(curLen+1, maxLen);
            }
            i++;
        }
        
        return maxLen;
    }
};
