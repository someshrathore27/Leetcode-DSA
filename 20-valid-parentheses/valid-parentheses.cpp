class Solution {
public:
    bool match(char open, char close) {
        return (open == '(' && close == ')') || 
               (open == '[' && close == ']') || 
               (open == '{' && close == '}');
    }

    bool isValid(string s)
    {
        stack<char> st;
        for(auto ch:s)
        {
            if(ch=='[' || ch=='{' || ch=='(')
            {
                st.push(ch);
            }
            else{
                if(st.empty() ||!match(st.top(),ch))
                {
                    return false;
                }
                st.pop();
            }
        }
        if(!st.empty())
        {
            return false;
        }
        return true;
    }
};
