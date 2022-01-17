/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        
        //go level by level and reverse the list
        
        vector<int> res;
        if(!root) return res;
        
        stack<Node*> stk;
        stk.push(root);
        
        while(!stk.empty()){
            
            Node* top = stk.top();
            stk.pop();
            res.push_back(top->val);
            
            for(int i=0;i<top->children.size();i++){
                if(top->children[i]!=NULL){
                    stk.push(top->children[i]);
                }
            }
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};
