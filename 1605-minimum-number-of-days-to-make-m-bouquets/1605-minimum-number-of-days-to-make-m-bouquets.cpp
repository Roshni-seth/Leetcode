class Solution {
public:
    bool possible(vector<int>& bloomDay, int m,int k,int day) {
        int n=bloomDay.size();
        int cnt=0, noOfB=0;
        for(int i=0;i<n;i++) {
            if(day>=bloomDay[i]) cnt++;
            else {
                noOfB+=(cnt/k);
                cnt=0;
            }
        }
        noOfB+=(cnt/k);
        if(noOfB>=m) return true;
        else return false;
    }
    int Min(vector<int>& bloomDay) {
        int mini=INT_MAX;
        for(int i=0;i<bloomDay.size();i++) {
            mini=min(mini,bloomDay[i]);
        }
        return mini;
    }
    int Max(vector<int>& bloomDay) {
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++) 
            maxi=max(maxi,bloomDay[i]);
        return maxi;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=Min(bloomDay),high=Max(bloomDay);
        long long val= m*1LL*k*1LL;
        if(val>bloomDay.size()) return -1;
        while(low<=high) {
            int mid=(low+high)/2;
            if(possible(bloomDay,m,k,mid)==true) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};