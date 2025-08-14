class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        
        bool sign = true;
        if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor >= 0)) 
            sign = false;
        
        long n = labs(dividend); 
        long d = labs(divisor);
        int ans = 0;
        
        while(n >= d) 
        {
            int cnt = 0;
            while(n >= (d << (cnt + 1))) // d<<(cnt+1) = d*2^(cnt+1)
            {
                cnt++;
            }
            ans = ans+ (1 << cnt);  // 1<<cnt = 2^cnt
            n = n-(d << cnt);  // d<<cnt = d*2^(cnt) 
        }
        
        if(!sign) ans = -ans;
        
        // Handle overflow cases
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        
        return ans;
    }

};