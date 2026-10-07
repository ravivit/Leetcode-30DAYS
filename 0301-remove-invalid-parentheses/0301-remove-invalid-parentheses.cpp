class Solution {
public:
    unordered_set<string> st;

    void solve(string &s, int i, int left, int right,
               int remL, int remR, string cur) {

        if (i == s.size()) {
            if (left == right && remL == 0 && remR == 0)
                st.insert(cur);
            return;
        }

        if (s[i] == '(') {

            // Remove
            if (remL > 0)
                solve(s, i + 1, left, right,
                      remL - 1, remR, cur);

            // Keep
            solve(s, i + 1, left + 1, right,
                  remL, remR, cur + '(');
        }

        else if (s[i] == ')') {

            // Remove
            if (remR > 0)
                solve(s, i + 1, left, right,
                      remL, remR - 1, cur);

            // Keep
            if (left > right)
                solve(s, i + 1, left, right + 1,
                      remL, remR, cur + ')');
        }

        else {
            solve(s, i + 1, left, right,
                  remL, remR, cur + s[i]);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int balance = 0;
        int remL = 0;
        int remR = 0;

        // Find minimum removals
        for (char c : s) {
            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                if (balance > 0)
                    balance--;
                else
                    remR++;
            }
        }

        remL = balance;

        st.clear();

        solve(s, 0, 0, 0, remL, remR, "");

        return vector<string>(st.begin(), st.end());
    }
};