class Solution
{
public:
    vector<string> findWords(vector<string>& words)
    {
        if (words.empty()) return {};

        vector<string> res;
        map<char, int> keyboard = {
            {'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1}, {'y', 1}, {'u', 1}, {'i', 1}, {'o', 1}, {'p', 1},
            {'a', 2}, {'s', 2}, {'d', 2}, {'f', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2},
            {'l', 2}, {'z', 3}, {'x', 3}, {'c', 3}, {'v', 3}, {'b', 3}, {'n', 3}, {'m', 3}
        };

        for (auto word : words) {
            string tmp = word;
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            bool flag = true;
            int row = keyboard[word[0]];
            for (int i = 1; i < word.length(); i++) {
            if (keyboard[word[i]] != row) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(tmp);
        }
        return res;
    }
};
