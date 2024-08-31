class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
    int low=0,high=m*n-1;
    while(low<=high) {
        int mid=(low+high)/2;
        int i=mid/n,j;
        if(mid<n) j=mid;
        else j=mid-n*i;
        if(matrix[i][j]==target) return true;
        else if(matrix[i][j]>=target) high=mid-1;
        else low=mid+1;
    }
    return false;
    }
};