//recursive
// 589. N-ary Tree Preorder Traversal
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
        recursive(root, res);

        return res;
    }
private:
    void recursive(Node* root, vector<int> &res){

        if(!root) return;
        res.push_back(root->val);
        if(root->children.size()) {
            for(int i=0;i<root->children.size();i++){
                recursive(root->children[i], res);
            }
        }
        return;
    }
};

//iterative
  vector<int> res;
  stack<Node*> stk;
  stk.push(root);

  while(!stk.empty()){
      Node* top = stk.top();
      stk.pop();
      if(!top) continue;
      res.push_back(top->val);
      if(top->children.size()){
          for(int i=top->children.size()-1;i>=0;i--){
              stk.push(top->children[i]);
          }
      }
  }

  return res;


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
