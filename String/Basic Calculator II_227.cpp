class Solution {
public:
    int calculate(string s) {
        int sum = 0, num = 0;
        char op = '+';
        stack<int> stk;
        for(int i = 0; i < s.size(); ++i){
            if(isdigit(s[i])){
                num = num*10 + (s[i] - '0');
            }
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.size()-1){
                if(op =='-'){
                    num =-num;
                }else if(op != '+'){
                    int prev = stk.top();
                    stk.pop();
                    if(op == '*')
                        num *= prev;
                    else
                        num = prev/num;
                }
                stk.push(num);
                num = 0;
                op = s[i];
            }
        }
        while(!stk.empty()){
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};
class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
        int num = 0, sum = 0, next;
        char op;
        while(in >> op){
            if(op == '+' || op == '-'){
                sum += num;
                in >> num;
                if(op == '-') num = -num;
            }else{
                in >> next;
                if(op == '*') num *= next;
                else num /= next;
            }
        }
        return sum;
    }
};
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        istringstream in(s);
        int num;
        char op;
        bool flag = false;
        while(flag || in >> num){
            nums.push(num);
            flag = false;
            in >> op;
            if(in.eof()) break;
            if(op == '+' || op == '-'){
                ops.push(op);
            }else{
                flag = true;
                int prev = nums.top();
                nums.pop();
                int next;
                in >> next;
                if(op == '*'){
                    num = prev*next;
                }else{
                    num = prev/next;
                }
            }
        }
        int res = 0;
        while(!nums.empty()){
            int num = nums.top();
            nums.pop();
            if(nums.empty()){
                res += num;
                break;
            }
            op = ops.top();
            ops.pop();
            if(op == '-') res -= num;
            else res += num;
        }
        return res;
    }
};