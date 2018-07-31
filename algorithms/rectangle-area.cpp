class Solution
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        if (C <= E || F >= D || B >= H || A >= G)
            return area;

        int topX = min(G, C);
        int topY = min(H, D);
        int bottomX = max(E, A);
        int bottomY = max(B, F);
        return area - (topX - bottomX) * (topY - bottomY);

    }
};
