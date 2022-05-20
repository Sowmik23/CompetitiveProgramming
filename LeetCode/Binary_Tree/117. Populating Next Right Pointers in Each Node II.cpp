/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        //Iterative: using extra space
        /*
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* top = q.front();
                q.pop();
                
                if(i==n-1) top->next = NULL;
                else top->next = q.front();
                
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        
        return root;
        */
        
        //Recursive: Not using extra space
        
        if(!root) return root;
        recursive(root);
        
        return root;
    }
private:
    void recursive(Node* root){
        
        if(!root) return ;
        
        cout<<root->val<<" ";
        
        Node* left = root->left;
        Node* right = root->right;
        
        Node* x = recursive(left);
        
        recursive(right);
    }
};
