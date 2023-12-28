// 792. Number of Matching Subsequences
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        

        //HashTable + Binary Search: Nice Approach!
        //Time: words.size()*word.size()*log(words[i].size())

        int cnt = 0;
        int n = s.size();
        unordered_map<char, vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }

        for(auto word: words){
            int index = -1;
            bool isExists = true;
            for(int i=0;i<word.size();i++){ //finding upper bound of prev index
                char ch = word[i];
                if(mp.find(ch)==mp.end()){
                    isExists = false;
                    break;
                }
                if(upper_bound(mp[ch].begin(), mp[ch].end(), index)==mp[ch].end()){
                    isExists = false;
                    break;
                }
                int x = upper_bound(mp[ch].begin(), mp[ch].end(), index) - mp[ch].begin();
                index = mp[ch][x];
            }
            if(isExists) cnt++;
        }
        return cnt;


        //This is for number of matching substring that includes in words list
        //simillar problem
        /*
        int n = s.size();
        unordered_set<string> st(words.begin(), words.end());
        int cnt = 0;

        for(int i=0;i<n;i++){
            string str = "";
            for(int j=i;j<min(i+50, n);j++){
                str+=s[j];
                if(st.count(str)){
                    cnt++;
                    st.erase(str);
                }
            }
        }
        return cnt;
        */
    }
};