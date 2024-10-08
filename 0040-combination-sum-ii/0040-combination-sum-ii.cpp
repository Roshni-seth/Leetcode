class Solution {
public:
    void f(vector<vector<int>> &v,vector<int> &v1,int i,int target,vector<int>& candidates) {
        if(target==0) {
            v.push_back(v1);
            return;
        }
        for(int j=i;j<candidates.size();j++) {
            if(j>i && candidates[j]==candidates[j-1]) continue;
            if(candidates[j]>target) break;
            v1.push_back(candidates[j]);
            f(v,v1,j+1,target-candidates[j],candidates);
            v1.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> v;
        vector<int> v1;
        f(v,v1,0,target,candidates);
        return v;
    }
};