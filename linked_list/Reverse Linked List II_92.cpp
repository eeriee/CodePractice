/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Solution 1
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0), *prev, *start, *curr;
        dummy -> next = head;
        prev = dummy; 
        for(int i = 0; i < m-1; ++i){
            prev = prev -> next;
        }
        start = prev -> next; 
        curr = start -> next;
        for(int i = 0; i < n-m; ++i){
            start -> next = curr -> next;
            curr -> next = prev -> next;
            prev -> next = curr;
            curr = start -> next;
        }
        return dummy -> next;
    }
};
//Solution 2
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *rb = NULL, *p;
        queue<int> start, end;
        stack<int> rl;
        int count = 1;
        while(head != NULL){
            int val = head -> val;
            if(count >= m && count <= n){
                rl.push(val);
            }else if(count < m){
                start.push(val);
            }else{
                end.push(val);
            }
            head = head -> next;
            ++count;
        }
        if(!start.empty()){
            rb = new ListNode(start.front());
            start.pop();
        }else if(!rl.empty()){
            rb = new ListNode(rl.top());
            rl.pop();
        }
        p = rb;
        while(!start.empty()){
            p -> next = new ListNode(start.front());
            start.pop();
            p = p -> next;
        }
        while(!rl.empty()){
            p -> next = new ListNode(rl.top());
            rl.pop();
            p = p -> next;
        }
        while(!end.empty()){
            p -> next = new ListNode(end.front());
            end.pop();
            p = p -> next;
        }
        return rb;
    }
};
//Solution 3
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *prev = NULL, *curr = head, *next = NULL, *tmp, *rl = head;
        for(int i = 0; i < m-1; ++i){
            curr = curr -> next;
        }
        for(int i = m; i <= n; ++i){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        if(m != 1){
            tmp = rl;
            for(int i = 0; i < m-2; ++i){
                tmp = tmp -> next;
            }
            tmp -> next = prev;
        }else{
            rl = prev;
        }
        
        if(prev == NULL) return rl;
        else{
            while(prev -> next != NULL){
                prev = prev -> next;
            }
            prev -> next = curr; 
        }
        return rl;
    }
};
