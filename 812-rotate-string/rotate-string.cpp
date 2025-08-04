class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
        {
            return false;
        }
        for(int i=0;i<s.length();i++)
        {
            string temp=s.substr(i,s.length());
            string t=temp+(s.substr(0,i));
            if(temp==goal || t==goal)
            {
                return true;
            }
        }
        return false;
    }
};