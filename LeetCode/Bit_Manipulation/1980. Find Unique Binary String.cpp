// 1980. Find Unique Binary String

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        const int n = nums.size();
  
 /*
        //Approach-01: generate all string
        //Time: O(n^2)

        set<string> st;
        for(auto& num: nums){
            st.insert(num);
        }

        //start generating binary string of length n
        string str = "";
        return generateBinaryStringOflenN(n, str, st);
*/

    /*
        //Approach-02: Iterate over integer equivalent

        unordered_set<int> st;
        for(auto& num: nums){
            int x = stol(num, 0, 2);
            st.insert(x);
        }
        // long limit = pow(2, n);
        for(int i=0;i<=n;i++){
            if(st.find(i)==st.end()){
                string str = std::bitset<16>(i).to_string().substr(16 - n);
                return str;
            }
        }
        return "";
        */

        // Approach 4: Cantor's Diagonal Argument
        // such a briliant idea!!!!!

        string res = "";
        for(int i=0;i<nums.size();i++){
            char bit = nums[i][i];
            res += bit=='0' ? "1" : "0";
        }
        return res;
    }
private:
    string generateBinaryStringOflenN(int n, string str, set<string> &st){

        if(str.size()==n){
            if(st.count(str)==0) return str;
            return "";
        }

        string zeroStr = generateBinaryStringOflenN(n, str+"0", st);
        if(zeroStr.size()>0) return zeroStr;
        return generateBinaryStringOflenN(n, str+"1", st);
    }
};