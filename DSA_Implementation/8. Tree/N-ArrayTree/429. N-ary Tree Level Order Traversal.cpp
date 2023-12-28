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
    vector<vector<int>> levelOrder(Node* root) {

        vector<vector<int>> res;
        vector<int> tmp;

        if(!root) return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* top = q.front();
                q.pop();

                tmp.push_back(top->val);
                if(top->children.size()){
                    for(int i=0;i<top->children.size();i++){
                        q.push(top->children[i]);
                    }
                }
            }
            res.push_back(tmp);
            tmp = vector<int> ();
        }
        return res;
    }
};

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
    vector<vector<int>> levelOrder(Node* root) {


        if(root==NULL) return {};

        vector<vector<int>> res;

        queue<Node*> q;
        q.push(root);

        vector<int> tmp;

        while(!q.empty()){

            tmp = vector<int> ();
            int n = q.size();
            tmp = vector<int> ();

            for(int i=0;i<n;i++){
                Node* top = q.front();
                q.pop();

                tmp.push_back(top->val);

                for(auto j: top->children){
                    q.push(j);
                }
            }
            res.push_back(tmp);
        }


        return res;
    }
};
