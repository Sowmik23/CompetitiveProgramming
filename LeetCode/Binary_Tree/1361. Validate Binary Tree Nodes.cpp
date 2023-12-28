// 1361. Validate Binary Tree Nodes

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        if (root == -1) {
            return false;
        }
        
        unordered_set<int> seen;
        stack<int> stack;
        seen.insert(root);
        stack.push(root);
        
        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();
            
            int children[] = {leftChild[node], rightChild[node]};
            for (int child : children) {
                if (child != -1) {
                    if (seen.find(child) != seen.end()) {
                        return false;
                    }
                    
                    stack.push(child);
                    seen.insert(child);
                }
            }
        }
        
        return seen.size() == n;
    }
    
    int findRoot(int n, vector<int>& left, vector<int>& right) {
        unordered_set<int> children;
        children.insert(left.begin(), left.end());
        children.insert(right.begin(), right.end());
        
        for (int i = 0; i < n; i++) {
            if (children.find(i) == children.end()) {
                return i;
            }
        }
        
        return -1;
    }
};