#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "nestedVectorIntVisualization.h"
// #include "nestedVectorCharVisualization.h"
// #include "treeVisualizationinPreorder.h"
// #include "listNodeVisualization.h"


using namespace std;

// Brute force: time complexity: O(2^N), space complexity: O(2^N)
class Solution1 {
public:
    string findLongestWord(string s, vector<string>& d) {
        unordered_set<string> wordSet{ d.begin(), d.end() };
        vector<string> wordList;
        generateWords(s, "", wordList, 0);
        string res = "";
        for (string each : wordList)
        {
            if (wordSet.count(each) != 0)
            {
                if (each.size() > res.size() || (each.size() == res.size() && each[0] < res[0]))
                    res = each;
            }
        }
        return res;
    }
    // DFS
    void generateWords(string s, string newS, vector<string>& wordList, int i)
    {
        if (i == s.size())
            wordList.push_back(newS);
        else
        {
            generateWords(s, newS + s[i], wordList, i + 1);
            generateWords(s, newS, wordList, i + 1);
        }
    }
};


// Optimized approach: sort and matching
// Over-write the comparator for sort() function
bool compare(string a, string b)
{
    // Same length return with alphabetical order
    if (a.size() == b.size())
        return a < b;
    else
        // different length return longer string
        return a.size() > b.size();
}
class Solution2 {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), compare);
        for (string each : d)
        {
            int i = 0;
            for (char c : s)
            {
                if (i < each.size() && each[i] == c)
                    i++;
            }
            if (i == each.size())
                return each;
        }
        return "";
    }
};

// Optimized approch: matching without sorting
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for (string each : d)
        {
            int i = 0;
            // determine whether each is a subsequence of s.
            for (char ch : s)
            {
                if (ch == each[i])
                    i++;
            }
            if (i == each.size())
            {
                if (each.size() > res.size() || (each.size() == res.size() && each[0] < res[0]))
                    res = each;
            }
        }
        return res;
    }
};

int main()
{
    string s = "abpcplea";
    vector<string> dict = { "ale","apple","monkey","plea" };
    Solution sol;
    
    string res = sol.findLongestWord(s, dict);

    cout << res << endl;
}