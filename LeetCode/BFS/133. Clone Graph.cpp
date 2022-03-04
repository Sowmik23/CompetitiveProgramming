/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    
    Node* cloneGraph(Node* node) {
     
        // traverse the graph: BFS/DFS
        
        //BFS
//         if(!node) return NULL;
        
//         Node* res = new Node(node->val, {});
        
//         unordered_map<Node*, Node*> mp;
//         mp[node] = res;
        
//         queue<Node*> q;
//         q.push(node);
        
//         while(!q.empty()){
//             Node* front = q.front();
//             q.pop();
            
//             for(Node* x : front->neighbors){
//                 if(mp.find(x)==mp.end()){ //if not found
//                     mp[x] = new Node(x->val, {});
//                     q.push(x);
//                 }
                
//                 mp[front]->neighbors.push_back(mp[x]);
//             }
//         }
        
//         return res;
 
    
        ////DFS
        if(!node) return NULL;
        if(mp.find(node)==mp.end()){
            mp[node] = new Node(node->val, {});
            for(Node* x : node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(x));
            }
        }
        
        return mp[node];
    }
};
