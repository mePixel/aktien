#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct stock{
    std::string name;
    std::string wkn;
    std::string shorthand;
    std::string date;
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


stock getStockWithName(std::string name){
    int stringRep=0;
    for (unsigned int i = 0; i < name.length(); i++){
        stringRep+=(name[i]);
    }

    int pos = hash(stringRep, 17);
    for (int i = 0; i < stocks[pos].size(); ++i) {
        if (name == stocks[pos][i].name){
            return stocks[pos][i];
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

std::vector<stock> read_stock_data(std::string filename){
    std::vector<stock> data;
    std::ifstream file(filename);
    int counter=0;

    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return data;
    }

    std::string line, col;
    getline(file, line); // read header row

    while (getline(file, line)&&counter<30) {

        stock row;
        std::string token;
        std::stringstream ss(line);

        getline(ss, row.date, ',');
        getline(ss, token, ',');
        row.open[counter] = stof(token);

        // read high
        getline(ss, token, ',');
        row.high[counter] = stof(token);

        // read low
        getline(ss, token, ',');
        row.low[counter] = stof(token);

        // read close
        getline(ss, token, ',');
        row.close[counter] = stof(token);

        // read volume
        getline(ss, token, ',');
        row.volume[counter] = stof(token);

        // read adj_close
        getline(ss, token, ',');
        row.adjClose[counter] = stof(token);

        data.push_back(row);

        data.push_back(row);
        counter++;
    }

    file.close();
    return data;
}

int charVal(char x){
    return (int)x - 87;
}

int main() {
    bool run=true;
    int p=17;

    std::string input;

    std::string filename = "MSFT.csv";
    std::vector<stock> data = read_stock_data(filename);

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
            //search();
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
