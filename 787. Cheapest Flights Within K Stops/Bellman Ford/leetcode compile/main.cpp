class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distRecord(n, INT_MAX);         // minimun distance to each node (node, min distance)
    
    distRecord[src] = 0;

    for(int i = 0 ; i <= k ; i++)
    {
        vector<int> tmp(distRecord);    // to copy the distRecord

        for(auto& p : flights)
        {
            if(distRecord[p[0]] != INT_MAX)
            {
                tmp[p[1]] = min(distRecord[p[0]]+p[2], tmp[p[1]]);  // use this net or the prev added weight
            }
        }

        distRecord = tmp;
    }

    return distRecord[dst] == INT_MAX? -1 : distRecord[dst];
    }
};
