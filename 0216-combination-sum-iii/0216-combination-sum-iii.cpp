class Solution {
public:
    void f(int i,int k,int n,vector<int>& v,vector<vector<int>>& ans) {
        if(v.size()==k) {
            if(n==0) {
                ans.push_back(v);
            }
            return;
        }
        for(int j=i;j<10;j++) {
            v.push_back(j);
            f(j+1,k,n-j,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        f(1,k,n,v,ans);
        return ans;
    }
};