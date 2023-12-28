// 1845. Seat Reservation Manager

class SeatManager {
public:
    set<int> reservedSet, unreservedSet;
    set<int> ::iterator it;

    SeatManager(int n) {
        for(int i=1;i<=n;i++) unreservedSet.insert(i);
    }
    
    int reserve() {
        it = unreservedSet.begin();
        int reserved = *it;
        unreservedSet.erase(reserved);
        reservedSet.insert(reserved);
        return reserved;
    }
    
    void unreserve(int seatNumber) {
        reservedSet.erase(seatNumber);
        unreservedSet.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */



 class SeatManager {
public:
    int start = 1;
    priority_queue<int, vector<int>, greater<int>> vacantQ;

    SeatManager(int n) {
        //Special hint: You can't unserved without reserving seat. and reserving rule is
        //smallest number first. So, it will happen increasingly.
    }
    
    int reserve() {
        int reserved;
        if(vacantQ.empty()){
            reserved = start;
            start++;
        }
        else {
            reserved = vacantQ.top();
            vacantQ.pop();
        }
        return reserved;
    }
    
    void unreserve(int seatNumber) {
       vacantQ.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */