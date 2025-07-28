class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int p=0;
        int n=1;
        int size=nums.size();
        vector<int>ans(size);
        for(int i=0;i<size;i++)
        {
            if(nums[i]>0)
            {
                ans[p]=nums[i];
                p=p+2;
            }
            else if(nums[i]<0)
            {
                ans[n]=nums[i];
                n=n+2;
            }
        }
        return ans;
    }
};