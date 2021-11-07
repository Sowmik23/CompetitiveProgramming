class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        
        ListNode(int val){
            this->val = val;
            this->next = NULL;
        }
    };
    ListNode* head = NULL;
    int size = 0;
    
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if(index<size and index>=0){
            ListNode* curr = head;
            //cout<<curr->val<<endl;
            // cout<<curr->next->val<<endl;
            // cout<<curr->next->next->val<<endl;
            // cout<<"sowmik"<<endl;
            for(int i=0;i<index;i++){
                // cout<<curr->val<<endl;
                curr = curr->next;
            }
            //cout<<curr->val<<endl;
            return curr->val;
        }    
        return -1;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void print(){
        ListNode* curr = head;
        for(int i=0;i<size;i++){
            cout<<curr->val<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return;
        
        ListNode* tmp = new ListNode(val);
            
        if(index==0){
            tmp->next = head;
            head = tmp;
            size++;
           // print();
            return;
        }
        if(index<=size){
            ListNode* curr = head;
            for(int i=0;i<index-1;i++){
                curr = curr->next;
            }
            
            tmp->next = curr->next;
            curr->next = tmp;
            size++;
            
            //print();
            return ;
        }
    }
    
    void deleteAtIndex(int index) {
        if(size==0) return;
        
        if(index==0){
            ListNode* tmp = head;
            head = head->next;
            delete(tmp);
            size--;
            return;
        }
        if(index<size){
            ListNode* curr = head;
            for(int i=0;i<index-1;i++){
                curr = curr->next;
            }
            ListNode* tmp = curr->next;
            if(curr->next) curr->next = curr->next->next;
            delete(tmp);
            
            size--;
            //print();
            return;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
