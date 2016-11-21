/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//bfs 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* node1 = q.front();
            q.pop();
            TreeNode* node2 = q.front();
            q.pop();
            if(node1 == NULL && node2 == NULL) continue;
            if(node1 == NULL || node2 == NULL || node1->val != node2->val) return false;
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }
};
//dfs
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || helper(root->left, root->right);
    }
    bool helper(TreeNode* n1, TreeNode* n2){
        if(n1 == NULL && n2 == NULL) return true;
        if(n1 == NULL || n2 == NULL || n1->val != n2->val) return false;
        return helper(n1->left, n2->right) && helper(n1->right, n2->left);
    }
};

//my silly solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root,1));
        int depth = 0;
        unordered_map<int, TreeNode*> mp;
        mp[1] = root;
        while(!q.empty()){
            int n = q.size();
            int breadth  = 1 << depth;

            for(int i = 0; i < n; ++i){
                auto item = q.front();
                TreeNode* node = item.first;
                int idx = item.second;
                int val = node->val;
                q.pop();
                int symIdx = 3*breadth - idx - 1;
                cout << idx << " " << symIdx << endl;
                if(!mp.count(symIdx) || mp[symIdx] == NULL || mp[symIdx]->val != val) return false;
                mp[idx*2] = node->left;
                mp[idx*2+1] = node->right;
                if(node->left != NULL){
                    q.push(make_pair(node->left, idx*2));
                }    
                if(node->right != NULL)
                    q.push(make_pair(node->right, idx*2+1));
            }
            ++depth;
        }
        return true;
    }
};