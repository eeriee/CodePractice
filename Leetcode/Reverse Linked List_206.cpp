/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Iterative Solution 1
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next = NULL;
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
//Iterative Solution 2
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> nodes;
        while(head != NULL){
            nodes.push(head->val);
            head = head->next;
        }
        ListNode* newHead = NULL;
        if(!nodes.empty()){
            newHead = new ListNode(nodes.top());
            nodes.pop();
        }
        ListNode* p = newHead;
        while(!nodes.empty()){
            p->next = new ListNode(nodes.top());
            nodes.pop();
            p = p->next;
        }
        return newHead;
    }
};
//Reversive Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverseListHelper(head, NULL);
    }
    
    ListNode* reverseListHelper(ListNode* curr, ListNode* prev){
        if(!curr) return prev;
        ListNode* next = curr->next;
        curr->next = prev;
        return reverseListHelper(next, curr);
    }
};
