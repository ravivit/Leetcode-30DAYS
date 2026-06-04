class Solution {
public:
    int waviness(int num) {
        string s = to_string(num);

        if (s.size() < 3) return 0;

        int cnt = 0;

        for (int i = 1; i < s.size() - 1; i++) {
            if (s[i] > s[i - 1] && s[i] > s[i + 1])
                cnt++;
            else if (s[i] < s[i - 1] && s[i] < s[i + 1])
                cnt++;
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int x = num1; x <= num2; x++) {
            ans += waviness(x);
        }

        return ans;
    }
};