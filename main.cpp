#include <iostream>
#include <string>
#include <list>
#include <vector>

struct stock{
    std::string name;
    std::string wkn;
    std::string shorthand;
    float open[30];
    float high[30];
    float low[30];
    float close[30];
    float adjClose[30];
    float volume[30];
};

int hash(int k, int p){
    return k%p;
}//done


stock add(){
    stock stocks;

    std::cout << "Please input the name of the stock: ";
    std::cin >> stocks.name;

    std::cout << "Please input the wkn of the stock: ";
    std::cin >> stocks.wkn;

    std::cout << "Please input the shorthand of the stock: ";
    std::cin >> stocks.shorthand;

    return stocks;
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

    std::list<stock> stocks[p];
    std::string input;

    std::string filename = "MSFT.csv";
    std::vector<StockData> data = read_stock_data(filename);

    while (run){
        std::cout << "what do you want to do?" << std::endl;

        std::cin >> input;

        if (input == "q"){
            quit(run);
        }else if (input == "a"){
            stock tmp = add();
            int pos = hash(std::stoi(tmp.name), p);
            stocks[0].push_back(tmp);
            //add element tmp to linked list and insert it to the stocks array at hashed position
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
