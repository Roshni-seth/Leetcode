class Solution {
public:
    void f(vector<vector<int>> &v,vector<int> &v1,int i,int target,vector<int>& candidates) {
        if(i==candidates.size()) {
            if(target==0) {
                v.push_back(v1);
            }
            return;
        }
        if(candidates[i]<=target) {
            v1.push_back(candidates[i]);
            f(v,v1,i,target-candidates[i],candidates);
            v1.pop_back();
        }
        
        f(v,v1,i+1,target,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> v1;
        f(v,v1,0,target,candidates);
        return v;
    }
};