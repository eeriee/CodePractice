/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// O(1) space O(n) time
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* curr = root; //current node of current level
        TreeLinkNode* prev = NULL; //prev node of the next level
        TreeLinkNode* head = NULL; // head node on the next level
        while(curr != NULL){
            head = NULL;
            prev = NULL;
            while(curr != NULL){
                if(curr->left != NULL){
                    if(prev != NULL){
                        prev->next = curr->left;
                    }else{
                        head = curr->left;
                    }
                    prev = curr->left;
                }
                if(curr->right != NULL){
                    if(prev != NULL){
                        prev->next = curr->right;
                    }else{
                        head = curr->right;
                    }
                    prev = curr->right;
                }
                curr = curr->next;
            }
            curr = head; // move to the next level
        }
        
    }
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            TreeLinkNode* curr = new TreeLinkNode(0);
            for(int i = 0; i < len; ++i){
                curr->next = q.front();
                curr = curr->next;
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
                q.pop();
            }
            curr->next = NULL;
        }
    }
};