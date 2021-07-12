class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        int idx1 = 0;
        int idx2 = 0;
        int idx3 = 0;
        while (idx1 < arr1.size() && idx2 < arr2.size() && idx3 < arr3.size()){
            if (arr1[idx1] == arr2[idx2] && arr2[idx2] == arr3[idx3]){
                ans.push_back(arr1[idx1]);
                idx1++;
                idx2++;
                idx3++;
            } else if (arr1[idx1] <= arr2[idx2] && arr1[idx1] <= arr3[idx3]){
                idx1++;
            } else if (arr2[idx2] <= arr1[idx1] && arr2[idx2] <= arr3[idx3]){
                idx2++;
            } else if (arr3[idx3] <= arr2[idx2] && arr3[idx3] <= arr1[idx1]){
                idx3++;
            }
        }
        return ans;
    }
};
