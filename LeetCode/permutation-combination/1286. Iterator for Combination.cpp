class CombinationIterator {
public:
    vector<string> combinations;
    int position = 0;
    
    CombinationIterator(string characters, int combinationLength) {
        
        string tmp="";
        CalculateCom(characters, tmp, 0, characters.size(), combinationLength);
        
        sort(combinations.begin(), combinations.end());
    }
    
    string next() {
        string res = combinations.at(position);
        position++;
        return res;
    }
    
    bool hasNext() {
        if(position<combinations.size()) return true;
        return false;
    }
private:
    void CalculateCom(string str, string tmp, int i, int j, int length){
        if(tmp.size()==length){
            combinations.push_back(tmp);
        }
        for(int k=i;k<j;k++){
            tmp+=(str[k]);
            CalculateCom(str, tmp, k+1, j, length);
            tmp.pop_back(); 
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
