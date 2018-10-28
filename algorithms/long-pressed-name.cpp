class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        if (name.length() > typed.length()) return false;
        if (name == typed) return true;

        int n_index = 0;
        for (int t_index = 0; t_index < typed.length(); t_index++) {
            if (n_index < name.length() && typed[t_index] == name[n_index]) n_index++;
            else if (t_index == 0 || typed[t_index] != typed[t_index - 1]) return false;
        }
        return n_index == name.length();
    }
};
