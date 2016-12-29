//easy way to understand sliding but use two hashmaps
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size() || s.size() == 0 || p.size() == 0) return {};
        vector<int> pdict(256);
        vector<int> sdict(256);
        vector<int> indices;
        
        for(char c: p) ++pdict[c];
        
        int start = 0, count = p.size();
        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            ++sdict[c];
            if(sdict[c] <= pdict[c]) --count;
            if(count == 0) indices.push_back(start);
            if(i - start + 1 == p.size()){
                char first = s[start];
                if(sdict[first] <= pdict[first]) ++count;
                --sdict[first];
                ++start;
            }
        }
        return indices;
    }
};

// use only one hashmap
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size() || s.size() == 0 || p.size() == 0) return {};
        vector<int> dict(256);
        vector<int> indices;
        
        for(char c: p) ++dict[c];
        
        int start = 0, end = 0, count = p.size();
        while(end < s.size()){
            if(dict[s[end]] > 0) --count;
            --dict[s[end]];
            ++end;
            if(count == 0) indices.push_back(start);
            if(end - start == p.size()){
                if(dict[s[start]] >= 0) ++count;
                ++dict[s[start]];
                ++start;
            }
        }
        return indices;
    }
};