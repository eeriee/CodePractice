class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.empty()) return true;
        int min = INT_MIN, max = INT_MAX;
        stack<int> root;
        root.push(preorder[0]);
        for(int i = 1; i < preorder.size(); i++){
            if(preorder[i] < preorder[i-1]){ //left child
                if(preorder[i]<min || preorder[i]>max) return false;
            }else{//right child
                while(!root.empty()){
                    if(preorder[i] > root.top()){
                        min = root.top();
                        max = INT_MAX;
                        root.pop();
                    }else{
                        max = root.top();
                        break;
                    }
                }
                //if(preorder[i] < min || preorder[i] > max) return false;
            } 
            root.push(preorder[i]);
        }
        return true;
    }
};
//28%
