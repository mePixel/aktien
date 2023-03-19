#include <iostream>
#include <string>
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

std::vector<stock> stocks[17];

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

void del(std::string name){
    int stringRep=0;
    for (unsigned int i = 0; i < name.length(); i++){
        stringRep+=(name[i]);
    }

    int pos = hash(stringRep, 17);
    for (int i = 0; i < stocks[pos].size(); ++i) {
        if (name == stocks[pos][i].name){
            stocks[pos].erase(stocks->begin()+i);
        }
    }
}

void import(){

}

void search(std::string name){

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
/*
std::vector<stock> read_stock_data(std::string filename){
    std::vector<stock> data;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return data;
    }

    std::string line, col;
    getline(file, line); // read header row

    while (getline(file, line)) {
        stock row;
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
*/

int charVal(char x){
    return (int)x - 87;
}

int main() {
    bool run=true;
    int p=17;

    std::string input;

    //std::string filename = "MSFT.csv";
    //std::vector<stock> data = read_stock_data(filename);

    while (run){
        std::cout << "what do you want to do?" << std::endl;

        std::cin >> input;

        if (input == "q"){
            quit(run);
        }else if (input == "a"){
            stock tmp = add();

            int stringRep=0;
            for (unsigned int i = 0; i < tmp.name.length(); i++){
                stringRep+=(tmp.name[i]);
            }

            int pos = hash(stringRep, p);
            stocks[pos].push_back(tmp);
        }else if (input == "d"){
            std::string tmp;
            std::cout << "What stock do you want to delete?" << std::endl;
            std::cin >> tmp;
            del(tmp);
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
