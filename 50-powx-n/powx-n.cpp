class Solution {
public:
    double solve(double x, int n)
    {
        if(n==1)return x;
        if(n==0)return 1.0;
        double ans=solve(x,n/2);
        if(n%2==0)
        {
            return ans*ans;
        }
        else{
            return x*ans*ans;
        }
    }
    double myPow(double x, int n) {
        long long N=n;
        double ans=solve(x,abs(N));
        if(n<0)
        {
            return 1/ans;
        }
        return ans;
    }
};