class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int> path, int begin, int end) {
        path.push_back(begin);
        if (begin == end) {
            paths.push_back(path);
            return;
        } else {
            for (int node: graph[begin]) {
                dfs(graph, paths, path, node, end);
            }
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 0)
            return {};

        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, paths, path, 0, n - 1);
        return paths;
    }
};
