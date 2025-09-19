class Spreadsheet {
public:
    struct Cell {
        int row;
        int col;
    };
    vector<vector<int>> spreadsheet;
    vector<string> split(const string& s, const string& delimiter) {
        vector<string> tokens;
        size_t start = 0, end;
        while ((end = s.find(delimiter, start)) != string::npos) {
            tokens.push_back(s.substr(start, end - start));
            start = end + delimiter.length();
        }
        tokens.push_back(s.substr(start));
        return tokens;
    }
    Spreadsheet(int rows) {
        spreadsheet.resize(rows + 1, vector<int> (26, 0));
    }
    Cell getCellIndex(string& cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        return {row, col};
    }
    void setCell(string cell, int value) {
        Cell cell_idx = getCellIndex(cell);
        // cout<<cell_idx.row<<" "<<cell_idx.col<<endl;
        spreadsheet[cell_idx.row][cell_idx.col] = value;
    }
    
    void resetCell(string cell) {
        Cell cell_idx = getCellIndex(cell);
        // cout<<cell_idx.row<<" "<<cell_idx.col<<endl;
        spreadsheet[cell_idx.row][cell_idx.col] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        vector<string> parts = split(formula, "+");
        if(isalpha(parts[0][0]) && isalpha(parts[1][0])) {
            Cell first_cell_idx = getCellIndex(parts[0]);
            Cell second_cell_idx = getCellIndex(parts[1]);
            return spreadsheet[first_cell_idx.row][first_cell_idx.col] + spreadsheet[second_cell_idx.row][second_cell_idx.col];
        }
        else if(isalpha(parts[0][0])) {
            Cell cell_idx = getCellIndex(parts[0]);
            return spreadsheet[cell_idx.row][cell_idx.col] + stoi(parts[1]);
        }
        else if(isalpha(parts[1][0])) {
            Cell cell_idx = getCellIndex(parts[1]);
            // cout<<cell_idx.row<<" "<<cell_idx.col<<endl;
            return stoi(parts[0]) + spreadsheet[cell_idx.row][cell_idx.col];
        }
        else {
            return stoi(parts[0]) + stoi(parts[1]);
        }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */