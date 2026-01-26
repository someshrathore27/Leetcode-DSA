public class Solution {
    public void NextPermutation(int[] nums) {
        int n=nums.Length;
        int sc=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                sc=i;
                break;
            }
        }
        if(sc==-1)
        {
            Array.Reverse(nums);
            return;
        }
        int rc=-1;
        for(int i=n-1;i>sc;i--)
        {
            if(nums[i]>nums[sc])
            {
                rc=i;
                break;
            }
        }
        int temp=nums[sc];
        nums[sc]=nums[rc];
        nums[rc]=temp;
        Array.Reverse(nums, sc + 1, n-sc-1);
    }
}