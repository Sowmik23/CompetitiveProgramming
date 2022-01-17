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
    vector<int> preorder(Node* root) {
        
        vector<int> res;
        if(!root) return res;
        
        stack<Node*> stk;
        stk.push(root);
        Node* curr = root;
        
        while(!stk.empty()){
            if(curr!=NULL){
                res.push_back(curr->val);
                
                for(int i=curr->children.size()-1;i>=0;i--){
                    if(curr->children[i]!=NULL){
                        stk.push(curr->children[i]);
                    }
                }
                curr = stk.top();
                stk.pop();
            }
        }
        
        return res;
    }
};
