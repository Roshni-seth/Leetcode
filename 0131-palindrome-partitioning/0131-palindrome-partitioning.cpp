class Solution {
public:
    bool isPalindrome(int ind,int i,string s) {
        while(ind<=i) {
            if(s[ind++]!=s[i--]) return false;
        }
        return true;
    }
    void f(int ind,vector<vector<string>>& ans,vector<string>& v, string s) {
        if(ind==s.size()) {
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<s.size();i++) {
            if(isPalindrome(ind,i,s)){
                v.push_back(s.substr(ind,i-ind+1));
                f(i+1,ans,v,s);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        f(0,ans,v,s);
        return ans;
    }
};