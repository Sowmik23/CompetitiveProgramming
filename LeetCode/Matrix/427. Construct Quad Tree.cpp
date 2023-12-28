// 427. Construct Quad Tree

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        
        //n*n matrix
        return solve(grid, 0, 0, grid.size());
    }
private:
    Node* solve(vector<vector<int>> &grid, int i, int j, int n){
        if(isSameValueInMatrix(grid, i, j, n)){
            return new Node(grid[i][j], true);
        }
        else {
            Node* root = new Node(grid[i][j], false);

            root->topLeft = solve(grid, i, j, n/2);
            root->topRight = solve(grid, i, j+n/2, n/2);
            root->bottomLeft = solve(grid, i+n/2, j, n/2);
            root->bottomRight = solve(grid, i+n/2, j+n/2, n/2);

            return root;
        }
        return NULL;
    }
    bool isSameValueInMatrix(vector<vector<int>>&grid, int x, int y, int n){
        for(int i=x;i<x+n;i++){
            for(int j=y;j<y+n;j++){
                if(grid[i][j]!=grid[x][y]) return false;
            }
        }   
        return true;
    }
};