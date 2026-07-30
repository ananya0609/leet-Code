class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int target, int index, vector<int>& arr) {

 if (target == 0) {
 ans.push_back(arr);
 return;
        }

 for (int i = index; i < nums.size(); i++) {

            // Skip duplicates
if (i > index && nums[i] == nums[i - 1])
 continue;

            // Stop if target becomes smaller
            if (nums[i] > target)
                break;

            arr.push_back(nums[i]);

            solve(nums, target - nums[i], i + 1, arr);

            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> arr;
        solve(candidates, target, 0, arr);

        return ans;
    }
};