class Solution {
public:
    int Sum(vector<int>& nums,int div) {
        double sum=0;
        for(int i=0;i<nums.size();i++) 
            sum+=ceil((double)(nums[i])/(double)(div));
        return (int)sum;
    }
    int Max(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
            maxi=max(maxi,nums[i]);
        return maxi;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=Max(nums);
        while(low<=high) {
            int mid=(low+high)/2;
            int s=Sum(nums,mid);
            if(s<=threshold) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};