class Solution {
public:

    int trap(vector<int>& height) {
        int n=height.size();
        int lMax,rMax,l=0,r=n-1;
        double total=0;
        while(l<r) {
            if(height[l]<=height[r]) {
                if(lMax>height[l])
                    total+=lMax-height[l];
                else 
                    lMax=height[l];
                l=l+1;
            }
            else {
                if(rMax>height[r])
                    total+=rMax-height[r];
                else
                    rMax=height[r];
                r=r-1;
            }
        }
        return (int)total;
    }
};