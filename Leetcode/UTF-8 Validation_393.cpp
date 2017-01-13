//concise way 
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for(int c: data){
            if(!count){
                if((c >> 5) == 0b110) count = 1;
                else if ((c >> 4) == 0b1110) count = 2;
                else if((c >> 3) == 0b11110) count = 3;
                else if((c >> 7)) return false;
            }else{
                if((c >> 6) != 2) return false;
                --count;
            }
        }
        return count == 0;
    }
};
// my way
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        if(n == 0) return true;
        vector<int> prefix = {0};
        for(int i = 3; i < 6; ++i){
            prefix.push_back(0x1F >> (5-i) & 0xFE);
        }
        for(int i = 0; i < n; ++i){
            if(!(data[i] >> 7)) continue;
            bool ok = false;
            for(int j = 1; j < 4; ++j){
                if(data[i] >> (6-j) == prefix[j]){
                    ok = true;
                    for(int k = 0; k < j; ++k){
                        ++i;
                        if(data[i]>>6 != 2) return false; 
                    }
                }
            }
            if(!ok) return false;
        }
        return true;
    }
};