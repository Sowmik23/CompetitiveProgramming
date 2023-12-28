class Solution {
public:
    bool reorderedPowerOf2(int n) {


        //first thought
        //convert int to string and do permutation of that string
        //check each string that has length as n (as may contain leading zero) if power of two


        int largetPowerofTwoForInt = findLargetPowerofTwoForInt();

        string str = to_string(n);
        return permutation(str, largetPowerofTwoForInt, 0, str.size()-1);
    }
private:
    bool permutation(string str, int largetPowerofTwoForInt, int start, int end){

        if(start==end){
            if(str[0]!='0'){
                int x = stoi(str);
                return x>0 and largetPowerofTwoForInt%x==0;
            }
        }
        for(int i=start;i<=end;i++){
            swap(str[start], str[i]);
            if(permutation(str, largetPowerofTwoForInt, start+1, end)) return true;
            swap(str[start], str[i]);
        }
        return false;
    }
    int findLargetPowerofTwoForInt() {
        long x = 2;
        while(x<=INT_MAX){
            x*=2;
        }
        return x;
    }
};
