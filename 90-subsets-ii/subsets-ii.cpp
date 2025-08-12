class Solution {
public:
    void solve(int idx,vector<int>& nums ,vector<int>&output,vector<vector<int>>&ans)
    {
        if(idx>=nums.size())
        {
            ans.push_back(output);
            return;
        }
        //include
        output.push_back(nums[idx]);
        solve(idx+1,nums,output,ans);
        output.pop_back();

        while(idx+1<nums.size() && nums[idx]==nums[idx+1])
        {
            idx++;
        }

        solve(idx+1,nums,output,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>output;
        vector<vector<int>>ans;
        solve(0,nums,output,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};