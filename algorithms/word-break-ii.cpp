class Solution {
    unordered_map<string, vector<string>> dp;
public:
    vector<string> findAns(string s, vector<string>& dict) {
        if(s.empty()) return {""};
        if(dp.count(s))
            return dp[s];
        
        vector<string> recursiveSol, completeSol;
        for(string d : dict) {
           //first, check to which dict word does the begining of s matches to
           string gotit = s.substr(0, d.length());
            if(gotit != d)
                continue;
            //second, perform recursive approach on remaining string
            recursiveSol = findAns(s.substr(d.length()), dict);
            
            //third, combine the word with all possible solutions obtained after solving recursuvely
            for(string ans : recursiveSol) {
                string space = ans.length()==0?"":" ";
                completeSol.push_back(d + space + ans);
            }
        }
        //finally memoize and return result
        return dp[s] = completeSol;
    }
    vector<string> wordBreak(string s, vector<string>& dict) {
      return findAns(s, dict);  // We will solve this solution using simple recursion and memoization
    }
};