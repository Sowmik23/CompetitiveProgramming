
### DP Approach:

class Solution {
public:
    int res;
    int maxLength(vector<string>& arr) {

        //let's try solving with DP

        //recursion: Accepted

        // string tmp="";
        // return recursive(arr, tmp, arr.size());

        //recursion with memoization
        unordered_map<string, int> memo;
        string tmp = "";
        return recursionWithMemo(arr, memo, tmp, arr.size());
    }
private:
    ///dp approach
    int len = 0;
    int recursive(vector<string> &arr,  string tmp, int i){

        if(i==0) return tmp.size();

        int taken = 0, notTaken = 0;
        if(isUniqueue(tmp+arr[i-1], arr[i-1])) {
            taken = recursive(arr, tmp+arr[i-1], i-1);
        }
        notTaken = recursive(arr, tmp, i-1);

        return max(taken, notTaken);
    }

    int recursionWithMemo(vector<string> &arr, unordered_map<string, int> &memo, string tmp, int i){
        if(i==0) return tmp.size();
        if(memo[arr[i-1]+tmp]!=0) return memo[arr[i-1]+tmp];

        int taken = 0, notTaken = 0;
        if(isUniqueue(tmp+arr[i-1], arr[i-1])){
            taken = recursionWithMemo(arr, memo, tmp+arr[i-1], i-1);
        }
        notTaken = recursionWithMemo(arr, memo,  tmp, i-1);

        return memo[arr[i-1]+tmp] = max(taken, notTaken);
    }

    bool isUniqueue(string tmp, string str){
        set<char> st;
        for(auto& ch: tmp){
            if(st.find(ch)!=st.end()) return false;
            st.insert(ch);
        }
        st.clear();
        for(auto& ch: str){
            if(st.find(ch)!=st.end()) return false;
            st.insert(ch);
        }
        return true;
    }
};

##### BackkTracking Approach:

class Solution {
public:
    int res;
    int maxLength(vector<string>& arr) {

        //back-tracking

        string tmp = "";
        backTrack(arr, tmp, 0);
        return res;
    }
private:
    //backtracking
    void backTrack(vector<string> &arr, string tmp, int i){
        if(!ifUnique(tmp))  return ;
        if(tmp.size()>res) res = tmp.size();
        for(int j=i;j<arr.size();j++){
            backTrack(arr, tmp+arr[j], j+1);
        }
    }
    bool ifUnique(string tmp){
        set<char> st;
        for(auto& ch: tmp){
            if(st.find(ch)!=st.end()) return false;
            st.insert(ch);
        }
        return true;
    }
};
