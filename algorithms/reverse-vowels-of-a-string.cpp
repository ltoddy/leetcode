class Solution {
public:
    string reverseVowels(string s)
    {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<int> pos;
        for (int i = 0; i < s.length(); i++) {
            if (vowels.count(s[i]))
                pos.push_back(i);
        }
        for (int i = 0; i < pos.size() / 2; i++) {
            swap(s[pos[i]], s[pos[pos.size() - i - 1]]);
        }
        return s;
    }
};
