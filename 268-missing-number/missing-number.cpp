class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int j=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(j!=nums[i]){
                return j;
            }
            j++;
        }
        return j;
    }
};