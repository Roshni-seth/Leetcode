class Solution {
public:
    int Mini(int a1,int a2,int a3) {
        int temp;
        temp=min(a1,a2);
        return min(temp,a3);
    }
    int numberOfSubstrings(string s) {
        vector<int> lastseen(3,-1);
        int cnt=0;
        for(int i=0;i<s.length();i++) {
            lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1) 
                cnt=cnt+(1+Mini(lastseen[0],lastseen[1],lastseen[2]));
        }
        return cnt;
    }
};