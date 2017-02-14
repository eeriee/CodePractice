/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// use istringstream
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> tree;
        tree.push(root);
        while(!tree.empty()){
            int breadth = tree.size();
            string temp = "";
            for(int i = 0; i < breadth; ++i){
                TreeNode* node = tree.front();
                tree.pop();
                if(node ==  NULL){
                    s += "n";
                }else{
                    s += to_string(node->val);
                    tree.push(node->left);
                    tree.push(node->right);
                }
                s += ' ';
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        string s;
        in >> s;
        if(s == "n")
            return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> tree;
        tree.push(root);
        while(!tree.empty()){
            TreeNode* node = tree.front();
            tree.pop();
            string left, right;
            in >> left;
            in >> right;
            if(left != "n"){
                TreeNode* leftChild = new TreeNode(stoi(left));
                node->left = leftChild;
                tree.push(leftChild);
            }
            if(right != "n"){
                TreeNode* rightChild = new TreeNode(stoi(right));
                node->right = rightChild;
                tree.push(rightChild);
            }
        }
        return root;
    }
};
//bfs -written by myself
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> tree;
        tree.push(root);
        while(!tree.empty()){
            TreeNode* node = tree.front();
            tree.pop();
            if(node ==  NULL){
                s += "n";
            }else{
                s += to_string(node->val);
                tree.push(node->left);
                tree.push(node->right);
            }
            s += '*';
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        size_t start = 0, mid, end = data.find("*");
        string s = data.substr(start, end-start);
        if(s == "n")
            return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> tree;
        tree.push(root);
        while(!tree.empty()){
            TreeNode* node = tree.front();
            tree.pop();
            start = end+1;
            mid = data.find("*", start);
            end = data.find("*", mid+1);
            string left = data.substr(start, mid-start);
            string right = data.substr(mid+1, end-mid-1);
            if(left != "n"){
                TreeNode* leftChild = new TreeNode(stoi(left));
                node->left = leftChild;
                tree.push(leftChild);
            }
            if(right != "n"){
                TreeNode* rightChild = new TreeNode(stoi(right));
                node->right = rightChild;
                tree.push(rightChild);
            }
        }
        return root;
    }
};

// dfs
class Codec {
public:
    //preorder
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "n";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize(ss);
    }
    
    TreeNode* deserialize(stringstream& ss){
        string val;
        ss >> val;
        if(val == "n") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserialize(ss);
        node->right = deserialize(ss);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));