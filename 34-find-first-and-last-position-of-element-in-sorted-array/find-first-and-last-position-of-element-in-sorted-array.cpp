class Solution {
public:
    int minid(vector<int>&arr,int k)
    {
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(arr[mid]==k)
            {
                ans=mid;
                e=mid-1;
            }
            else if(arr[mid]>k)
            {
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    int maxid(vector<int>&arr,int k)
    {
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(arr[mid]==k)
            {
                ans=mid;
                s=mid+1;
            }
            else if(arr[mid]>k)
            {
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int mini=minid(nums,target);
        int maxi=maxid(nums,target);
        vector<int>ans({mini,maxi});
        return ans;
    }
};