class Solution
{
public:
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for (int left = 0, right = static_cast<int>(s.size() - 1); left < right; left++, right--) {
            while (!isalnum(s[left])) {
                left++;
            }

            while (!isalnum(s[right])) {
                right--;
            }

            if (s[left] != s[right] && left < right) {
                return false;
            }
        }
        return true;
    }
};

