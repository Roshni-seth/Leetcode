class Solution {
public:
    int maxele(vector<int>& piles) {
       int maxi=INT_MIN;
       for(int i=0;i<piles.size();i++) {
        maxi=max(maxi,piles[i]);
       }
       return maxi;
    }
    double check(vector<int>& piles,int m) {
        double totaltime=0;
        for(int i=0;i<piles.size();i++) {
            totaltime+=ceil((double)(piles[i])/(double)(m));
        }
        return totaltime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=maxele(piles);
        while(low<=high) {
            int mid=(low+high)/2;
            double totalTime=check(piles,mid);
            if(totalTime<=h) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};