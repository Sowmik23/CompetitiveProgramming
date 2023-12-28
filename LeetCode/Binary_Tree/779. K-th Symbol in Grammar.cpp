// 779. K-th Symbol in Grammar

class Solution {
public:
    int kthGrammar(int n, int k) {
        
        //TLE
        /*
        string str = "0";
        for(int i=2;i<=n;i++){
            string tmp = "";
            int len = str.size();

            for(int j=0;j<len;j++){
                if(str[j]=='0') tmp+="01";
                else tmp+="10";
            }
            str = tmp;
        }
        return str[k-1]-'0';
        */

        //Binary Tree Traversal: Seaching n'th node in a binary tree
        //Perfect/Complete binary tree

        //Recursive Approach:
        //Time: O(n)
        // return dfsSearch(n, k, 0);

        //Normal recursion
        //Time: O(n)
        return recursive(n, k);
    }
private:
    int dfsSearch(int n, int k, int rootVal){
        if(n==1) return rootVal;

        int totalNodes = pow(2, n-1);

        //target node will be present in the right half sub-tree of the current root node
        if(k>(totalNodes/2)){
            int nextRootVal = (rootVal==0) ? 1 : 0; //as 0-> 01
            return dfsSearch(n-1, k-(totalNodes/2), nextRootVal);
        } //target node is in the left sub-tree of the current root node
        else {
            int nextRootVal = (rootVal==0) ? 0 : 1; //as 1->10
            return dfsSearch(n-1, k, nextRootVal);
        }
    }
    int recursive(int n, int k){
        //first row have only "0"
        if(n==1) return 0;

        int totalNodes = pow(2, n-1);
        int halfNodes = totalNodes/2;

        if(k>halfNodes){
            return 1-recursive(n-1, k-halfNodes);
        }
        return recursive(n-1, k);
    }
};

// Notice the pattern!!!
// First part is always same. Always concate same length sting with toggled value.
// 0
// 01
// 0110
// 01101001
// 0110100110010110
// 01101001100101101001011001101001
// 0110100110010110100101100110100110010110011010010110100110010110