class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> str2Count;
        for (int i = 0; i < s.size(); i++)
            ++str2Count[s[i]];
        for (int i = 0; i < s.size(); i++)
        {
            if (str2Count[s[i]] == 1)
                return i;
        }
        return -1;
    }
};


/*
    0   1   2   3   4   5   6   7   8
    a   b   c   d   e   f   a   b   c

    a -> 2
    b -> 2
    c -> 2
    d -> 1
    e -> 1
    f -> 1


    a -> 6
    b -> 7
    c -> 8
    d -> 3
    e -> 4
    f -> 5

    return d
*/