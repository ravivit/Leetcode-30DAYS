class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        long long sum = 0;
        long long ans = 0;

        int low = 0;

        for (int high = 0; high < n; high++) {
            // add current element
            sum += nums[high];
            mp[nums[high]]++;

            // window size > k ho gaya to left se hatao
            if (high - low + 1 > k) {
                sum -= nums[low];
                mp[nums[low]]--;

                if (mp[nums[low]] == 0) {
                    mp.erase(nums[low]);
                }
                low++;
            }

            // jab window size exactly k ho
            if (high - low + 1 == k) {
                if (mp.size() == k) {   // all distinct
                    ans = max(ans, sum);
                }
            }
        }

        return ans;
    }
};