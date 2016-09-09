//sorted version. directly use sort() costs time.
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if(n < 0) return {};
        return findHelper(n, n);
    }
    vector<string> findHelper(int x, int n){
        if(x == 0) return {""};
        if(x == 1) return {"0","1","8"};
        vector<string> strs;
        vector<string> strs2 = findHelper(x-2,n);
        if(x < n) addString(strs, strs2, "0", "0");
        addString(strs, strs2, "1", "1");
        addString(strs, strs2, "6", "9");
        addString(strs, strs2, "8", "8");
        addString(strs, strs2, "9", "6");
        return strs;
    }
    void addString(vector<string> &strs1, vector<string> &strs2, string s1, string s2){
        for(string s: strs2){
            strs1.push_back(s1+s+s2);
        }
    }
};
//no sort
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if(n < 0) return {};
        return findHelper(n, n);
    }
    vector<string> findHelper(int x, int n){
        if(x == 0) return {""};
        if(x == 1) return {"0","1","8"};
        vector<string> strs;
        vector<string> strs2 = findHelper(x-2,n);
        for(string s: strs2){
            if(x < n)
                strs.push_back("0"+s+"0");
            strs.push_back("1"+s+"1");
            strs.push_back("6"+s+"9");
            strs.push_back("8"+s+"8");
            strs.push_back("9"+s+"6");
        }
        return strs;
    }
};

/*
Question:
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].

Hint:

Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.
*/
