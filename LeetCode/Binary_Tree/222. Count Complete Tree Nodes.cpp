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
class Solution {
public:
    int countNodes(TreeNode* root) {

        //The subtree of a complete binary tree is also a complete binary tree. Cool!

        /* Time analysis with this solution is actually very tricky. In the beginning, I thought if each node
        takes logN time, then it will be O(NlogN). On a second thought, however, if(hl==hr) return pow(2,hl)-1;
        makes sure on each level/depth of the tree, only one node can possibly trigger the recursion,
        therefore it becomes h (height of the tree=logN) + (h-1) + (h-2)...+1 = O(h^2) = O(logN*logN).
        How beautiful is this! */

        //Time: O(logn*logn)

        int leftHight = 0;
        int rightHight = 0;
        TreeNode* leftR = root;
        TreeNode* rightR = root;

        while(leftR) {
            leftHight++;
            leftR = leftR->left;
        }

        while(rightR){
            rightHight++;
            rightR = rightR->right;
        }

        if(leftHight==rightHight) return pow(2, leftHight)-1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
