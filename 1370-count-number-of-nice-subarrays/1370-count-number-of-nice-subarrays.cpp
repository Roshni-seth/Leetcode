class Solution {
public:
    int func(vector<int>& nums,int goal) {
        if(goal<0) return 0;
        int l=0,r=0,sum=0,cnt=0;
        while(r<nums.size()) {
            sum+=(nums[r]%2);
            while(sum>goal) {
                sum=sum-(nums[l]%2);
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int ans=func(nums,k)-func(nums,k-1);
        return ans;
    }
};