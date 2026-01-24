public class Solution {
    public bool IsAnagram(string s1, string s2) {
        if(s1.Length!=s2.Length)return false;
        Dictionary<char,int>d=new Dictionary<char,int>();
        for(int i=0;i<s1.Length;i++)
        {
            if(d.ContainsKey(s1[i]))
            {
                d[s1[i]]++;
            }
            else{
                d[s1[i]]=1;
            }
        }
        for(int i=0;i<s2.Length;i++)
        {
            if(d.ContainsKey(s2[i]) && d[s2[i]]>=1)
            {
                d[s2[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
}