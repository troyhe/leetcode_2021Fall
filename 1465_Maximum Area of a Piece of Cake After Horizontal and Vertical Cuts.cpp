class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxWidth = verticalCuts[0];
        for (int i = 1; i < verticalCuts.size(); i++){
            maxWidth = max(maxWidth, verticalCuts[i] - verticalCuts[i-1]);
        }
        maxWidth = max(maxWidth, w - verticalCuts[verticalCuts.size()-1]);
        
        int maxHeight = horizontalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); i++){
            maxHeight = max(maxHeight, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        maxHeight = max(maxHeight, h - horizontalCuts[horizontalCuts.size()-1]);
        const int modulos = 1e9 + 7;
        maxWidth = maxWidth % modulos;
        maxHeight = maxHeight % modulos;
        long product = (long) maxWidth * (long) maxHeight % modulos;
        return product;
    }
};
