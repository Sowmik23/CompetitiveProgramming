/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        
        stack<Node*> stk;
        
        Node* curr = head;
        while(curr!=NULL){
            //cout<<curr->val<<" ";
            if(curr->next==NULL and !stk.empty()){
                Node* top = stk.top();
                stk.pop();
                
                curr->next = top;
                top->prev = curr;
            }
            if(curr->child){
                //cout<<curr->val<<" "<<curr->child->val<<endl;
                if(curr->next){
                    stk.push(curr->next);
                    curr->next->prev = NULL;
                }
                // curr->child->prev = curr;
                curr->next = curr->child;
                curr->next->prev = curr;


                //Great mistake: You must NULL the child
                curr->child = NULL;
            }
            curr = curr->next;
        }
        
//         cout<<endl;
//         curr = head;
//         Node* parent;
//         while(curr!=NULL){
//             parent = curr;
//             cout<<curr->val<<" ";
//             curr = curr->next;
//         }
//         cout<<endl;
        
//         while(parent!=NULL){
//             cout<<parent->val<<" ";
//             parent = parent->prev;
//         }
//         cout<<endl;
        
        return head;
    }
};
