class Solution {
public:
    void make(vector<string> &vs,int left,int right,string str,int n) {
        if(str.length()==2*n) {
            vs.push_back(str);
            return;
        }
        if(left<n) {
            make(vs,left+1,right,str+'(',n);
        }
        if(right<left) {
            make(vs,left,right+1,str+')',n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        make(vs,0,0,"",n);
        return vs;
    }
};