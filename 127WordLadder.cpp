#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

// #include "NestedVectorIntVisualization.h"

using namespace std;

// BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Put all words into a set
        unordered_set<string> wordSet{ wordList.begin(), wordList.end() };
        // Edge case ==> wordList does not have the endWord.
        if (wordSet.count(endWord) == 0)
            return 0;
        int count = 0;
        queue<string> wordQueue({ beginWord });
        while (!wordQueue.empty())
        {
            for (int i = wordQueue.size(); i > 0; i--)
            {
                string word = wordQueue.front();
                wordQueue.pop();
                if (word == endWord)
                    return count+1;
                for (int j = 0; j < word.size(); j++)
                {
                    string newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        newWord[j] = ch;
                        if (wordSet.count(newWord) != 0 && newWord != word)
                        {
                            wordQueue.push(newWord);
                            wordSet.erase(newWord);
                        }
                    }
                }
            }
            count++;
        }
        return 0;
    }
};

int main()
{
    // case 1
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "cot", "cog"};

    // case 2
    string beginWord2 = "aaa", endWord2 = "cog";
    vector<string> wordList2 = { "hot", "cot", "cog" };

    // case 3
    string beginWord3 = "hit", endWord3 = "cog";
    vector<string> wordList3 = { "hot","dot","dog","lot","log","cog" };

    Solution sol;

    int res = sol.ladderLength(beginWord3, endWord3, wordList3);

    cout << res << endl;
}
