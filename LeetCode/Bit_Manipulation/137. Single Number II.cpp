class Solution {
public:
    int singleNumber(vector<int>& nums) {
     
        //approach: using bit
        //Time: O(C*n), c = size of int= 32, n = nums.size()
        //Space: O(1)
        
        string res="";
        int signBit;
        int mx = INT_MIN;
        int maxBit;
        
        for(int i=31;i>=0;i--){
            int cnt=0;
            for(int j=0;j<nums.size();j++){
                // if(i==31) {
                //     if(nums[j]==0) maxBit = 1;
                //     else maxBit = floor(log2(abs(nums[j])))+1;
                //     mx = max(mx, maxBit);
                // }
                if((1&(nums[j])>>i)==1) cnt++;
            }
           
            if(cnt%3==1) res+="1";
            else res+="0";                  

        }
        cout<<res<<endl;
        if(res[0]=='1') signBit = 1;
        else signBit = 0;
        
        if(signBit==1){
            //find 1's complement
            for(int i=0;i<res.size();i++){
                if(res[i]=='0') res[i]='1';
                else res[i]='0';
            }
            
        }
//         res = res.substr(res.size()-mx, res.size());
//         cout<<res<<endl;
        
        int r = stoi(res, 0, 2);
        cout<<r<<endl;
        
        //if negative then 2's complement
        if(signBit==1) {
            if(r==INT_MAX) return -r-1;
            return -(r+1);
        }
        return r;
    }



//Explanation:
/*
1. ones ^= (number & ^twos): This line updates the ones variable by XORing it with the bitwise AND of the current number (number)
 and the complement of twos (^twos). The complement of twos ensures that if a bit has already appeared twice, it is excluded from ones. 
 This operation effectively keeps track of the bits that have appeared once but not twice.

2. twos ^= (number & ^ones): This line updates the twos variable by XORing it with the bitwise AND of the current number (number) 
and the complement of ones (^ones). The complement of ones ensures that if a bit has already appeared once, it is excluded from twos. 
This operation effectively keeps track of the bits that have appeared twice but not three times.

*/
        int ones = 0;
        int twos = 0;

        for (const int num : nums) {
            ones ^= (num & ~twos);
            twos ^= (num & ~ones);
        }

        return ones;
        
    }
};
