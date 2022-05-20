class ATM {
public:
    ATM() {
        
    }
    unordered_map<long, long> mp;
    vector<long> notes = {20, 50, 100, 200, 500};
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<banknotesCount.size();i++){
                mp[notes[i]] += banknotesCount[i];  
        }
    }
    
    vector<int> withdraw(int amount) {
        
        vector<int> res;
        map<long, long> m;
        
        // cout<<"amount: "<<amount<<endl;
        // for(int i=0;i<=4;i++) cout<<notes[i]<<" "<<mp[notes[i]]<<endl;        
        
        unordered_map<long, long> tmp;
        for(int i=0;i<=4;i++){
                tmp[notes[i]] = mp[notes[i]];  
        }
        
        long amnt = amount;
        for(int i=4;i>=0;i--){
            if(amnt<0) return {-1};
            long c = amnt/notes[i];

            long x = min(tmp[notes[i]], c);

            m[notes[i]]+=x;
            tmp[notes[i]]-=x;                        

            amnt = amnt - (x*notes[i]);
        }

        if(amnt==0){
            for(int i=0;i<=4;i++){
                mp[notes[i]]-=m[notes[i]];
                res.push_back(m[notes[i]]);
            }    
        }
        else return {-1};
        
        
        return res;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
