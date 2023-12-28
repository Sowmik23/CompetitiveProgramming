// 819. Most Common Word
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        set<string> bannedSt;
        unordered_map<string, int> cntMp;
        for(auto& b : banned) bannedSt.insert(b);
        
        stringstream ss(paragraph);
        string word;
        int mx = 0;
        string res = "";

        while(ss>>word){
            stringstream ss1(word);
            while(getline(ss1, word, ',')){
                stringstream ss2(word);
                while(getline(ss2, word, '\'')){
                    stringstream ss3(word);
                    while(getline(ss3, word, '.')){
                        stringstream ss4(word);
                        while(getline(ss4, word, '!')){
                            stringstream ss5(word);
                            while(getline(ss5, word, '?')){
                                stringstream ss6(word);
                                while(getline(ss6, word, ';')){
                                    transform(word.begin(), word.end(), word.begin(), ::tolower);
                                    if(bannedSt.count(word)==0){
                                        cntMp[word]++;
                                        if(mx<cntMp[word]){
                                            mx = cntMp[word];
                                            res = word;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
private:
    bool isNotChar(char ch){
        return ch!='!' and ch!='?' and ch!='\'' and ch!=',' and ch!=';' and ch!='.';
    }
};