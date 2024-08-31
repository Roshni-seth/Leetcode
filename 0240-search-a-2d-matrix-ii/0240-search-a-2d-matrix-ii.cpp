class Solution {
public:
    bool FindTarget(vector<int>& matrix,int target) {
        int m=matrix.size();
        int low=0,high=m-1;
        while(low<=high) {
            int mid=(low+high)/2;
            if(matrix[mid]==target) return true;
            else if(matrix[mid]>=target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++) {
            if(matrix[i][0]<=target && matrix[i][n-1]>=target) 
                if(FindTarget(matrix[i],target)==0)
                    continue;
                else return true;
        }
        return false;
    }
};