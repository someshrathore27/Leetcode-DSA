using System;
using System.Collections.Generic;

public class Solution {
    public string ReverseWords(string s) {
        s = s.Trim();
        List<string> words = new List<string>();
        int i = 0;

        while (i < s.Length) {
            while (i < s.Length && s[i] == ' ') i++; 

            if (i >= s.Length) break;

            int start = i;
            while (i < s.Length && s[i] != ' ') i++; 

            words.Add(s.Substring(start, i - start));
        }

        words.Reverse();
        return string.Join(" ", words);
    }
}
