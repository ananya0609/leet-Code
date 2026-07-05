class Solution {
public:
    int countSubarrays(vector<int>& nums, int maxSum) {
        int count = 1;
        int sum = 0;

        for (int num : nums) {
            if (sum + num <= maxSum) {
                sum += num;
            } else {
                count++;
                sum = num;
            }
        }

        return count;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());

        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (countSubarrays(nums, mid) <= k)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};