class Solution {
    int partition(vector<vector<int>>& points, int left, int right){
        int pivot = --right;
        int distance = points[pivot][0]*points[pivot][0] + points[pivot][1]*points[pivot][1];
        while (true){
            while (points[left][0]*points[left][0] + points[left][1]*points[left][1] < distance) left++;
            while (left < right && points[right-1][0]*points[right-1][0] + points[right-1][1]*points[right-1][1] >= distance) right--;
            if (left >= right) break;
            swap(points[left], points[right-1]);
        }
        swap(points[left], points[pivot]);
        return left;
    }
    
    void quickSelect(vector<vector<int>>& points, int left, int right, int k){
        if (left >= right - 1) return;
        int pivot = partition(points, left, right);
        if (pivot == k) return;
        if (pivot > k) quickSelect(points, left, pivot, k);
        quickSelect(points, pivot+1, right, k);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(points, 0, points.size(), k-1);
        vector<vector<int>> ans(k);
        copy(points.begin(), points.begin() + k, ans.begin());
        return ans;
    }
};
