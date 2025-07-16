class Solution {
public:
    int t[101][101];
    bool solve(int i,int cnt, string s)
    {
        if(i==s.length())
        {
            return (cnt==0);
        }
        if(t[i][cnt]!=-1)
        {
            return t[i][cnt];
        }
        bool isvalid=false;
        if(s[i]=='(')
        {
            isvalid=solve(i+1,cnt+1,s);
        }
        else if(s[i]=='*')
        {
            //open bracket
            isvalid |= solve(i+1,cnt+1,s);

            //nothing
            isvalid |= solve(i+1,cnt,s);

            //close bracket
            if(cnt>0)
            {
                isvalid |= solve(i+1,cnt-1,s);
            }
        }
        else if(cnt>0){
            isvalid=solve(i+1,cnt-1,s);
        }
        return t[i][cnt] = isvalid;
    }
    bool checkValidString(string s) {
        int i=0;
        int cnt=0;
        memset(t,-1,sizeof(t));
        return solve(i,cnt,s);
    }
};