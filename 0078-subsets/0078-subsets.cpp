class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int subsets=1<<nums.size();
        for(int n=0;n<=subsets-1;n++) {
            vector<int> v;
            for(int i=0;i<nums.size();i++) {
                if(n&(1<<i)) v.push_back(nums[i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};