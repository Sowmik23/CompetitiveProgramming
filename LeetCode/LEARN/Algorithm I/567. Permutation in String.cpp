class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        /*Approach-01: Memory inefficient
        
        if(s1.size()>s2.size()) return false;
        
        unordered_map<char, int> freq;
        unordered_map<char, int> freq2;
        
        for(char ch: s1){
            freq[ch]++;
        }
        
        int left = 0, right = 0;
        
        while(right<s2.size()){
            char c1 = s2[right];
            
            if(freq.find(c1)!=freq.end()) freq2[c1]++;
            cout<<right<<" "<<c1<<endl;
            
            if(right>=s1.size()-1){
                // cout<<"sowmik"<<endl;
                bool f = compareTwoHashMap(freq, freq2);
                if(f==true) return true;
                // cout<<s2[right-(s1.size()-1)]<<endl;
                
                if(freq2.find(s2[right-(s1.size()-1)])!=freq2.end()) freq2[s2[right-(s1.size()-1)]]--;
                // cout<<"sowmik1"<<endl;

            }
            
            right++;
        }
        
        return false;
    }
    
private:
    bool compareTwoHashMap(unordered_map<char, int> &freq1, unordered_map<char, int> &freq2){
        
        if(freq1.size()==freq2.size()){
            for(auto& i: freq1){
                // cout<<i.first<<" "<<i.second<<" "<<freq2[i.first]<<endl;
                
                if(freq2[i.first]!=i.second) return false;
            }
            return true;
        }
        return false;
        */
        
        
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        
        for(auto& i: s1){
            freq1[i-'a']++;
        }
        
        for(int i=0;i<s2.size();i++){
            freq2[s2[i]-'a']++;
            
            if(i+1>=s1.size()){
                if(freq1==freq2) return true;
                
                freq2[s2[i-(s1.size()-1)]-'a']--;
            }
        }
        
        return false;
    }
};
