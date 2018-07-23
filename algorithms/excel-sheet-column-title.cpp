class Solution
{
public:
    string convertToTitle(int n)
	{
        string res;
        while (n > 0) {
       		n--;
       		res = static_cast<char>('A' + (n % 26)) + res;
       		n /= 26;
		}
		return res;
    }
};

