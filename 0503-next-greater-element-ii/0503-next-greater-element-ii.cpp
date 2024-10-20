class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> stk;
        int n=nums.size();
        for(int i=2*n-1;i>=0;i--) {
            while(!stk.empty() && stk.top()<=nums[i%n]) stk.pop();
            if(i<n) {
                ans[i]=stk.empty()?-1:stk.top();
            }
            stk.push(nums[i%n]);
        }
        return ans;
    }
};