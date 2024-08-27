class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> v;
    int i=0,j=1;
    int maxi=*max_element(arr.begin(),arr.end());
    int n=arr.size();
    while(i<n && j<maxi) {
        if(j<arr[i]) {
            v.push_back(j);
            j++;
        }
        else if(j==arr[i]){
            i++;
            j++;
        }
    }
    if(k<=v.size()) return v[k-1];
    else return maxi+(k-v.size());
    }
};