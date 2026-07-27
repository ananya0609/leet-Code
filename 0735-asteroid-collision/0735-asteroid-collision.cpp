class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
  stack<int> st;

 for (int a : asteroids) {

  while (!st.empty() && st.top() > 0 && a < 0) {

      if (abs(st.top()) < abs(a)) {
       st.pop();
                }
          else if (abs(st.top()) == abs(a)) {
   st.pop();
           a = 0;
                }
      else {
     a = 0;
                }
            }

      if (a != 0)
                st.push(a);
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};