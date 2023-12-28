// 2781. Length of the Longest Valid Substring
class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {

        //Time: O(n*10);

        int n = word.size();
        unordered_set<string> st(forbidden.begin(), forbidden.end());
        vector<int> index(n, -1);

        for(int i=0;i<n;i++){
            string str = "";
            for(int j=i;j<min(n, i+10);j++){ //make and check substr atmost 10 length
                str+=word[j];
                if(st.count(str)){
                    index[j] = max(index[j], i);
                }
            }
        }

        int res = 0, cnt = 0;
        for(int i=0;i<n;i++){
            if(index[i]!=-1) cnt = max(cnt, index[i]+1);
            res = max(res, i-cnt+1);
        }
        return res;
    }
};