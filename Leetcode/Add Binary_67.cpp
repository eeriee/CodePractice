/* stupid way, consider all cases
class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size(), len2 = b.size();
        if(len1 > len2) swap(a,b);
        stack<char> ans;
        int left = 0;
        int i = a.size()-1, j = b.size()-1;
        for(; i >= 0; --i, --j){
            if(a[i] == '0' && b[j] == '0'){
                ans.push(left +'0');
                left = 0;
            }else if(a[i] == '0' || b[j] == '0'){
                //only one 1
                ans.push(1 - left +'0');
            }else{
                //two 1
                if(left){
                    ans.push('1');
                }else{
                    left = 1;
                    ans.push('0');
                }
            }
        }
        for(; j >= 0; --j){
            if(left){
                if(b[j] == '0'){
                    left = 0;
                    ans.push('1');
                }else{
                    ans.push('0');
                }
            }else{
                ans.push(b[j]);
            }
        }
        if(left) ans.push(left +'0');
        string str = "";
        while(!ans.empty()){
            str += ans.top();
            ans.pop();
        }
        return str;
    }
};
*/