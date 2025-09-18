class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }   
        int cnt=0;
        int prev=INT_MIN;
        int temp=1;
        for(auto i:s)
        {
            if(i==prev+1)
            {
                temp++;
            }
            else{
                cnt=max(cnt,temp);
                temp=1;
            }
            prev=i;
        }
        cnt=max(cnt,temp);
        return cnt;
    }
};