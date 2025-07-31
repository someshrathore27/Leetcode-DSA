class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(arr[mid]==target)
            {
                return mid;
            }
            else if(arr[mid]>target)
            {
                ans=mid;
                e=mid-1;
            }
            else{
                ans=mid+1;
                s=mid+1;
            }
        }
        return ans;
    }
};