class Solution {
    static constexpr long long INF = (1LL << 60);

    struct TrieNode {
        int id = -1;
        unordered_map<char, TrieNode*> next;
    };

    TrieNode* root = new TrieNode();

    void insert(const string& s, int id) {
        TrieNode* cur = root;
        for (char c : s) {
            if (!cur->next.count(c))
                cur->next[c] = new TrieNode();
            cur = cur->next[c];
        }
        cur->id = id;
    }

public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        unordered_map<string,int> id;
        int idx = 0;

        for (auto &s: original)
            if (!id.count(s))
                id[s] = idx++;

        for (auto &s: changed)
            if (!id.count(s))
                id[s] = idx++;

        int m = idx;

        vector<vector<long long>> dist(m,
            vector<long long>(m, INF));

        for (int i=0;i<m;i++)
            dist[i][i]=0;

        for (int i=0;i<original.size();i++) {
            int u=id[original[i]];
            int v=id[changed[i]];
            dist[u][v]=min(dist[u][v],
                           (long long)cost[i]);
        }

        for(int k=0;k<m;k++)
            for(int i=0;i<m;i++)
                for(int j=0;j<m;j++)
                    if(dist[i][k]!=INF &&
                       dist[k][j]!=INF)
                        dist[i][j]=min(dist[i][j],
                                       dist[i][k]+dist[k][j]);

        for(auto &p:id)
            insert(p.first,p.second);

        int n=source.size();
        vector<long long> dp(n+1,INF);
        dp[n]=0;

        for(int i=n-1;i>=0;i--){

            if(source[i]==target[i])
                dp[i]=dp[i+1];

            TrieNode* s=root;
            TrieNode* t=root;

            for(int j=i;j<n;j++){

                if(!s->next.count(source[j]))
                    break;

                if(!t->next.count(target[j]))
                    break;

                s=s->next[source[j]];
                t=t->next[target[j]];

                if(s->id!=-1 &&
                   t->id!=-1 &&
                   dist[s->id][t->id]!=INF &&
                   dp[j+1]!=INF){

                    dp[i]=min(dp[i],
                              dist[s->id][t->id]
                              +dp[j+1]);
                }
            }
        }

        return dp[0]==INF?-1:dp[0];
    }
};