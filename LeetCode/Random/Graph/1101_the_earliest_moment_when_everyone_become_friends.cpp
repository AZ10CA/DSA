class DisjointSet {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    // Constructor to initialize the disjoint set
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // Each element is its own parent initially
        }
    }

    // Find function with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union function with union by rank
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX; // Attach smaller tree under the larger tree
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY; // Attach smaller tree under the larger tree
            } else {
                parent[rootY] = rootX; // Arbitrarily choose one as root
                rank[rootX]++;        // Increase the rank of the new root
            }
        }
    }

    // Helper function to check if two elements are in the same set
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    bool is_connected(){
        int root = find(parent[0]);
        for(auto each: parent){
            if(find(each) != root)
                return false;
        }
        return true;
    }
};


class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        // Time: O(nlogn + mlog * alpha(n) + n), Space: O(n)
        std::sort(logs.begin(), logs.end());
        DisjointSet dj(n);
        for(auto log: logs){
            auto from = log[1], to = log[2];
            dj.unionSet(from, to);
            if(dj.is_connected())
                return log[0];
        }

        return -1;
    }
};