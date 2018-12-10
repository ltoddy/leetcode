class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K)
    {
        int result = 0;
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 1; i < N; i++) {
            for (auto time : times) {
                int u = time[0], v = time[1], w = time[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            result = max(result, dist[i]);
        }
        return result == INT_MAX ? -1 : result;
    }
};
