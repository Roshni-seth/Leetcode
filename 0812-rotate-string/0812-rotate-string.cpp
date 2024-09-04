class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp;
    int rotation = 0;
    while (s != goal && rotation <= s.length())
    {
        temp = s.substr(0,1);
        for (int i = 0; i < s.length(); i++)
        {
            if (i == s.length() - 1)
                s.replace(i,1,temp);
            else
                s.replace(i,1,s.substr(i+1,1));
        }
        rotation++;
    }
    if (s == goal)
        return true;
    else
        return false;
    }
};