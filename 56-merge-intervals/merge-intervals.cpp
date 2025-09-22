class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int idx=0;
        int i=1;
        ans.push_back(arr[0]);
        while(i<arr.size())
        {
            if(arr[i][0]<=ans[idx][1])
            {
                ans[idx][0]=min(ans[idx][0],arr[i][0]);
                ans[idx][1]=max(ans[idx][1],arr[i][1]);
            }
            else{
                ans.push_back(arr[i]);
                idx++;
            }
            i++;
        }
        return ans;
    }
};