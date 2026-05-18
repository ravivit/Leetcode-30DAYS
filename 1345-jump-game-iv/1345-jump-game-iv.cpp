class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if(n == 1)
            return 0;

        // value -> all indices
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }

        queue<pair<int,int>> q;

        vector<int> visited(n, 0);

        q.push({0, 0});

        visited[0] = 1;

        while(!q.empty())
        {
            auto [idx, steps] = q.front();
            q.pop();

            // reached end
            if(idx == n - 1)
                return steps;

            // i - 1
            if(idx - 1 >= 0 && !visited[idx - 1])
            {
                visited[idx - 1] = 1;
                q.push({idx - 1, steps + 1});
            }

            // i + 1
            if(idx + 1 < n && !visited[idx + 1])
            {
                visited[idx + 1] = 1;
                q.push({idx + 1, steps + 1});
            }

            // same value jumps
            for(auto nextIdx : mp[arr[idx]])
            {
                if(!visited[nextIdx])
                {
                    visited[nextIdx] = 1;
                    q.push({nextIdx, steps + 1});
                }
            }

            // IMPORTANT OPTIMIZATION
            mp[arr[idx]].clear();
        }

        return -1;
    }
};