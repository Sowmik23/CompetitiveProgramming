// Reservoir sampling: which is a family of randomized algorithms for sampling from a population of unknown size.

// The reservoir sampling algorithm is intended to sample k elements from an population of unknown size. 
// In our case, the k happens to be one.


//first one is fixed range sampling using extra array
//second one is reservior sampling

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

// Follow up:
// What if the linked list is extremely large and its length is unknown to you?
// Could you solve this efficiently without using extra space?

    // vector<int> nums;
    // int n;

    //without using extra space
    ListNode* node;
    Solution(ListNode* head) {
        // while(head){
        //     nums.push_back(head->val);
        //     head = head->next;
        // }
        // this->n = nums.size();

        //without using extra space
        this->node = head;
    }
    
    int getRandom() {
        // int rnd = rand()%n;
        // return nums[rnd];


        //  Reservoir Sampling
        // The reservoir sampling algorithm is intended to sample k elements from an population of unknown size. In our case, the k happens to be one.

        //without using extra space
        int scope = 1;
        int res = 0;
        ListNode* tmp = node;
        while(tmp){
            if(rand()%scope==0) res = tmp->val;
            scope++;
            tmp = tmp->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */