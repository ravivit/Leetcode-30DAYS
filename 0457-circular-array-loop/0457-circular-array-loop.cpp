class Solution {
public:

    int getNext(vector<int>& nums, int curr) {

        int n = nums.size();

        return ((curr + nums[curr]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            bool forward = nums[i] > 0;

            int slow = i;
            int fast = i;

            while(true) {

                // move slow one step
                int nextSlow = getNext(nums, slow);

                // direction check
                if((nums[nextSlow] > 0) != forward)
                    break;

                // move fast first step
                int nextFast = getNext(nums, fast);

                if((nums[nextFast] > 0) != forward)
                    break;

                // move fast second step
                nextFast = getNext(nums, nextFast);

                if((nums[nextFast] > 0) != forward)
                    break;

                slow = nextSlow;
                fast = nextFast;

                // cycle found
                if(slow == fast) {

                    // self loop check
                    if(slow == getNext(nums, slow))
                        break;

                    return true;
                }
            }
        }

        return false;
    }
};