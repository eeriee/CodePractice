/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//dfs. write by myself. 8ms.
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        helper(root, 0, 0);
        vector<vector<int>> order(mp.size());
        int i = 0;
        for(auto m: mp){
            for(auto it: m.second)
                order[i].insert(order[i].end(), it.second.begin(), it.second.end());
            ++i;
        }
        return order;
    }
    void helper(TreeNode* node, int col, int row){
        if(node == NULL) return;
        helper(node->left, col-1, row+1);
        mp[col][row].push_back(node->val);
        helper(node->right, col+1, row+1);
    }
    map<int, map<int,vector<int>>> mp;
};

//bfs. inspired by others. faster. 12ms.
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> order;
        if(!root) return order;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        map<int, vector<int>> mp;
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int col = q.front().second;
            q.pop();
            mp[col].push_back(node->val);
            if(node->left) q.push({node->left, col-1});
            if(node->right) q.push({node->right, col+1});
        }
        for(auto m: mp)
            order.push_back(m.second);
        return order;
    }
    
};
/*
Question:
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:

Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,8,4,0,1,7],
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2
return its vertical order traversal as:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
Show Company Tags
Show Tags
Show Similar Problems
*/
