class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>> > dist(n);    // dist[src] -> (dst, distance)
    vector<int> distRecord(n, INT_MAX);         // minimun distance to each node (node, min distance)
    queue<pair<int, int>> Q;                    // to record the BFS process
    int stop = 0;                               // the number of stops

    // To construct the dist
    for(auto &p :flights)
    {
        dist[p[0]].emplace_back(make_pair(p[1],p[2]));
    }

    // To do BFS
    Q.push(make_pair(src, 0));

    while( stop <= k && !Q.empty() )
    {
        int qSize = Q.size();

        while(qSize--)  // if qSize == 0 ,then jump out the loop
        {
            auto [node, minDist] = Q.front(); // only for c++17 up
            Q.pop();

            for(auto &[neighbor, cost] : dist[node])
            {
                if(minDist+cost < distRecord[neighbor])
                {
                    distRecord[neighbor] = minDist+cost;
                    Q.push({neighbor, distRecord[neighbor]});
                }
            }
        }
        stop++;
    }

    return distRecord[dst] == INT_MAX? -1 : distRecord[dst];
    }
};
