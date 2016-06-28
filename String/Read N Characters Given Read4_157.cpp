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
        int count = 0, tmp = 0;
        while(n > 0){
            tmp = min(read4(buf),n);
            buf += tmp;
            count += tmp;
            if(tmp < 4)
                break;
            n -= 4;
        }
        return count;
    }
};
