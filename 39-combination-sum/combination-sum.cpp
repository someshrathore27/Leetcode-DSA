class Solution {
public:
    void solve(vector<int>& candidates, int target ,vector<vector<int>>&ans,vector<int>&output,int idx,int sum)
    {
        if(sum==target)
        {
            ans.push_back(output);
            return ;
        }   
        if(sum>target || idx>=candidates.size())
        {
            return;
        }
        output.push_back(candidates[idx]);

        solve(candidates,target,ans,output,idx,sum+candidates[idx]);

        output.pop_back();

        solve(candidates,target,ans,output,idx+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        int idx=0;
        int sum=0;
        solve(candidates,target,ans,output,idx,sum);
        return ans;
    }
};