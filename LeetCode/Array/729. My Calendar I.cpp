class MyCalendar {
public:
    vector<pair<int, int>> pa;
    MyCalendar() {
        pa = vector<pair<int, int>> ();
    }

    bool book(int start, int end) {
        for(auto& x: pa){
            if((start<=x.first and end>x.first) or (start>=x.first and (start<=x.second-1 or end<=x.second-1))) return false;
        }
        pa.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
