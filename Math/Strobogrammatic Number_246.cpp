//for this solution. You can also store 0,1,8,6,9 and their corresponding value in a hashmap. But it's slower.
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int i = 0, j = num.length()-1;
        while(i<=j){
            char c = num[i];
            switch(c){
                case '6':
                    if(num[j] != '9')
                        return false;
                    break;
                case '9':
                    if(num[j] != '6')
                        return false;
                    break;
                case '0':
                case '1':
                case '8':
                    if(num[j] != num[i])
                        return false;
                    break;
                default:
                    return false;
            } 
            ++i;
            --j;
        }
        return true;
    }
};
//Very triky answer! Here is a C++ code. But it's really easy-written in Java. 
//https://discuss.leetcode.com/topic/20837/4-lines-in-java.
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int i = 0, j = num.length()-1;
        string s ="00 11 88 696";
        while(i<=j){
            string str;
            str += num[i];
            str += num[j];
            if(s.find(str) == string::npos) return false;
            ++i;
            --j;
        }
        return true;
    }
};
/* 
Question:
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/
