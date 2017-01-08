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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        int sum = 0;
        while(node1 != NULL || node2 != NULL){
            sum /= 10;
            if(node1 != NULL){
                sum += node1->val;
                node1 = node1->next;
            }
            if(node2 != NULL){
                sum += node2->val;
                node2 = node2->next;
            }
            ptr->next = new ListNode(sum%10);
            ptr = ptr->next;
        }
        if(sum/10) ptr->next = new ListNode(1);
        return dummy->next;
    }
};