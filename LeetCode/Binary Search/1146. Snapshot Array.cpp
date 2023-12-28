// 1146. Snapshot Array
class SnapshotArray {
public:
    vector<vector<pair<int, int>>> mp;
    int snapId;
    SnapshotArray(int length) {
        this->snapId = 0;
        mp = vector<vector<pair<int, int>>> (length);
        for(int i=0;i<length;i++){
           mp[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        mp[index].push_back({this->snapId, val});
    }
    
    int snap() {
        this->snapId++;
        return this->snapId-1;
    }
    
    int get(int index, int snap_id) {

        auto upBnd = upper_bound(mp[index].begin(), mp[index].end(), make_pair(snap_id, INT_MAX));
        return prev(upBnd)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */