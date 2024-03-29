{
    ListNode *st = new ListNode(0);
        st->next = head;

        ListNode* prev = st;
        for(int i=1;i<left;i++){
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        //reversing
        // [1,2,3,4,5] 2->4
        // 2 3 4
        // curr = 2, forw = curr next 3
        // curr next 2 next = forw next 4 next 5
        // forw next 4 = prev next 2
        // prev next 2 = forw 4
        for(int i=0;i<right-left;i++){ //Deep Here :(
            ListNode* forward = curr->next;
            curr->next = forward->next;
            forward->next = prev->next;
            prev->next = forward;
        }
        return st->next;
    }



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        
        if(left==right) return head;
        
        ListNode* tmp = head;
        int cnt = 1;
        
        ListNode* prev = NULL;
        ListNode* last = head;
        
        ListNode start = NULL;
        ListNode* s = &start;
        
        ListNode h = NULL;
        ListNode* hh = &h;
        
        while(tmp){
            if(cnt==left-1){
                prev = tmp;
            }
            if(cnt==left){
                while(tmp!=NULL and cnt<=right){
                   //cout<<tmp->val<<endl;
                    s->next = tmp;
                    tmp = tmp->next;
                    s = s->next;
                    cnt++;
                }
                s->next = NULL;
                last = tmp;
                break;
            }
            cnt++;
            tmp = tmp->next;
        }
        
        if(prev!=NULL) {
            prev->next = reverse(start.next, last);
            return head;
        }
        hh->next = reverse(start.next, last);
        
        return h.next;
    }
private:
    ListNode* reverse(ListNode* head, ListNode* last){
        
        ListNode* curr = head;
        ListNode* tmp;
        ListNode* prev = last;

        while(curr){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        
        return prev;
    }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL) return NULL;
        else if(left==right) return head;
        
        ListNode res(0);
        res.next = head;
        // res->next = head;
        ListNode* slow = &res;
        
        right-=left;
        
        for(int i=1;i<left;i++){
            slow = slow->next;
        }
        
        ListNode* fast = slow->next;
        ListNode* tmp;
        
        
        
        while(right--){
            tmp = fast->next;
            fast->next = fast->next->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        return res.next;
    }
};
