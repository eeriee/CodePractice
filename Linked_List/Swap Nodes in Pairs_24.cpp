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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = head;
        ListNode* next = NULL;
        ListNode* prev = dummy;
        while(p != NULL && p->next != NULL){
            next = p->next;
            p->next = next->next;
            next->next = p;
            prev->next = next;
            prev = p;
            p = p->next;
        }
        return dummy->next;
    }
};