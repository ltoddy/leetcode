class Solution
{
private:
    bool is_capitalize(string word)
    {

        if (!isupper(word[0])) return false;

        for (int i = 1; i < word.size(); i++) {
            if (!islower(word[i]))
                return false;
        }
        return true;
    }

    bool is_upper(string word)
    {
        for (char c : word) {
            if (!isupper(c))
                return false;
        }
        return true;
    }

    bool is_lower(string word)
    {
        for (char c : word) {
            if (!islower(c))
                return false;
        }
        return true;
    }

public:
    bool detectCapitalUse(string word)
    {
        if (word.empty()) return false;
        return is_capitalize(word) || is_upper(word) || is_lower(word);
    }
};
