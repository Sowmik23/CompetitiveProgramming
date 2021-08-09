class MapSum {
public:
    /** Initialize your data structure here. */
    map<string, int> mapSum;
    MapSum() {
        mapSum = map<string, int> ();
    }
    
    void insert(string key, int val) {
        mapSum[key] = val;
    }
    
    int sum(string prefix) {
        int totalSum = 0;
        for(auto i: mapSum){
            if((i.first).compare(0, prefix.size(), prefix)==0){
                totalSum+=i.second;
            }
        }
        return totalSum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
