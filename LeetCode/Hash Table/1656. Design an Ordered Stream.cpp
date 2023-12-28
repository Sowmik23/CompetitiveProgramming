// 1656. Design an Ordered Stream
class OrderedStream {
public:
    unordered_map<int, string> mp;
    int i;
    int n;
    OrderedStream(int n) {
        this->n = n;
        this->i = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> res;
        mp[idKey] = value;
        while(mp.find(i)!=mp.end()){
            res.push_back(mp[i]);
            i++;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */