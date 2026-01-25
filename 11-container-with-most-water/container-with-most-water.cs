public class Solution {
    public int MaxArea(int[] arr) {
        int s=0;
        int e=arr.Length-1;
        int max_water=0;
        while(s<e)
        {
            int width=e-s;
            int height=Math.Min(arr[s],arr[e]);
            int water=height*width;
            max_water=Math.Max(max_water,water);
            if(arr[s]<arr[e])s++;
            else{
                e--;
            }
        }
        return max_water;
    }
}