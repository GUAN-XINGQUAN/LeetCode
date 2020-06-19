#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>

#include "NestedVectorVisualization.h"

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0)
            return 0;
        queue<string> wordQueue({ beginWord });
        int res = 0;
        while (!wordQueue.empty())
        {
            for (int i = wordQueue.size(); i > 0; i--)
            {
                string word = wordQueue.front();
                wordQueue.pop();
                if (word == endWord)
                    return res+1;
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
            res++;
        }
        return 0;
    }
};

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };

    Solution sol;
    int len = sol.ladderLength(beginWord, endWord, wordList);

    cout << len;
}