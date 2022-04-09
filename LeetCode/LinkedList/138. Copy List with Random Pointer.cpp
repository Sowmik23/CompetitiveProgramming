/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head) return head;
        
        //unordered_map<Node*, Node*> mp;
        
        Node* curr = head;
        
        while(curr!=NULL){
            Node* tmp = new Node(curr->val);
            tmp->next = curr->next;
            
            curr->next = tmp;
            curr = tmp->next;
        }
        
        curr = head;
        while(curr!=NULL){
            curr->next->random = curr->random ? curr->random->next : NULL;
            curr = curr->next->next;
        }
        
        Node* res = head->next;
        curr = head->next;
        
        while(head!=NULL){
            head->next = curr->next;
            head = head->next;
            
            if(!head) break;
            
            curr->next = head->next;
            curr = curr->next;
        }
        
        return res;
    }
};
