/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serialize(root, ss);
        
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        
        return deserialize(ss);
    }
private:
    void serialize(TreeNode* root, stringstream& ss){
        if(root){
            ss<<root->val<<" ";
            serialize(root->left, ss);
            serialize(root->right, ss);
        }
        else ss<<"# ";
    }
    TreeNode* deserialize(stringstream& ss){
        string val;
        
        ss>>val;
        if(val=="#") return NULL;
        //cout<<val<<endl;
        TreeNode* root = new TreeNode(std::stoi(val));
        root->left = deserialize(ss);
        root->right = deserialize(ss);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
