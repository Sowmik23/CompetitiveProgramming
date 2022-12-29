class Solution {
public:
    int romanToInt(string s) {

        //Time: O(n)

        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;


        //LVIII

        int sum = mp[s.back()];
        for(int i=s.size()-2;i>=0;i--){
            if(mp[s[i]]<mp[s[i+1]]){
                sum-=mp[s[i]];
            }
            else sum+=mp[s[i]];
        }

        return sum;
    }
};
