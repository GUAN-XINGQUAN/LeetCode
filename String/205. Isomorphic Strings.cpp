class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> s2t, t2s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s2t.count(s[i]) == 0)
            {
                if (t2s.count(t[i]) != 0)
                    return false;
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            }
            else
            {
                if (t[i] != s2t[s[i]])
                    return false;
            }
        }
        return true;
    }
};


/*
    e   g   f

    a   d   d


    e->a
    g->d
    f->d

*/