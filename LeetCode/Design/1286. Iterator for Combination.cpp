// 1286. Iterator for Combination
class CombinationIterator {
public:
    vector<string> allPossibleComb;
    int index = 0;
    CombinationIterator(string characters, int combinationLength) {
        backTrack(characters, combinationLength, 0, "");
        sort(allPossibleComb.begin(), allPossibleComb.end());
        for(auto& a: allPossibleComb) cout<<a<<" ";
        cout<<endl;
    }
    
    string next() {
        return allPossibleComb[index++];
    }
    
    bool hasNext() {
        return index<allPossibleComb.size();
    }
    void backTrack(string str, int len, int idx, string tmp){
        if(tmp.size()==len){
            allPossibleComb.push_back(tmp);
            return;
        }
        for(int i=idx;i<str.size();i++){
            tmp.push_back(str[i]);
            backTrack(str, len, i+1, tmp);
            tmp.pop_back();
        }
        return;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */