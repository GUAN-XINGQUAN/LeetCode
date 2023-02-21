class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> char2Freq;
        for (int i = 0; i < s.size(); i++)
            ++char2Freq[s[i]];
        for (int i = 0; i < t.size(); i++)
        {
            if (char2Freq.count(t[i]) == 0 || char2Freq[t[i]] <= 0)
                return false;
            --char2Freq[t[i]];
        }
        return true;
    }
};