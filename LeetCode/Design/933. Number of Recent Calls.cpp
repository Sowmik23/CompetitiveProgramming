// 933. Number of Recent Calls
class RecentCounter {
public:
    deque<int> dq;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!dq.empty()){
            int f = dq.front();
            int diff = t-f;
            if(diff>3000) dq.pop_front();
            else break;
        }
        dq.push_back(t);
        return dq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */