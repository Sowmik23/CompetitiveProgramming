//Follow-up: Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* root;
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        this->root = root;
        preprocess(root);
    }

    void preprocess(TreeNode* root){
        while(root){
            stk.push(root);
            root = root->left;
        }
    }

    int next() {
        if(!stk.empty()){
            TreeNode* top = stk.top();
            stk.pop();
            if(top->right) preprocess(top->right);
            return top->val;
        }
        return 0;
    }

    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* root;
    vector<int> inorder;
    int cnt = 0;
    BSTIterator(TreeNode* root) {
        this->root = root;

        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while(curr!=NULL or !stk.empty()){
            while(curr!=NULL){
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            inorder.push_back(curr->val);
            stk.pop();

            curr = curr->right;
        }
    }

    int next() {
        if(cnt<inorder.size()){
            int x = inorder.at(cnt);
            cnt++;
            return x;
        }
        return -1;
    }

    bool hasNext() {
        if(cnt<inorder.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
