class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(n + 1, 0);

        for (int num : arr) {
            count[min(num, n)]++;
        }

        int prev = 1;
        for (int num = 2; num <= n; num++) {
            prev = min(prev + count[num], num);
        }

        return prev;
    }
};