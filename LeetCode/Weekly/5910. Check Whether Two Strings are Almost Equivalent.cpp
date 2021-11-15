class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        
        int arr1[26] = {0};
        for(int i=0;i<word1.size();i++){
            arr1[word1[i]-'a']++;
        }
        
        int arr2[26] = {0};
        for(int i=0;i<word2.size();i++){
            arr2[word2[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(abs(arr1[i]-arr2[i])>3) return false;
        }
        
        return true;
    }
};
