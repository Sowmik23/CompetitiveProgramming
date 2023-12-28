class Solution {
public:
    int xorBeauty(vector<int>& nums) {


        unordered_map<int, int> mp0;
        unordered_map<int, int> mp1;

        for(int i=0;i<nums.size();i++){

            int x = nums[i];
            for(int j=0;j<32;j++){
                int b = (1 & (x >> j));
                if(b==0) mp0[j]++;
                else mp1[j]++;
            }
        }

        string str = "";
        for(int i=0;i<32;i++){
            if(mp1[i]%2==1) str="1"+str;
            else str="0"+str;
        }
        //cout<<str<<endl;

        int res = stoi(str, nullptr, 2);;


        return res;
    }
};
