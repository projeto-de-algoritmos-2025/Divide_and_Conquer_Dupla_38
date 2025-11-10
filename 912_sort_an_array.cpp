#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int left, int m, int right) {
        int k = m + 1;

        for(int i = left; i <= m; i++){
            while(k <= right && nums[i] > nums[k]){
                k++;
            }
        }

        vector<int> temp;
        int l = left; 
        int r = m + 1;

        while(l <= m && r <= right){
            if(nums[l] <= nums[r]){
                temp.push_back(nums[l++]);
            } else {
                temp.push_back(nums[r++]);
            }
        }

        while(l <= m) {
            temp.push_back(nums[l++]);
        }
        
        while(r <= right) { 
            temp.push_back(nums[r++]);
        }

        for(int i = left; i <= right; i++) {
            nums[i] = temp[i - left];
        }

    } 

    void mergeSort(vector<int>& nums, int left, int right) {
        if(left >= right) return;

        int m = left + (right - left) / 2;

        mergeSort(nums, left, m);
        mergeSort(nums, m + 1, right);
        merge(nums, left, m, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};