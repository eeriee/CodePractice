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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode* walker = head;
        ListNode* runner = head;
        while(runner!= NULL && runner->next!= NULL){ 
            //runner!=NULL is to ensure we can get runner->next
            //if runner != NULL than walker won't be NULL
            walker = walker->next;
            runner = runner->next->next;
            if(walker == runner) return true;
        }
        return false;
    }
};