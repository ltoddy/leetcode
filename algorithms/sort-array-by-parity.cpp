class Solution
{
private:
    bool even(int num)
    {
        return num % 2 == 0;
    }

public:
    vector<int> sortArrayByParity(vector<int>& A)
    {
        vector<int> evens;
        vector<int> odds;
        for (auto num : A) {
            if (this->even(num)) evens.push_back(num);
            else odds.push_back(num);
        }
        evens.insert(evens.end(), odds.begin(), odds.end());
        return evens;
    }
};
