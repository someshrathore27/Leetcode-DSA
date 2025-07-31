class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if(numRows==0)  return ans;
        vector<int>temp;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==1) return ans;
        int i=1;
        while(i<numRows)
        {
            int currsize=ans[i-1].size()+1;
            vector<int>temp(currsize);
            int j=0;
            while(j<currsize)
            {
                if(j==0 || j==currsize-1)
                {
                    temp[j]=1;
                }
                else {
                    temp[j]=ans[i-1][j-1]+ans[i-1][j];
                }
                j++;
            }
            i++;
            ans.push_back(temp);
        }
        return ans;
    }
};