public class Solution {
    public int[] SortArray(int[] nums) {
        List<int>arr=new List<int>();
        for(int i=0;i<nums.Length;i++)
        {
            arr.Add(nums[i]);
        }
        arr.Sort();
        for(int i=0;i<nums.Length;i++)
        {
            nums[i]=arr[i];
        }
        return nums;
    }
}