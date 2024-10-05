class Solution {
public:
    void generate(vector<vector<int>> &V,int l,vector<int> &v,vector<int>& nums) {
        if(l==nums.size()) {
            V.push_back(v);
            return;
        }
        v.push_back(nums[l]);
        generate(V,l+1,v,nums);
        // V.push_back(v);
        v.pop_back();
        generate(V,l+1,v,nums);
        // V.push_back(v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> V;
        vector<int> v;
        generate(V,0,v,nums);
        return V;
    }
};