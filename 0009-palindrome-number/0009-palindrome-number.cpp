class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        else {
            long int rev_no=0,a,b=x;
            while(x!=0) {
                a=x%10;
                x=x/10;
                rev_no=rev_no*10+a;
            }
            if(rev_no==b) return true;
            else return false;
        }
    }
};