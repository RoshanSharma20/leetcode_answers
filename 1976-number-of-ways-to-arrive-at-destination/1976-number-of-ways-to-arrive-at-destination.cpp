class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        long long int mod = 1e9 + 7;
        vector<pair<long long int,long long int>> adj[n];
        for(int i=0;i<roads.size();++i)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        vector<long long int> distance(n,LONG_MAX);
        distance[0]=0;
        vector<int> ways(n,0);
        ways[0]=1;
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>> nodes;
        nodes.push({0,0});
        while(!nodes.empty())
        {
            auto it = nodes.top();
            nodes.pop();
            long long int dis = it.first;
            long long int node = it.second;
            for(auto adjnode : adj[node])
            {
                long long int edgenode = adjnode.first;
                long long int edgewt = adjnode.second;
                if(dis + edgewt < distance[edgenode])
                {
                    distance[edgenode] = dis + edgewt;
                    nodes.push({dis+edgewt,edgenode});
                    ways[edgenode]=ways[node];
                }
                else if(dis+edgewt==distance[edgenode])
                {
                    ways[edgenode]=(ways[edgenode]+ ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};