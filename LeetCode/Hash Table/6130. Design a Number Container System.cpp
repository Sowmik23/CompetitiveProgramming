class NumberContainers {
public:
    unordered_map<int, priority_queue<int,vector<int>, greater<int>>> mp;
    unordered_map<int, int> blockedList;
    
    NumberContainers() {

    }
    
    void change(int index, int number) {
        blockedList[index] = number;
       
        mp[number].push(index);
    }
    
    int find(int number) {
        
        if(mp.find(number)!=mp.end()) {
            
           while(!mp[number].empty()){
               int x = mp[number].top();
               if(blockedList[x]==number) return x;
               mp[number].pop();
           }   
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
