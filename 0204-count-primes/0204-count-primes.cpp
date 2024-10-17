class Solution {
public:
    int countPrimes(int N) {
        long long int cnt=0;
        vector<long long int> prime;
        prime.assign(N,1);
        for(long long int i=2;i*i<N;i++) {
            if(prime[i]==1) {
                for(int j=i*i;j<N;j+=i) {
                    prime[j]=0;
                }
            }
        }
        for(long long int i=2;i<N;i++) {
            if(prime[i]==1) cnt++;
        }
        return cnt;
    }
};