class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        stack<int>openst;
        stack<int>asterisk;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                openst.push(i);
            }
            else if(s[i]=='*')
            {
                asterisk.push(i);
            }
            else{
                if(!openst.empty())
                {
                    openst.pop();
                }
                else if(!asterisk.empty())
                {
                    asterisk.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!openst.empty() && !asterisk.empty())
        {
            if(openst.top() > asterisk.top())
            {
                return false;
            }
            openst.pop();
            asterisk.pop();
        }
        return openst.empty();
    }
};