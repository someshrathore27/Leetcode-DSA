class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        
        bool sign = true;
        if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor >= 0)) 
            sign = false;
        
        long n = labs(dividend);  // Use long to avoid INT_MIN overflow
        long d = labs(divisor);
        int ans = 0;
        
        while(n >= d) {
            int cnt = 0;
            while(n >= (d << (cnt + 1))) {
                cnt++;
            }
            ans += (1 << cnt);
            n -= (d << cnt);
        }
        
        if(!sign) ans = -ans;
        
        // Handle overflow cases
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        
        return ans;
    }

};