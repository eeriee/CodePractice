//all solutions cost 0ms.
//my first solution, use map to store frequency
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> dict;
        for(int i = 0; i < s.length(); ++i){
            ++dict[s[i]];
        }
        bool even = (s.length()%2)? false:true;
        int count = 0;
        for(auto it = dict.begin(); it != dict.end(); ++it){
            int val = it->second;
            if(val%2){
                ++count;
                if(even || count > 1) return false;
            }
                
        }
        return true;
    }
};
//char as index
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> dict(128,0);
        for(int i = 0; i < s.length(); ++i){
            char c = s[i];
            if(dict[c]) --dict[c];
            else ++dict[c];
        }
        int count = 0;
        for(int i = 0; i < 128; ++i){
            if(dict[i]) ++count;
            if(count > 1) return false;
        }
        return true;
    }
};
//set
class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> per;
        for(int i = 0; i < s.length(); ++i){
            char c = s[i];
            if(per.count(c)) per.erase(c);
            else per.insert(c);
        }
        int n = per.size();
        return n < 2; 
    }
};
/*bitset. A bitset stores bits (elements with only two possible values: 0 or 1, true or false, ...).
Flip()
Flips bit values converting zeros into ones and ones into zeros 
count()
Returns the number of bits in the bitset that are set (i.e., that have a value of one).*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> b;
        for(char c: s)
            b.flip(c);
        return b.count() < 2;
    }
};
/*
Question:
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
*/

