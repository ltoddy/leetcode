class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> ransom_cnt, magazine_cnt;
        for (auto m : magazine) magazine_cnt[m] += 1;

        for (auto r : ransomNote) {
            magazine_cnt[r] -= 1;
            if (magazine_cnt[r] < 0) return false;
        }
        return true;
    }
};
