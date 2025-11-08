#include <vector>
using namespace std;

class Solution {
private:
    int merge(vector<int>& nums, int l, int m, int r) {
        int count = 0;
        int k = m + 1;

        for(int i = l; i <= m; i++){
            while(k <= r && (long)nums[i] > 2 * (long long)nums[k]){
                k++;
            }

            count += (k - (m + 1));
        }

        vector<int> temp;
        int left = l, right = m + 1;

        while(left <= m && right <= r){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        
        while(left <= m) {
            temp.push_back(nums[left++]);
        }
        
        while(right <= r) { 
            temp.push_back(nums[right++]);
        }
        
        for(int i = l; i <= r; i++) {
            nums[i] = temp[i - l];
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) return 0;

        int m = l + (r - l) / 2;
        int reverse_pairs = 0;

        reverse_pairs += mergeSort(nums, l, m);
        reverse_pairs += mergeSort(nums, m + 1, r);
        reverse_pairs += merge(nums, l, m, r);

        return reverse_pairs;
    }

public:
    int reversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;

        return mergeSort(nums, 0, nums.size() - 1);
    }
};