class Table {
    int row_generator = 1;
    unordered_map<int, vector<string>> data;

public:
    void insert(vector<string> row){
        auto id = row_generator++;
        data[id] = std::move(row);
    }

    void erase(int row_id){
        data.erase(row_id);
    }

    string getValue(int row, int col){
        return data[row][col - 1];
    }
};

class SQL {
    unordered_map<string, Table> tables;
public:
    SQL(vector<string>& names, vector<int>& columns) {
        for(int i = 0; i < names.size(); i++)
            tables[names[i]] = Table();
    }

    void insertRow(string name, vector<string> row) {
        auto& table = tables[name];
        table.insert(row);
    }

    void deleteRow(string name, int rowId) {
        auto& table = tables[name];
        table.erase(rowId);
    }

    string selectCell(string name, int rowId, int columnId) {
        auto& table = tables[name];
        return table.getValue(rowId, columnId);
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */