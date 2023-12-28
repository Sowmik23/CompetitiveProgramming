class RandomizedSet {
public:
    set<int> st;

    RandomizedSet() {
        st = set<int> ();
    }

    bool insert(int val) {
        bool res = true;
        if(st.find(val)!=st.end()) res = false;
        st.insert(val);
        return res;
    }

    bool remove(int val) {
        bool res = false;
        if(st.find(val)!=st.end()) res = true;
        st.erase(val);
        return res;
    }

    int getRandom() {
        int n = st.size();
        int x = rand()%n;
        //cout<<x<<endl;
        set<int> ::iterator it;
        it = st.begin();
        advance(it, x);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
