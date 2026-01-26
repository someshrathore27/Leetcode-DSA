public class Solution {
    public string RemoveOccurrences(string s, string part) {
        while (true) {
            int idx = s.IndexOf(part);
            if (idx == -1) break;

            s = s.Remove(idx, part.Length);
        }
        return s;
    }
}
