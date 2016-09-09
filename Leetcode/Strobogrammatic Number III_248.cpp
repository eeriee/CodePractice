/* stupid method but faster. 52ms.
1. use strobogrammatic number II method to generate the strings of len1 and len2 and compare those strings with low and high. 
2. For strings between len1 and len2, use getSize() to count the number of strings.
*/
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        lo = low;
        hi = high;
        sum = 0;
        int len1 = low.length(), len2 = high.length();
        if(len1 == len2){
            if(lo.compare(hi) > 0) return 0;
            findHelper(len1, len1, 0);
        }else if(len1 < len2){
            findHelper(len1, len1, 1);
            findHelper(len2, len2, 2);
            if(len2 > len1 + 1){
                int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
                getSize(len1, len1, s1);
                getSize(len1-1, len1-1, s2);
                getSize(len2-1, len2-1, s3);
                getSize(len2-2, len2-2, s4);
                sum += s3 + s4 - s1 - s2;
            }
        }
        return sum;
    }
    int getSize(int x, int n, int &s){
        if(x == 0) return 1;
        if(x == 1) {
            s += 3;
            return 3;
        }
        int size = getSize(x-2, n, s);
        s += size*4;
        if(x < n)
            size *= 5;
        else
            size *= 4;
        return size;
    }
    vector<string> findHelper(int x, int n, int comp){
        if(x == 0) return {""};
        if(x == 1) {
            if(n == 1){
                switch(comp){
                    case 0:
                        if(lo.compare("0") <= 0 && hi.compare("0") >= 0)    ++sum;
                        if(lo.compare("1") <= 0 && hi.compare("1") >= 0)    ++sum;
                        if(lo.compare("8") <= 0 && hi.compare("8") >= 0)    ++sum; 
                        break;
                    case 1:
                        if(lo.compare("0") <= 0)    ++sum;
                        if(lo.compare("1") <= 0)    ++sum;
                        if(lo.compare("8") <= 0)    ++sum;  
                        break;
                    default:
                        break;
                }
                 
            }
            return {"0","1","8"};
        }
        vector<string> strs;
        vector<string> strs2 = findHelper(x-2, n, comp);
        if(x < n) 
            addString(strs, strs2, "0", "0");
        if(x == n){
            addStringLowHigh(strs, strs2, "1", "1", comp);
            addStringLowHigh(strs, strs2, "6", "9", comp);
            addStringLowHigh(strs, strs2, "8", "8", comp);
            addStringLowHigh(strs, strs2, "9", "6", comp);
        }else{
            addString(strs, strs2, "1", "1");
            addString(strs, strs2, "6", "9");
            addString(strs, strs2, "8", "8");
            addString(strs, strs2, "9", "6");
        }
        return strs;
    }
    void addString(vector<string> &strs1, vector<string> &strs2, string s1, string s2){
        for(string s: strs2){
            strs1.push_back(s1+s+s2);
        }
    }
    void addStringLowHigh(vector<string> &strs1, vector<string> &strs2, string s1, string s2, int comp){
        for(string s: strs2){
            string tmp = s1+s+s2;
            switch(comp){
                case 0:
                    if(tmp.compare(lo) >= 0 && tmp.compare(hi) <=0)
                        ++sum;
                    break;
                case 1:
                    if(tmp.compare(lo) >= 0)
                        ++sum;
                    break;
                case 2:
                    if(tmp.compare(hi) <= 0)
                        ++sum;
                    break;
                default:
                    break;
            }
            
        }
    }
    private:
        int sum;
        string lo,hi;
};
//smart solution. slower. 80ms.
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int count = 0;
        for(int len = low.length(); len <= high.length(); ++len){
            string s(len, '0');
            helper(low, high, s, 0, len-1, count); //make up strobogrammatic number of len.
        }
        return count;
    }
    void helper(string lo, string hi, string s, int left, int right, int& count){
        if(left > right){
            if((s.length() == lo.length() && s.compare(lo) < 0) ||
            (s.length() == hi.length() && s.compare(hi) > 0)) return;
            ++count;
            return;
        }
        for(auto m: mp){
            int fst = m.first, sec = m.second;
            s[left] = fst;
            s[right] = sec;
            if(s.length() != 1 && s[0] == '0') continue; //if the number has more than two digits, make sure it not start from 0.
            if(left < right || fst == sec) helper(lo, hi, s, left+1, right-1, count);
            //count if the left<right or when left==right, the mid digit has value in {'0', '1', '8'}.
        }
    }
    private:
        map<char, char> mp ={{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
};
/*Question:
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.
*/
