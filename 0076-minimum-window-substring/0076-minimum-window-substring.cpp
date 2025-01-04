class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(),n=t.size(),l=0,r=0,cnt=0,sIndex=-1;
        int minlen=INT_MAX;
        int hash[256]={0};
        for(int i=0;i<n;i++) 
            hash[t[i]]++;
        while(r<m) {
            if(hash[s[r]]>0) 
                cnt=cnt+1;
            hash[s[r]]--;
            
            while(cnt==n) {
                if((r-l+1)<minlen) {
                    minlen=r-l+1;
                    sIndex=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt=cnt-1;
                l++;
            }
            r=r+1;
        }
        return sIndex==-1?"":s.substr(sIndex,minlen);
    }
};