/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *dummy = new ListNode(0), *p1, *p2;
        dummy->next = head;
        p1 = dummy;
        p2 = dummy;
        while(p1->next != NULL){
            p1 = p1->next;
            if(p1->val != 9){
                p2 = p1;
            }
        }
 
        ++(p2->val);
        while(p2->next != NULL){
            p2 = p2->next;
            p2->val = 0;
        }  

        if(dummy->val == 1)
            return dummy;
        return dummy->next;
    }
};
