class Solution {
public:
    vector<string> ans;

    void solve(string digits, vector<string>& mp, int index, string temp) {

      
        if (index == digits.size()) {
  ans.push_back(temp);
            return;
        }

        
        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {
    solve(digits, mp, index + 1, temp + ch);
        }
    }

    vector<string> letterCombinations(string digits) {

  if (digits.empty())
      return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(digits, mp, 0, "");

        return ans;
    }
};