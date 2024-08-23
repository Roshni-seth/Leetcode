class Solution {
public:
    int end(vector<int>& nums,int target)
    {
        int n=nums.size();
        int low=0,high=n-1;
        int res=-1;
        while(low<=high) {
            int mid=(low+high)/2;
            if(nums[mid]==target) {
                low=mid+1;
                res=mid;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return res;
    }
    int start(vector<int>& nums,int target)
    {
        int n=nums.size();
        int low=0,high=n-1;
        int res=-1;
        while(low<=high) {
            int mid=(low+high)/2;
            if(nums[mid]==target) {
                high=mid-1;
                res=mid;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        v.push_back(start(nums,target));
        v.push_back(end(nums,target));
        return v;

    }
};