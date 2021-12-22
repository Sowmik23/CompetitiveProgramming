class Solution {
public:
    int maxArea(vector<int>& height) {
        
        //two pointer 
        
        int i=0, j=height.size()-1;
        
        int mx = 0;
        
        while(i<j){
            
            int area = (j-i)*min(height[i], height[j]);
            
            mx = max(mx, area);
            if(height[i]<height[j]) i++;
            else j--;
        }
        
        return mx;
    }
};
