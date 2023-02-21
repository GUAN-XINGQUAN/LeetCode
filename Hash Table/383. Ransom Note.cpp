class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> char2Count;
        for (int i = 0; i < magazine.size(); i++)
            ++char2Count[magazine[i]];
        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (char2Count.count(ransomNote[i]) == 0 || char2Count[ransomNote[i]] <= 0)
                return false;
            char2Count[ransomNote[i]] -= 1;
        }
        return true;
    }
};


/*
m: a    b
char2Count:
    a -> 1
    b -> 1

i = 0
r[i] = a

*/