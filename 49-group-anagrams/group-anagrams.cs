public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        Dictionary<string, List<string>> mp = new Dictionary<string, List<string>>();

        foreach (string s in strs) {
            char[] arr = s.ToCharArray();
            Array.Sort(arr);
            string key = new string(arr);

            if (!mp.ContainsKey(key)) {
                mp[key] = new List<string>();
            }
            mp[key].Add(s);
        }

        List<IList<string>> ans = new List<IList<string>>();
        foreach (var it in mp) {
            ans.Add(it.Value);
        }

        return ans;

    }
}