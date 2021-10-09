class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        
        //Approach-01: using hash table
        /*
        unordered_map<char, int> freqOfMagazine;
        
        for(auto& ch: magazine){
            freqOfMagazine[ch]++;
        }
        
        for(auto& ch: ransomNote){
            if(freqOfMagazine[ch]<1){
                return false;
            }
            freqOfMagazine[ch]--;
        }
        
        return true;
        */
        //Approach-02: using frequency array
        
        vector<int> freq(26, 0);
        for(auto& ch: magazine){
            freq[ch-'a']++;
        }
        
        for(auto& ch: ransomNote){
            if(freq[ch-'a']<1) return false;
            freq[ch-'a']--;
        }
        
        return true;
    }
};
