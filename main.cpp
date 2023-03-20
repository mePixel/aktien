#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

struct stock{
    std::string name;
    std::string wkn;
    std::string shorthand;
    std::string date[30];
    float open[30]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    float high[30]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    float low[30]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    float close[30]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    float adjClose[30]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    float volume[30]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
};

std::vector<stock> stocks[17];

int hash(int k, int p){
    return k%p;
}//done

int charVal(char x){
    return (int)x - 87;
}
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

stock add(std::string name, std::string wkn, std::string shorthand){
    stock stocks;
    stocks.name=name;
    stocks.wkn=wkn;
    stocks.shorthand=shorthand;

    return stocks;
}

void del(std::string name){
    int stringRep=0;
    for (unsigned int i = 0; i < name.length(); i++){
        stringRep+=charVal(name[i]);
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
        stringRep+=charVal(name[i]);
    }

    int pos = hash(stringRep, 17);
    for (int i = 0; i < stocks[pos].size(); ++i) {
        if (name == stocks[pos][i].name){
            return stocks[pos][i];
        }
    }
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

        getline(ss, row.date[counter], ',');
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

        // read adj_close
        getline(ss, token, ',');
        row.adjClose[counter] = stof(token);

        // read volume
        getline(ss, token, ',');
        row.volume[counter] = stof(token);

        data.insert(data.begin(),row);

        counter++;

    }

    file.close();
    return data;
}

void import(std::string stockname, std::string filename){
    std::vector<stock> data = read_stock_data(filename);
    stock stocki = getStockWithName(stockname);

    for(int i = 0; i < 30; i++){
        stocki.date[i] = data[0].date[i];
        stocki.open[i] = data[0].open[i];
        stocki.high[i] = data[0].high[i];
        stocki.low[i] = data[0].low[i];
        stocki.close[i] = data[0].close[i];
        stocki.volume[i] = data[0].volume[i];
        stocki.adjClose[i] = data[0].adjClose[i];
    }


}

void search(stock stockEntry){
    std::cout << " " << stockEntry.name ;
    std::cout << " " << stockEntry.date[0] << " ";
    std::cout << " " << stockEntry.open[0] << " ";
    std::cout << " " << stockEntry.high[0] << " ";
    std::cout << " " << stockEntry.close[0] << " ";
    std::cout << " " << stockEntry.volume[0] << " ";
    std::cout << " " << stockEntry.adjClose[0] << std::endl;
}

void plot(stock stockEntry){
    return;
}

void save(){
    std::ofstream myfile;
    myfile.open ("savedata.txt");
    for (int i = 0; i < 17; ++i) {
        for (int j = 0; j < stocks[i].size(); ++j) {
            myfile << stocks[i][j].name << "\n";
            myfile << stocks[i][j].wkn << "\n";
            myfile << stocks[i][j].shorthand << "\n";
            for (int k = 0; k < 30; ++k) {
                myfile << stocks[i][j].date[k] << "\n";
                myfile << stocks[i][j].open[k] << "\n";
                myfile << stocks[i][j].high[k] << "\n";
                myfile << stocks[i][j].low[k] << "\n";
                myfile << stocks[i][j].close[k] << "\n";
                myfile << stocks[i][j].volume[k] << "\n";
                myfile << stocks[i][j].adjClose[k] << "\n";
            }
        }
    }

    myfile.close();

    std::cout << "File Saved" << std::endl;
}



void load(){
    std::string line;
    std::ifstream myfile ("savedata.txt");
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            std::string name = line;

            getline (myfile,line);
            std::string wkn = line;

            getline (myfile,line);
            std::string shorthand = line;

            stock tmp = add(name, wkn, shorthand);

            for (int i = 0; i < 30; ++i) {
                getline (myfile,line);
                std::string date = line;
                getline (myfile,line);
                std::string open = line;
                getline (myfile,line);
                std::string high = line;
                getline (myfile,line);
                std::string low = line;
                getline (myfile,line);
                std::string close = line;
                getline (myfile,line);
                std::string adjClose = line;
                getline (myfile,line);
                std::string volume = line;

                tmp.date[i] = date;
                tmp.open[i] = std::stof(open);
                tmp.high[i] = std::stof(high);
                tmp.low[i] = std::stof(low);
                tmp.close[i] = std::stof(close);
                tmp.adjClose[i] = std::stof(adjClose);
                tmp.volume[i] = std::stof(volume);
            }

            int stringRep=0;
            for (unsigned int i = 0; i < tmp.name.length(); i++){
                stringRep+=charVal(tmp.name[i]);
            }

            int pos = hash(stringRep, 17);
            stocks[pos].push_back(tmp);
        }
        myfile.close();
    }else{
        std::cout << "Unable to open file" << std::endl;
    }

    std::cout << "File has been loaded" << std::endl;
}

void quit(bool& run){
    run = false;
}



int main() {
    bool run=true;
    int p=17;

    std::string input;

    //std::string filename = "MSFT.csv";


    while (run){
        std::cout << "What do you want to do?" << std::endl;

        std::cin >> input;

        if (input == "q"){
            quit(run);
        }else if (input == "a"){
            stock tmp = add();

            int stringRep=0;
            for (unsigned int i = 0; i < tmp.name.length(); i++){
                stringRep+=charVal(tmp.name[i]);
            }

            int pos = hash(stringRep, p);
            stocks[pos].push_back(tmp);
        }else if (input == "d"){
            std::string tmp;
            std::cout << "What stock do you want to delete?" << std::endl;
            std::cin >> tmp;
            del(tmp);
        }else if (input == "i"){
            std::string stockname;
            std::string filename;
            std::cout << "Input Stockname: ";
            std::cin >> stockname;
            std::cout << "Input Filename: ";
            std::cin >> filename;
            filename="./csv/"+filename;
            import(stockname, filename);
        }else if (input == "s"){
            std::string tmp;
            std::cout << "What stock do you want to search for?" << std::endl;
            std::cin >> tmp;
            search(getStockWithName(tmp));
        }else if (input == "p"){
            std::string tmp;
            std::cout << "What stock do you want to plot?" << std::endl;
            std::cin >> tmp;
            plot(getStockWithName(tmp));
        }else if (input == "sa"){
            save();
        }else if (input == "lo"){
            load();
        }
    }

    return 0;
}
