class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> st;
        long sum = 0;

        while(n){
            if(n==1) return true;
            sum = 0;
            while(n){
                int x = n%10;
                x*=x;
                sum+=x;
                n/=10;
            }
            if(sum==1) return true;
            if(st.count(sum)) return false;
            st.insert(sum);
            n = sum;
        }
        return false;
    }
};


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
