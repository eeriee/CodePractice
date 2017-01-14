//static dp
class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }
        
        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Since cntPerfectSquares is a static vector, if 
        // cntPerfectSquares.size() > n, we have already calculated the result 
        // during previous function calls and we can just return the result now.
        static vector<int> cntPerfectSquares({0});
        
        // While cntPerfectSquares.size() <= n, we need to incrementally 
        // calculate the next result until we get the result for n.
        while (cntPerfectSquares.size() <= n)
        {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i*i <= m; i++)
            {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            }
            
            cntPerfectSquares.push_back(cntSquares);
        }
        
        return cntPerfectSquares[n];
    }
};
//math method
class Solution 
{  
private:  
    int is_square(int n)
    {  
        int sqrt_n = (int)(sqrt(n));  
        return (sqrt_n*sqrt_n == n);  
    }
    
public:
    // Based on Lagrange's Four Square theorem, there 
    // are only 4 possible results: 1, 2, 3, 4.
    int numSquares(int n) 
    {  
        // If n is a perfect square, return 1.
        if(is_square(n)) 
        {
            return 1;  
        }
        
        // The result is 4 if and only if n can be written in the 
        // form of 4^k*(8*m + 7). Please refer to 
        // Legendre's three-square theorem.
        while ((n & 3) == 0) // n%4 == 0  
        {
            n >>= 2;  
        }
        if ((n & 7) == 7) // n%8 == 7
        {
            return 4;
        }
        
        // Check whether 2 is the result.
        int sqrt_n = (int)(sqrt(n)); 
        for(int i = 1; i <= sqrt_n; i++)
        {  
            if (is_square(n - i*i)) 
            {
                return 2;  
            }
        }  
        
        return 3;  
    }  
}; 
//dp
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for(int i = 1; i <=n; ++i){
            int minNum = INT_MAX;
            for(int j = 1; j*j <= i; ++j){
                minNum = min(dp[i-j*j]+1, minNum);
            }
            dp[i] = minNum;
        }
        return dp[n];
    }
};
//bfs - modified way
class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(n);
        int step = 0;
        while(!q.empty()){
            int breadth = q.size();
            for(int b = 0; b < breadth; ++b){
                int num = q.front();
                q.pop();
                int sqrt_root = (int) sqrt(num);
                if(sqrt_root*sqrt_root == num) return step+1;
                for(int i = sqrt_root; i > 0; --i){
                    q.push(num - i*i);
                }
            }
            ++step;
        }
        return -1;
    }
    
};
class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(n);
        int depth = 0;
        int breadth = 0;
        int m = 1;
        while(!q.empty()){
            if(m == 0){
                ++depth;
                m = breadth;
                breadth = 0;
            }
            int num = q.front();
            q.pop();
            --m;
            int sr = (int) sqrt(num);
            int lmt = num/3; //think about why it can make sure it's the best answer?
            for(int i = sr; i > 0 && i*i >= lmt; --i){
                int res = num - i*i;
                if(res == 0) return depth+1;
                q.push(res);
                ++breadth;
            }
        }
        return 0;
    }
};

