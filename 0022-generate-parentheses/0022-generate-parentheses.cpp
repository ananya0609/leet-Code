class Solution {
public:
    vector<string> ans;

    void solve(string s, int open, int close, int n) {

        // If the string has 2*n characters, it is complete
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add '(' if we still have opening brackets left
        if (open < n) {
            solve(s + "(", open + 1, close, n);
        }

        // Add ')' only if it keeps the string valid
        if (close < open) {
            solve(s + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return ans;
    }
};