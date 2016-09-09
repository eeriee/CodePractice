// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        while(!remain.empty() && count < n){
            buf[count++] = remain.front();
            remain.pop();
        }
        n -= count;
        buf += count;
        while(n > 0){
            int tmp = read4(buf);
            int add = min(tmp, n);
            buf += add;
            count += add;
            if(add < 4){
                if(tmp > n){
                    for(int i=0; i<tmp-add; ++i){
                        remain.push(buf[i]);
                    }
                }
                break;
            }
            n -= 4;
        }
        return count;
    }
    queue<int> remain;
};
