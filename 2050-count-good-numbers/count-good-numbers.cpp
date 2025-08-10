class Solution {
public:
    int mod=1e9+7;
    long long solve(long long x, long long n)
    {
        if(n==1)return x%mod;
        if(n==0)return 1;
        long long ans=solve(x,n/2) % mod;
        if(n%2==0)
        {
            return (ans*ans) % mod;
        }
        else{
            return (x*ans*ans) % mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long even=(n/2)+(n%2);
        long long odd=n/2;
        long long evenways=solve(5,even);
        long long oddways=solve(4,odd);
        return (evenways*oddways) % mod;
    }
};