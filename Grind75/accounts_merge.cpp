class UnionFind {
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unionSet(int x, int y){
        int root_x = find(x), root_y = find(y);

        if(root_x == root_y)
            return;

        if(rank[root_x] == rank[root_y]){
            parent[root_x] = root_y;
            rank[root_y]++;
        } else if(rank[root_x] < rank[root_y])
            parent[root_x] = root_y;
        else
            parent[root_y] = root_x;
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }

    unordered_map<int, vector<int>> fetch_groups(){
        unordered_map<int, vector<int>> groups;
        for(int i = 0; i < parent.size(); i++)
            groups[find(i)].push_back(i);

        return groups;
    }

};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int idx = 0;

        unordered_map<string, string> mail_to_name;
        unordered_map<string, int> mail_to_idx;
        unordered_map<int, string> idx_to_mail;


        // Phase 1: convert accounts to unordered_map, this represents the relationship between the account name and emails much better
        for(auto& acc: accounts){
            string name = acc[0];
            for(int i = 1; i < acc.size(); i++){
                if(mail_to_idx.find(acc[i]) == mail_to_idx.end()){
                    mail_to_name[acc[i]] = name;
                    mail_to_idx[acc[i]] = idx;
                    idx_to_mail[idx] = acc[i];
                    idx++;
                }
            }
        }

        // Phase 2: set up UnionFind and merge the emails
        UnionFind ds(idx);
        for(auto& acc: accounts){
            auto& first_email = mail_to_idx[acc[1]];
            for(int i = 2; i < acc.size(); i++)
                ds.unionSet(first_email, mail_to_idx[acc[i]]);
        }

        // Phase 3: fetch groups from UnionFind and prepare results
        unordered_map<int, vector<int>> groups = ds.fetch_groups();
        vector<vector<string>> result;

        for(auto&[parent, children]: groups){
            string account_name = mail_to_name[idx_to_mail[parent]];
            vector<string> emails;
            for(auto child: children)
                emails.push_back(idx_to_mail[child]);

            std::sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), account_name);

            result.push_back(emails);
        }

        return result;
    }
};