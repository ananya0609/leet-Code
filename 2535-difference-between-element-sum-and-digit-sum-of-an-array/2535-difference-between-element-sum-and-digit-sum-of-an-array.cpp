class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0;
        int digitSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            elementSum += nums[i];

            int x = nums[i];

            while (x > 0) {
                digitSum += x % 10;
                x = x / 10;
            }
        }

        return abs(elementSum - digitSum);
    }
};