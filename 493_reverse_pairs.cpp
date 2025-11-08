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

public:
    int reversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;

        return mergeSort(nums, 0, nums.size() - 1);
    }
};