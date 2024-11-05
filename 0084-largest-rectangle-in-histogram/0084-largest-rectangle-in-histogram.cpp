class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int maxArea=0,i;
        for(i=0;i<heights.size();i++) {
            while(!stk.empty() && heights[stk.top()]>heights[i]) {
                int ele=stk.top();
                stk.pop();
                int nse=i;
                int pse=(stk.empty())?-1:stk.top();
                maxArea=max(maxArea, heights[ele]*(nse-pse-1));
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            int nse=heights.size();
            int ele=stk.top();
            stk.pop();
            int pse=(stk.empty())?-1:stk.top();
            maxArea=max(maxArea, heights[ele]*(nse-pse-1));
        }
        return maxArea;
    }
};