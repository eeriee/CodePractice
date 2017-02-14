// O(n)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) return 0;
        vector<int> counts(n+1);
        for(int cit: citations){
            if(cit >= n) ++counts[n];
            else ++counts[cit];
        }
        int cnt = 0;
        for(int i = n; i >= 0; --i){
            cnt += counts[i];
            if(cnt >= i) return i;
        }
        return 0;
    }
};
// O(nlogn)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for(int i = n; i >=0; --i){
            if(citations[n-i] >=i) return i;
        }
        return 0;
    }
};