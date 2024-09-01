class Solution {
public:
    string removeOuterParentheses(string s) {
         string s1;
    stack<int> stk;
    for(int i=0;i<s.length();i++) {
        if(stk.empty())
            stk.push(s[i]);
        else if(s[i]=='(') {
            s1+=s[i];
            stk.push(s[i]);
        } 
        else if(stk.size()!=1) {
            s1+=s[i];
            stk.pop();
        }
        else 
            stk.pop();
    }
    return s1;
    }
};