class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
      /*  //brute force
        int x, n = nums.size();
        k = k%n;
        for(int i=0;i<k;i++){
            int last = nums[n-1];
            
            for(int j=0;j<n;j++){
                int tmp = nums[j];
                nums[j] = last;
                last = tmp;
            }
        }*/
        
        //approach 2
       /* int n = nums.size();
        vector<int> res(n);
        
        for(int i=0;i<n;i++){
            res[(i+k)%n] = nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i] = res[i];
        }*/
        
        //approach 3: using vector reverse
        
       /* if(nums.size()==0 or nums.size()==1) return ;
        //1 2 3 4 5 6 7 and k = 3
        //1st: 7 6 5 4 3 2 1
        //2nd: 5 6 7 4 3 2 1
        //finally: 5 6 7 1 2 3 4
        
        k = k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    } */
    
    //using stl rotate function
    //std:: rotate(nums.begin(), nums.begin()+nums.size()-(k%nums.size()), nums.end());
    
   /* //another awesome approache: O(n) + O(1)
        k = k%nums.size();
        for(int i=1;i<=k;i++){
            int tmp = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), tmp);
        } */
        
        //using cyclic replacements: maybe best O(n) + O(1) approach
        
        k = k%nums.size();
        int cnt = 0;
        
        for(int i=0;cnt<nums.size();i++){
            int current = i;
            int prev = nums[i];
            while(true){
                int next = (current+k)%nums.size();
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;
                current = next;
                cnt++;
                if(i==current) break;
            }
        }
    }
        
};
