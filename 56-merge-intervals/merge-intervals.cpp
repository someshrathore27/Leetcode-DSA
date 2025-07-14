class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if(intervals.empty()){
            return {};
        }
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i) 
        {
            if(ans.back()[1] >= intervals[i][0]) 
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else 
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
