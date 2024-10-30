class Solution {
public:
    vector<int> findNSE(vector<int>& arr) {
        vector<int> nse(arr.size());
        stack<int> stk;
        int i;
        for(i=arr.size()-1;i>=0;i--) {
            while(!stk.empty() && arr[stk.top()]>=arr[i])
                stk.pop();
            nse[i]=(stk.empty())?arr.size():stk.top();
            stk.push(i);
        }
        return nse;
    }
    vector<int> findPSEE(vector<int>& arr) {
        int n=arr.size();
        vector<int> psee(n);
        stack<int> stk;
        for(int i=0;i<n;i++) {
            while(!stk.empty() && arr[stk.top()]>arr[i])
                stk.pop();
            psee[i]=(stk.empty())?-1:stk.top();
            stk.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=findNSE(arr);
        vector<int> pse=findPSEE(arr);
        int total=0,i;
        int mod=(int)(1e9+7);
        for(i=0;i<arr.size();i++) {
            int left=i-pse[i];
            int right=nse[i]-i;
            total=(total+(left*right*1LL*arr[i])%mod)%mod;
        }
        return total;
    }
};