#include <vector>
#include <iostream>
using namespace std;

class Solution {
    using Item = pair<int, int>;

    void mergeSort(vector<Item>& vec, int l, int r, vector<int>& counts) {
        if (l >= r) {
            return;
        }
        int mid = l + (r - l) / 2;
        mergeSort(vec, l, mid, counts); 
        mergeSort(vec, mid + 1, r, counts);
        merge(vec, l, mid, r, counts); 
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        vector<int> counts(n, 0);
        vector<Item> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = make_pair(nums[i], i);
        }
        mergeSort(vec, 0, n - 1, counts);
        return counts;
    }
};
