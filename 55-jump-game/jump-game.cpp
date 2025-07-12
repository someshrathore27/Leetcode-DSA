class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxindex=0;
        for(int i=0;i<nums.size();i++)
        {
            if(maxindex>=nums.size())
            {
                return true;
            }
            if(i>maxindex)
            {
                return false;
            }
            maxindex=max(maxindex,i+nums[i]);
        }
        return true;
    }
};