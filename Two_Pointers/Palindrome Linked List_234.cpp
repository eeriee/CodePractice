/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        // because fast can traverse twice of slow
        // different if using fast != NULL && fast->next != NULL
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverseList(slow->next);
        fast = head;
        while(slow != NULL){ // need to be use slow != NULL
            if(fast->val != slow->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* next = head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

 // cal length
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        int len = 0;
        ListNode* p1 = head;
        while(p1 != NULL){
            ++len;
            p1 = p1->next;
        }
        p1 = head;
        ListNode* p2 = head;
        ListNode* prev = NULL;
        for(int i = 0; i < len/2; ++i){
            p2 = p1->next;
            p1->next = prev;
            prev = p1;
            p1 = p2;
        }
        if(len%2) p2 = p2->next;
        p1 = prev;
        while(p1 != NULL){
            if(p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};