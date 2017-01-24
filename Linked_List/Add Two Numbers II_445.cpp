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
        stack<int> s1, s2;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while(p1 != NULL){
            s1.push(p1->val);
            p1 = p1->next;
        }
        while(p2 != NULL){
            s2.push(p2->val);
            p2 = p2->next;
        }
        int sum = 0;
        ListNode* node = new ListNode(0);
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            node->val = sum%10;
            ListNode* head = new ListNode(sum/10);
            head->next = node;
            node = head;
            sum /= 10;
        }
        return node->val == 0 ? node->next:node;
    }
};