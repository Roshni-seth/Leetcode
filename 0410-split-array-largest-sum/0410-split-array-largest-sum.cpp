class Solution {
public:
    int partition(vector<int>& nums, int about) {
        int cntparts=1;
    long long subarraysum=0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (subarraysum + nums[i] <= about)
        {
            subarraysum+=nums[i];
        }
        else{
            cntparts++;
            subarraysum = nums[i];
        }
    }
    return cntparts;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high) {
            int mid=(low+high)/2;
            if(partition(nums,mid)<=k) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};