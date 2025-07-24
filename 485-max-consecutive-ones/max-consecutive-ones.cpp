class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int s=0;
        int e=0;
        int temp=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                s=i;
                e=i;
                cnt=max(cnt,temp);
                temp=0;
            }
            else if(nums[i]==1)
            {
                e=i;
                temp++;
            }
        }
        return max(cnt,temp);
    }
};