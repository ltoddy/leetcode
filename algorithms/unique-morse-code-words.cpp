class Solution
{
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        vector<string> morse = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
            "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
        };

        set<string> charset;
        for (auto word : words) {
            string tmp = "";
            for (auto c : word) tmp += morse[c - 'a'];
            charset.insert(tmp);
        }
        return charset.size();
    }
};
