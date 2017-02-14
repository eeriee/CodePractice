/*
Time complexity: O(n*(2^n))
For a string with length n, there will be (n - 1) intervals between chars.
For every interval, we can cut it or not cut it, so there will be 2^(n - 1) ways to partition the string.
For every partition way, we need to check if it is palindrome, which is O(n).
So the time complexity is O(n*(2^n))
*/
class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    void helper(vector<vector<string>>& res, vector<string>& path, int start, string& s){
        if(start == s.size()) res.push_back(path);
        for(int i = start; i < s.size(); ++i){
            if(isPalindrome(s, start, i)){
                path.push_back(s.substr(start, i-start+1));
                helper(res, path, i+1, s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        helper(res, path, 0, s);
        return res;
    }
};