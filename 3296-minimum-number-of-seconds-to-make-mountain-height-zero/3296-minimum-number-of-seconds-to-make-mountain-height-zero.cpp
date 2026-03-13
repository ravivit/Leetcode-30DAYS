class Solution {
public:
    bool can(long long time, int H, vector<int>& wt) {
        long long total = 0;

        for(long long t : wt) {
            long long l = 0, r = 1e6;

            while(l <= r) {
                long long m = (l + r) / 2;
                long long need = t * m * (m + 1) / 2;

                if(need <= time) l = m + 1;
                else r = m - 1;
            }

            total += r;
            if(total >= H) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int H, vector<int>& workerTimes) {
        long long l = 0, r = 1e18;
        long long ans = r;

        while(l <= r) {
            long long mid = (l + r) / 2;

            if(can(mid, H, workerTimes)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};