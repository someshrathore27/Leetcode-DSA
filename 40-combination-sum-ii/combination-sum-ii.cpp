class Solution {
public:
    void solve(vector<int>& arr, int target,int sum ,int idx , vector<vector<int>>&ans ,vector<int>&output) 
    {
        if(sum==target)
        {
            ans.push_back(output);
            return;
        }
        if(sum>target || idx>=arr.size())
        {
            return;
        }

        // include
        output.push_back(arr[idx]);
        solve(arr,target,sum+arr[idx],idx+1,ans,output);
        output.pop_back();

        while (idx + 1 < arr.size() && arr[idx] == arr[idx + 1])
        {
            idx++;
        }

        //exclude
        solve(arr,target,sum,idx+1,ans,output);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>output;
        vector<vector<int>>ans;
        int idx=0;
        int sum=0;
        solve(candidates,target,sum,idx,ans,output);
        return ans;
    }
};