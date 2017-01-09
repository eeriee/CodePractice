/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// divide and conquer, nlog(k), but faster than pq because it deal with the case that only one list exist
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int k = lists.size();
        while(k > 1){
            for(int i = 0; i < k/2; ++i){
                lists[i] = mergeTwoLists(lists[i], lists[k-1-i]);
            }
            k = (k+1)/2; 
        }
        return lists[0];
    }
};
// use priority_queue nlog(k)
class cmp{
public:
    bool operator()(const ListNode* l1, const ListNode* l2) const{
        return l1->val > l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(ListNode* li: lists){
            if(li != NULL) pq.push(li);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        while(!pq.empty()){
            ListNode* li = pq.top();
            pq.pop();
            ptr->next = li;
            ptr = ptr->next;
            if(li->next != NULL){
                pq.push(li->next);
            }
        }
        return dummy->next;
    }
};