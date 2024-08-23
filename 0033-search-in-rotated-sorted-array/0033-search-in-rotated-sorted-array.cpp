class Solution {
public:
    int search(vector<int>& v, int target) {
        if(find(v.begin(),v.end(),target)!=v.end())
        return (find(v.begin(),v.end(),target)-v.begin());
    else
        return -1;
    }
};