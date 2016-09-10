class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> mp1; 
        unordered_map<string, char> mp2; 
        str += " ";
        auto i = str.find(" ");
        size_t j = 0;
        int count = 0;
        while(i != string::npos){     
            if(count > pattern.size()-1) return false;
            string s = str.substr(j, i-j);
            char p = pattern[count++];
            if(!mp1.count(p)){
                if(mp2.count(s)) return false;
                mp1[p] = s;
                mp2[s] = p;
            }else if(mp1[p] != s){
                return false;
            }
            j = i+1;
            i = str.find(" ", j);
        }
        return count == pattern.size();
    }
};
//clear solution
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> mp1; 
        unordered_map<string, int> mp2; 
        istringstream stream(str);
        int i = 0, n = pattern.size();
        for(string word; stream >> word; ++i){
            if(i == n || mp1[pattern[i]] != mp2[word]) 
            //access empty key will insert the key and give the default value. 
                return false;
            mp1[pattern[i]] = mp2[word] = i+1; //since the default value is 0 (for int). The value should > 0
        }
        return i == n;
    }
};
