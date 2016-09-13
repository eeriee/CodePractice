class Solution {
public:
    vector<string> generatePalindromes(string s) {
        int n = s.size();
        vector<string> result;
        map<char, int> mp;
        int count = 0;
        string half = "";
        for(char c: s){
            if(mp[c]){
                --mp[c];
                --count;
                half += c;
            }
            else{
                ++mp[c];
                ++count;
            } 
        }
        if(count <= 1){
            string mid = "";
            if(count == 1){
                for(auto x: mp){
                    if(x.second){
                        mid += x.first;
                        break;
                    } 
                }
            }
            sort(half.begin(), half.end());
            helper(half, result, 0, n/2, mid);
        }
        return result;
    }
    void helper(string s, vector<string>& result, int start, int n, string mid){
        if(start >= n-1){
            s += mid;
            for(int i = n-1; i >= 0; --i){
                s += s[i];
            }
            result.push_back(s);
            return; 
        }
        for(int i = start; i < n; ++i){
            if(i != start && s[start] == s[i]) continue;
            swap(s[i], s[start]);
            helper(s, result, start+1, n, mid);
        }
    }
};
/*Question:
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].
*/
