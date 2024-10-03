class Solution {
public:
    const int MOD=1e9+7;
    long long myPow(long long base, long long exp,int mod) {
        long long ans=1;
        base =base%mod;
        while(exp>0) {
            if(exp%2==1) {
                ans=(ans*base)%mod;
            }
            exp=exp>>1;
            base=(base*base)%mod;
        }
        return ans;
    }
    int countGoodNumbers(long long n2) {
        long long nodd=n2/2;
        long long neven=n2-nodd;
        long long result=(myPow(5,neven,MOD)* myPow(4,nodd,MOD))%MOD;
        return result;
    }
};