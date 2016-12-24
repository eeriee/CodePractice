/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> mp;
        RandomListNode* tail = head;
        
        //1. copy all the nodes
        while(tail != NULL){
             mp[tail] = new RandomListNode(tail->label);
             tail = tail->next;
        }
        tail = head;
        //2. assign next and random pointers
        while(tail != NULL){
            mp[tail]->next = mp[tail->next];
            mp[tail]->random = mp[tail->random];
            tail = tail->next;
        }
        return mp[head];
    }
};
// extra O(1) space
class Solution { 
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode* run = head;
        /* Insert the copy of each node after it. */
        while (run) {
            RandomListNode* copy = new RandomListNode(run -> label);
            copy -> next = run -> next;
            run -> next = copy;
            run = run -> next -> next;
        }
        /* Set the random pointer for each copy. */
        run = head;
        while (run) {
            if (run -> random)
                run -> next -> random = run -> random -> next;
            run = run -> next -> next;
        }
        /* Extract the copy list. */
        RandomListNode* new_head = new RandomListNode(0);
        RandomListNode* new_run;
        run = head;
        new_head -> next = head -> next;
        while (run) {
            new_run = run -> next;
            run -> next = new_run -> next;
            if (run -> next)
                new_run -> next = new_run -> next -> next;
            run = run -> next;
        }
        return new_head -> next;
    }
};