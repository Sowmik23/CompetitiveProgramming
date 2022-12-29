class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {

    }

    int book(int start, int end) {
        mp[start]++;
        mp[end]--;

        int k = 0;
        int ongoing = 0;

        for(auto& [i, j] : mp){
            ongoing+=j;
            k = max(k, ongoing);
        }
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
