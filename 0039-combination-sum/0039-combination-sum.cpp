class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target, vector<int>& temp, int index) {

        // Found a valid combination
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // Target exceeded
        if (target < 0)
            return;

        for (int i = index; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);          // Choose

            solve(candidates, target - candidates[i], temp, i);
            // i because we can reuse the same element

            temp.pop_back();                        // Backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, target, temp, 0);
        return ans;
    }
};