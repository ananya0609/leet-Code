class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        if (k < 0)
            return 0;

        int left = 0;
        int odd = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] % 2 == 1)
                odd++;

            while (odd > k) {
                if (nums[left] % 2 == 1)
                    odd--;

                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};