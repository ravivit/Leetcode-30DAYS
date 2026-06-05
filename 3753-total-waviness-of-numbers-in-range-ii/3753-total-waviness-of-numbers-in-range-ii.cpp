class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;

    Node memo[20][11][11][2];
    bool vis[20][11][11][2];

    Node dfs(int pos, int p1, int p2, bool started, bool tight) {
        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][p1][p2][started]) {
            return memo[pos][p1][p2][started];
        }

        int limit = tight ? s[pos] - '0' : 9;

        Node ans{0, 0};

        for (int d = 0; d <= limit; d++) {

            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node cur = dfs(pos + 1, 10, 10, false, ntight);

                ans.cnt += cur.cnt;
                ans.wav += cur.wav;
                continue;
            }

            if (!started) {
                Node cur = dfs(pos + 1, d, 10, true, ntight);

                ans.cnt += cur.cnt;
                ans.wav += cur.wav;
            } else {

                int add = 0;

                if (p2 != 10) {
                    if ((p1 > p2 && p1 > d) ||
                        (p1 < p2 && p1 < d))
                        add = 1;
                }

                Node cur = dfs(pos + 1, d, p1, true, ntight);

                ans.cnt += cur.cnt;
                ans.wav += cur.wav + 1LL * add * cur.cnt;
            }
        }

        if (!tight) {
            vis[pos][p1][p2][started] = true;
            memo[pos][p1][p2][started] = ans;
        }

        return ans;
    }

    long long calc(long long x) {
        if (x < 0) return 0;

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, false, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};