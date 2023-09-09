class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> char2Count;
        for (int i = 0; i < secret.size(); i++)
            ++char2Count[secret[i]];
        for (int i = 0; i < guess.size(); i++)
        {
            // if guess character is not in the secret: let it go
            if (char2Count.count(guess[i]) == 0)
                continue;
            // current char matches
            if (guess[i] == secret[i])
            {
                bulls++;
                if (char2Count[guess[i]] <= 0)
                    cows--;
            }
            else
            {
                if (char2Count[guess[i]] > 0)
                    cows++;
            }
            char2Count[guess[i]]--;
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};