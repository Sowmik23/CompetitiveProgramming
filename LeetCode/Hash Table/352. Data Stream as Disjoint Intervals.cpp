class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        st = set<int> ();
    }

    void addNum(int value) { //O(logn)
        st.insert(value);
    }

    vector<vector<int>> getIntervals() { //O(n)
        vector<vector<int>> res;
        if(st.empty()) return res;
        int left = -1, right = -1;

        for(auto& s: st){
            if(left<0){
                left = right = s;
            }
            else if(s==right+1){
                right = s;
            }
            else {
                res.push_back({left, right});
                left = right = s;
            }
        }
        res.push_back({left, right});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
