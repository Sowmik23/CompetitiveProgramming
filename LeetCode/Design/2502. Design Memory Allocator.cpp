// 2502. Design Memory Allocator
class Allocator {
public:
    int n;
    vector<int> memory;
    unordered_map<int, vector<int>> mp;

    Allocator(int n) {
        this->n = n;
        memory = vector<int> (n, -1);
    }
    
    int allocate(int size, int mID) {

        bool flag = false;
        int start = -1;
        int sz = 0;
        for(int i=0;i<n;i++){
            if(memory[i]!=-1){
                start = -1;
                sz = 0;
                continue;
            }
            if(start==-1) start = i;
            sz++;
            if(sz>=size){
                flag = true;
                break;
            }
        }
        if(flag){
            for(int i=start;i<start+size;i++){
                memory[i] = mID;
                mp[mID].push_back(i);
            }
            return start;
        }
        return -1;
    }
    
    int free(int mID) {
        int total = 0;
        for(auto& idx: mp[mID]){
            memory[idx]=-1;
            total++;
        }
        mp.erase(mID);
        return total;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */