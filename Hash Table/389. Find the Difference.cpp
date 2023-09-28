/*
Approach #1:
1. Sort both strings s and t;
2. Use two pointers that point to the beginning of each string
3. Move two pointers with same pace:
   If any character from two strings are different: return that character from t.

Approach #2:
1. Count the characters and corresponding frequency in string s using a hashtable.
2. Loop through each character in t:
   For each character, reduce the frequency by 1 in the hashtable.
   When the frequency goes below zero OR the character does not exist in the hashtable, that is the answer we are looking for.
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> charFrequency;
        for (int i = 0; i < s.size(); i++)
            ++charFrequency[s[i]];
        for (int i = 0; i < t.size(); i++)
        {
            if (charFrequency.count(t[i]) == 0 || charFrequency[t[i]] <= 0)
                return t[i];
            --charFrequency[t[i]];
        }
        return ' ';
    }
};