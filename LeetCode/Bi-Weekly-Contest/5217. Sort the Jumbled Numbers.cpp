class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        //Verdict: TLE
        
        //vector<int> res;
        unordered_map<int, int> mp, mp2; 
        
        for(int i=0;i<mapping.size();i++){
            mp[i] = mapping[i];
        }
        
        
        for(int i=0;i<nums.size();i++){
            
            // int x = nums[i];
            //int num = 0;
            string str="";
            
            string s = to_string(nums[i]);
            

            if(mp2.find(stoi(s))!=mp2.end()) continue;
            
            for(int j=0;j<s.size();j++){
                int id = s[j]-'0';
                //int digit = mp[id];
                //num = num*10 + digit;

                str+=to_string(mp[id]);
            }
            int num = stoi(str);
            //cout<<num<<endl;
        
                       
            mp2[nums[i]] = num;
        }
        
        //now sort the result array
        //insertion sort
        // for(int i=1;i<nums.size();i++){
        //     int val = mp2[nums[i]];
        //     int v = nums[i];
        //     int minIdx = i-1;
        //     while(minIdx>=0 and mp2[nums[minIdx]]>val){
        //         nums[minIdx+1] = nums[minIdx];
        //         minIdx--;
        //     }
        //     nums[minIdx+1] = v;
        // }
        
        //stable selection sort
        // for(int i=0;i<nums.size();i++){
        //     int minIdx = i;
        //     for(int j=i+1;j<nums.size();j++){
        //         if(mp2[nums[j]]<mp2[nums[minIdx]]){
        //             minIdx = j;
        //         }
        //     }
        //     int tmp = nums[minIdx];
        //     while(minIdx>i){
        //         nums[minIdx] = nums[minIdx-1];
        //         minIdx--;
        //     }
        //     nums[minIdx] = tmp;
        // }
        
        sort(nums.begin(), nums.end(), [](int &a, int &b){return mp2[a]<mp2[b]});
        
        
        return nums;
    }    
    
};
