class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)
        {
            return arr;
        }
        vector<int>sorted(arr.begin(),arr.end());
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int>mp;
        int last=INT_MAX;
        int rank=0;
        for(int i=0;i<sorted.size();i++)
        {
            int curr=sorted[i];
            if(last!=curr || last==INT_MAX)
            {
                rank++;
            }
            mp[sorted[i]]=rank;
            last=curr;
        }
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};