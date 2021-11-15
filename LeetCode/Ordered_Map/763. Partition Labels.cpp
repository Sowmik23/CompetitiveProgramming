class Solution {
public:
    vector<int> partitionLabels(string s) {
     
        //Time: O(n)
        //Space: O(n)
        
//         unordered_map<char, int> lastPosition;
//         vector<int> res;
        
//         for(int i=0;i<s.size();i++){
//             lastPosition[s[i]] = i;
//         }
        
//         int i = 0;
        
//         while(i<s.size()){
            
//             int j = lastPosition[s[i]];
            
//             for(int k=i;k<j;k++){
//                 j = max(j, lastPosition[s[k]]);
//             }
//             res.push_back(j-i+1);
//             i = j+1;
//         }
        
//         return res;
        
        
        //Time: O(n)
        //Space: O(1)
        
        int arr[26] = {0};
        vector<int> res;
        
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a'] = i;
        }
        
        
        int i=0;
        while(i<s.size()){
            int lastPos = arr[s[i]-'a'];
            for(int j=i;j<lastPos;j++){
                lastPos = max(lastPos, arr[s[j]-'a']);
            }
            res.push_back(lastPos-i+1);
            i = lastPos+1;
        }
        
        return res;
    }
};
