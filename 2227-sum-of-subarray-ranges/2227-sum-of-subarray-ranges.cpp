class Solution {
public:
    vector<int> NGE(vector<int>& nums) {
        vector<int> nge(nums.size());
        stack<int> stk;
        int i;
        for(i=nums.size()-1;i>=0;i--) {
            while(!stk.empty() && nums[stk.top()]<=nums[i])
                stk.pop();
            nge[i]=(stk.empty())?nums.size():stk.top();
            stk.push(i);
        }
        return nge;
    }
    vector<int> PGEE(vector<int>& nums) {
        vector<int> pgee(nums.size());
        stack<int> stk;
        int i;
        for(i=0;i<nums.size();i++) {
            while(!stk.empty() && nums[stk.top()]<nums[i]) 
                stk.pop();
            pgee[i]=(stk.empty())?-1:stk.top();
            stk.push(i);
        }
        return pgee;
    }
    long long subarraySubMax(vector<int>& nums) {
        vector<int> pge=PGEE(nums);
        vector<int> nge=NGE(nums);
        long long total=0;
        int i;
        int mod=(int)(1e9+7);
        for(i=0;i<nums.size();i++) {
            int left=i-pge[i];
            int right=nge[i]-i;
            total=(total+(left*right*1LL*nums[i]));
        }
        return total;
    }

    vector<int> findNSE(vector<int>& nums) {
        vector<int> nse(nums.size());
        stack<int> stk;
        int i;
        for(i=nums.size()-1;i>=0;i--) {
            while(!stk.empty() && nums[stk.top()]>=nums[i])
                stk.pop();
            nse[i]=(stk.empty())?nums.size():stk.top();
            stk.push(i);
        }
        return nse;
    }
    vector<int> findPSEE(vector<int>& nums) {
        int n=nums.size();
        vector<int> psee(n);
        stack<int> stk; 
        for(int i=0;i<n;i++) {
            while(!stk.empty() && nums[stk.top()]>nums[i])
                stk.pop();
            psee[i]=(stk.empty())?-1:stk.top();
            stk.push(i);
        }
        return psee;
    }
    long long sumSubarrayMins(vector<int>& nums) {
        vector<int> nse=findNSE(nums);
        vector<int> pse=findPSEE(nums);
        long long total=0;
        int i;
        int mod=(int)(1e9+7);
        for(i=0;i<nums.size();i++) {
            int left=i-pse[i];
            int right=nse[i]-i;
            total=(total+(left*right*1LL*nums[i]));
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long largest=subarraySubMax(nums);
        long long smallest=sumSubarrayMins(nums);
        long long range=largest-smallest;
        return range;
    }
};