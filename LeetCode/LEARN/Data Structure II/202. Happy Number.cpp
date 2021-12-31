class Solution {
public:
    bool isHappy(int n) {
        
        set<int> st;
        int x = n;
        
        while(true){
            x = process(x);
            //cout<<x<<endl;

            if(x==1) return true;
            
            if(st.count(x)!=0) return false;
            else st.insert(x);
        }
        
        return false;
    }
private:
    int process(int n){
        int num = 0;
        while(n){
            int r = n%10; 
            num +=(r*r);
            n/=10;
        }
        //if(n%10==0) return 1;
        return num;
    }
};
