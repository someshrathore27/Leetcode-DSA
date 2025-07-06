class Solution {
public:
    unordered_map<int, set<int>> adj;              
    unordered_map<int, bool> status;              
    unordered_map<int, int> stationMap;           
    unordered_map<int, set<int>> componentActive; 

    void addEdge(int u, int v) {
        adj[u].insert(v);
        adj[v].insert(u);
    }

    void buildComponents(int c) {
        unordered_set<int> visited;
        int componentId = 0;

        for (int i = 1; i <= c; ++i) {
            if (visited.count(i)) continue;

            queue<int> q;
            q.push(i);
            visited.insert(i);
            componentActive[componentId] = set<int>();

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                stationMap[node] = componentId;
                componentActive[componentId].insert(node);
                status[node] = true;

                for (int neighbor : adj[node]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }

            componentId++;
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        for (auto& conn : connections) {
            addEdge(conn[0], conn[1]);
        }

        buildComponents(c);

        vector<int> ans;

        for (auto& query : queries) {
            int type = query[0];
            int node = query[1];

            int componentId = stationMap[node];

            if (type == 1) {
                if (status[node]) {
                    ans.push_back(node);
                } else {
                    if (!componentActive[componentId].empty()) {
                        ans.push_back(*componentActive[componentId].begin());
                    } else {
                        ans.push_back(-1);
                    }
                }
            } else if (type == 2) {
                status[node] = false;
                componentActive[componentId].erase(node);
            }
        }

        return ans;
    }
};
