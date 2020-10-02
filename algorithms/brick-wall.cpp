class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int> m;
        for(auto v : wall){
            int sum = 0;
            for(int i=0;i<v.size()-1;i++){
                sum += v[i];
                m[sum]++;
            }
        }
        int mc=0;
        for(auto it : m){
            if(mc < it.second)
                mc = it.second;
        }
        return wall.size() - mc;
    }
};