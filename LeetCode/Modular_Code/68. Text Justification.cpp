// 68. Text Justification



/// MY CODE(tried)
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> res;
        int n = words.size();

        int i = 0, j = 0;
        while(j<n){
            int len = 0;
            int wordCnt = 0;
            int k = j;
            while(j<n){
                len+=words[j].size();
                wordCnt++;
                j++;
                if(len+wordCnt-1<maxWidth){
                    // cout<<j<<" "<<wordCnt<<" "<<len<<endl;
                    continue;
                }
                else {
                    len-=words[j-1].size();
                    wordCnt--;
                    j--;
                    // cout<<"corrected: "<<j<<" "<<wordCnt<<" "<<len<<endl;
                    break;
                }
            }
           
            int totalExtraSpace = maxWidth - (len + wordCnt-1);
            int pad = 0;
            if(totalExtraSpace>(wordCnt-1) and (wordCnt-1)>0) pad = totalExtraSpace/(wordCnt-1);
            int extraPad = 0;
            if(wordCnt-1>0) totalExtraSpace%(wordCnt-1);
            
            // cout<<j<<" wordCnt: "<<wordCnt<<" len: "<<len<<" totalSp: "<<totalExtraSpace<<" pad: "<<pad<<" extpd"<<extraPad<<endl;

            string str = "";
            for(int l=k;l<j;l++){
                if(l!=k) {
                    if(wordCnt-1>0) str+=" ";
                    //pad between word
                    for(int space=0;space<pad;space++){
                        str+=" ";
                    }
                    //extra pad 
                    if(extraPad>0){
                        str+=" ";
                        extraPad--;
                    }
                }
                str+=words[l];
            }
            res.push_back(str);
        }
        return res;
    }
};




//solution 


vector<string> res;
for(int i = 0, k, l; i < words.size(); i += k) {
    for(k = l = 0; i + k < words.size() and l + words[i+k].size() <= maxWidth - k; k++) {
        l += words[i+k].size();
    }
    string tmp = words[i];
    for(int j = 0; j < k - 1; j++) {
        if(i + k >= words.size()) tmp += " ";
        else tmp += string((maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1)), ' ');
        tmp += words[i+j+1];
    }
    tmp += string(maxWidth - tmp.size(), ' ');
    res.push_back(tmp);
}
return res;