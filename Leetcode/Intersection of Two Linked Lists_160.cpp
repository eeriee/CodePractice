/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// can also memory the last one to avoid twice traverse if no intersection
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1 != NULL && p2 != NULL && p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
            
            // Any time they collide or reach end together without colliding 
            // then return any one of the pointers.

            if(p1 == p2) return p1;

            // If one of them reaches the end earlier then reuse it 
            // by moving it to the beginning of other list.
            // Once both of them go through reassigning, 
            // they will be equidistant from the collision point.
            
            if(p1 == NULL) p1 = headB;
            if(p2 == NULL) p2 = headA;
        }
        return p1;
    }
};
 // use difference of length
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        int lenA = 0, lenB = 0;
        ListNode* listA = headA;
        ListNode* listB = headB;
        while(listA != NULL){
            ++lenA;
            listA = listA->next;
        }
        while(listB != NULL){
            ++lenB;
            listB = listB->next;
        }
        if(lenA > lenB){
            swap(headA, headB);
            swap(lenA, lenB);
        }
        int diff = lenB - lenA;
        listA = headA;
        listB = headB;
        while(diff != 0){
            listB = listB->next;
            --diff;
        }
        while(listA != NULL){
            if(listA == listB) return listA;
            listA = listA->next;
            listB = listB->next;
        }
        return NULL;
    }
};