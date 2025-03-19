class Solution {
public:
    int romanToInt(string s) {
        int ans=0,i=0;
        while(i<s.size()) {
            if((s[i]=='I' && s[i+1]=='V') || (s[i]=='I' && s[i+1]=='X')) {
                if(s[i+1]=='V') ans=ans+4;
                else ans=ans+9;
                i=i+2;
            }
            else if((s[i]=='X' && s[i+1]=='L') || (s[i]=='X' && s[i+1]=='C')) {
                if(s[i+1]=='L') ans=ans+40;
                else ans=ans+90;
                i=i+2;
            }
            else if((s[i]=='C' && s[i+1]=='D') || (s[i]=='C' && s[i+1]=='M')) {
                if(s[i+1]=='D') ans=ans+400;
                else ans=ans+900;
                i=i+2;
            }
            else {
                if(s[i]=='I') ans=ans+1;
                else if(s[i]=='V') ans=ans+5;
                else if(s[i]=='X') ans=ans+10;
                else if(s[i]=='L') ans=ans+50;
                else if(s[i]=='C') ans=ans+100;
                else if(s[i]=='D') ans=ans+500;
                else if(s[i]=='M') ans=ans+1000;
                i++;
            }
        }
        return ans;
    }
};