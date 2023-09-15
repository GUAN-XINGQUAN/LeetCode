/*
Use BFS to solve the problem.
1. Start with the beginWord
2. For each character in the beginWord: change that to other 25 characters
3. Keep doing so until (a) we reach the endWord OR (b) we enumerate all possible cases and cannot reach endWord
    
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet {wordList.begin(), wordList.end()};
        // endWord is not in the dictionary
        if (wordSet.count(endWord) == 0)
            return 0;
        // general case
        queue<string> wordQueue ({beginWord});
        int result = 1;
        while(!wordQueue.empty())
        {
            int size = wordQueue.size();
            for (int i = 0; i < size; i++)
            {
                string cur = wordQueue.front();
                wordQueue.pop();
                if (cur == endWord)
                    return result;
                // we can possible change each character in this string
                for (int j = 0; j < cur.size(); j++)
                {
                    // we can change each character to other 25 characters
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        // there is one case that we use the same character to replace itself
                        if (ch == cur[j])
                            continue;
                        string newCur = cur;
                        newCur[j] = ch;
                        if (wordSet.count(newCur) != 0)
                        {    
                            wordQueue.push(newCur);
                            wordSet.erase(newCur);
                        }
                    }
                }
            }
            result++;
        }
        return 0;
    }
};