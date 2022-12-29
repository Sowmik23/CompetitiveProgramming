class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size()>s.size()) return "";

        vector<int> freqT(60, 0);
        int remaining = t.size();

        for(auto& ch: t){
            freqT[ch-'A']++;
        }

        int left = 0, right = 0;
        int start = 0, len = INT_MAX, minStart = 0;
        int n = s.size();

        while(right<n){
            freqT[s[right]-'A']--;
            if(freqT[s[right]-'A']>=0) remaining--;
            right++;

            if(len==t.size()) break; //to improve performance
            while(remaining==0){
                if(right-left<len){
                    len = right-left;
                    minStart = left;
                }
                freqT[s[left]-'A']++;
                if(freqT[s[left]-'A']>0) remaining++;
                left++;
            }
        }

        if(len==INT_MAX) return "";
        return s.substr(minStart, len);
    }
};
