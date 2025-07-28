class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return;
        }
        int l=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                l=i;
                break;
            }
        }
        if(l==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int swapnum=-1;
        for(int i=n-1;i>l;i--)
        {
            if(nums[i]>nums[l])
            {
                swapnum=i;
                break;
            }
        }
        
        swap(nums[swapnum],nums[l]);
        sort(nums.begin()+l+1,nums.end());
        return;
    }
};