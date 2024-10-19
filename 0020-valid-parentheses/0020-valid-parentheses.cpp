class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.length();i++) {
            if(stk.size()!=0) {
                // if(s[i]=='(' || s[i]=='{' || s[i]=='[') 
                    // stk.push(s[i]);
                if(s[i]==')' && stk.top()=='(') stk.pop();
                else if(s[i]=='}' && stk.top()=='{') stk.pop();
                else if(s[i]==']' && stk.top()=='[') stk.pop();
                else 
                    stk.push(s[i]);
            }
            else if(s[i]=='(' || s[i]=='{' || s[i]=='[') stk.push(s[i]);
            else if(s[i]==')' || s[i]=='}' || s[i]==']') return false;
        }
        if(stk.empty()) return true;
        else return false;
    }
};