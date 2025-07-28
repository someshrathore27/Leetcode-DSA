class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int cnt=0;
        for(auto i:s)
        {
            if(s.find(i-1)==s.end())
            {
                int curr_num=i;
                int currcnt=1;
                while(s.find(curr_num+1)!=s.end())
                {
                    curr_num++;
                    currcnt++;
                }
                cnt=max(cnt,currcnt);
            }
        }
        return cnt;
    }
};