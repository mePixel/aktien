#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

struct stock{
    std::string name;
    float open[30];
    float high[30];
    float low[30];
    float close[30];
    float adjClose[30];
    float volume[30];
};

struct StockData {
    std::string name;
    std::string wkn;
    std::string abbreviation;
};

int hash(int k, int p){
    return k%p;
}//done


void add(){

}

void del(){

}

void import(){

}

void search(){

}

void plot(){

}

void save(){

}

void load(){

}

void quit(bool& run){
    run = false;
}

std::vector<StockData> read_stock_data(std::string filename){
    std::vector<StockData> data;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return data;
    }

    std::string line, col;
    getline(file, line); // read header row

    while (getline(file, line)) {
        StockData row;
        std::stringstream ss(line);

        getline(ss, row.date, ',');
        ss >> row.open;
        ss.ignore(); // ignore comma
        ss >> row.high;
        ss.ignore(); // ignore comma
        ss >> row.low;
        ss.ignore(); // ignore comma
        ss >> row.close;
        ss.ignore();
        ss >> row.volume;
        ss.ignore();
        ss >> row.adj_close;

        data.push_back(row);
    }

    file.close();
    return data;
}
int main() {
    bool run=true;
    int p=17;
    stock stocks[p];
    std::string input;
    std::string filename = "MSFT.csv";
    std::vector<StockData> data = read_stock_data(filename);
    while (run){
        std::cin >> input;

        if (input == "q"){
            quit(run);
        }else if (input == "a"){
            add();
        }else if (input == "d"){
            del();
        }else if (input == "i"){
            import();
        }else if (input == "s"){
            search();
        }else if (input == "p"){
            plot();
        }else if (input == "sa"){
            save();
        }else if (input == "lo"){
            load();
        }
    }

    return 0;
}
