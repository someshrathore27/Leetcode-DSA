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
        for (int i = 0; i < s.size(); i++) 
        {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') 
            {
                st.push(c);
            } 
            else 
            {
                if (st.empty() || !match(st.top(), c)) 
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
