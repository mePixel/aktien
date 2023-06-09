#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <math.h>

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
    double volume[30]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
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

    int pos = hash(stringRep, 17);      //Welcher Vektor im Array
    for (int i = 0; i < stocks[pos].size(); ++i) {
        if (name == stocks[pos][i].name){       //Element im Vektor mit richtigem Namen
            return stocks[pos][i];
        }
    }
}

int getStockPosByName(std::string name){
    int stringRep=0;
    for (unsigned int i = 0; i < name.length(); i++){
        stringRep+=(name[i]);
    }

    int pos = hash(stringRep, 17);
    for (int i = 0; i < stocks[pos].size(); ++i) {
        if (name == stocks[pos][i].name){       //returned den Index von dem Element mit richtigem Namen im Vektor
            return i;
        }
    }
}

stock read_stock_data(std::string filename){
    std::vector<stock> data;
    std::ifstream file(filename);
    stock row;
    int counter=0;

    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return row;
    }

    std::string line, col;
    getline(file, line); // read header row

    std::vector<std::string> fileArr;

    while(getline(file, line)){
        std::string token;
        std::stringstream ss(line);
        getline(ss, token, ',');
        fileArr.insert(fileArr.cbegin(), token);
        getline(ss, token, ',');
        fileArr.insert(fileArr.cbegin(), token);
        getline(ss, token, ',');
        fileArr.insert(fileArr.cbegin(), token);
        getline(ss, token, ',');
        fileArr.insert(fileArr.cbegin(), token);
        getline(ss, token, ',');
        fileArr.insert(fileArr.cbegin(), token);
        getline(ss, token, ',');
        fileArr.insert(fileArr.cbegin(), token);
        getline(ss, token, ',');
        fileArr.insert(fileArr.cbegin(), token);
    }

    counter=0;
    for (int i = 0; i < 30*7; i+=7) {       //30Tage 7 Einträge pro Tag, deswegen 7er Schritte
        row.date[counter] = fileArr[i+6];
        row.open[counter] = stof(fileArr[i+5]);
        row.high[counter] = stof(fileArr[i+4]);
        row.low[counter] = stof(fileArr[i+3]);
        row.close[counter] = stof(fileArr[i+2]);
        row.volume[counter] = stold(fileArr[i+1]);
        row.adjClose[counter] = stof(fileArr[i]);
        counter++;
        data.push_back(row);
    }



    /*
    while (getline(file, line)&&counter<30) {

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
        row.volume[counter] = stold(token);

        // read volume
        getline(ss, token, ',');
        row.adjClose[counter] = stof(token);

        data.insert(data.begin(),row);

        counter++;

    }*/

    file.close();
    return row;
}

void import(std::string stockname, std::string filename){
    stock data = read_stock_data(filename);     //Daten aus csv holen
    stock stocki = getStockWithName(stockname);     //name, wkn, shorthand holen

    data.name = stocki.name;        //data wird um fehlende "Attribute" ergänzt
    data.wkn = stocki.wkn;
    data.shorthand = stocki.shorthand;

    /* for(int i = 0; i < 30; i++){
         stocki.date[i] = data.date[i];
         stocki.open[i] = data.open[i];
         stocki.high[i] = data.high[i];
         stocki.low[i] = data.low[i];
         stocki.close[i] = data.close[i];
         stocki.volume[i] = data.volume[i];
         stocki.adjClose[i] = data.adjClose[i];
     }*/

    int i = getStockPosByName(stockname);   //Holt gesuchtes Element im Vektor mit dem richtigen Namen

    int stringRep=0;
    for (unsigned int i = 0; i < stockname.length(); i++){  //stockname wird zur Zahl gemacht
        stringRep+=charVal(stockname[i]);
    }
    int pos = hash(stringRep, 17);      //Verschlüsselung des Stockname um Index für richtigen Vektor zu bekommen

    stocks[pos].at(i) = data;

}

void search(stock stockEntry){      //liest die daten des gesuchten Stock aus
    std::cout << " " << stockEntry.name ;
    std::cout << " " << stockEntry.date[0] << " ";
    std::cout << " " << stockEntry.open[0] << " ";
    std::cout << " " << stockEntry.high[0] << " ";
    std::cout << " " << stockEntry.close[0] << " ";
    std::cout << " " << stockEntry.volume[0] << " ";
    std::cout << " " << stockEntry.adjClose[0] << std::endl;
}

void plot(stock stockEntry){
    float max=0;
    for (int i = 0; i < 30; ++i) {      //sucht maximales High eines Stocks innerhalb von 30Tagen
        if(stockEntry.high[i] > max){
            max = stockEntry.high[i];
        }
    }

    float min=max;
    for (int i = 0; i < 30; ++i) {      //sucht minimales High eines Stocks innerhalb von 30Tagen
        if(stockEntry.high[i] < min){
            min = stockEntry.high[i];
        }
    }

    std::vector<float> values;      //Vektor für Balkenanzahl
    for (int i = 0; i < 30; ++i) {
        values.insert(values.cbegin(), floor(((stockEntry.high[i]-min)/(max-min))*10)); //Rechnung um zu wissen wie viele balken der jeweilige Tag hat
    }

    for (int i = 10; i >= 0; --i) { //printed values vector als balkendiagramm
        for (int j = 0; j < 30; ++j) {
            if (values[j] >= i){
                std::cout << "|";
            }else{
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }

}

void save(){
    std::ofstream myfile;
    myfile.open ("savedata.txt");   //erstellt/öffnet savedata.txt
    for (int i = 0; i < 17; ++i) {
        for (int j = 0; j < stocks[i].size(); ++j) {    //speichert ganze Hashtabelle in der txt
            myfile << stocks[i][j].name << "\n";
            myfile << stocks[i][j].wkn << "\n";
            myfile << stocks[i][j].shorthand << "\n";
            for (int k = 0; k < 30; ++k) {
                myfile << stocks[i][j].date[k] << "\n";
                myfile << stocks[i][j].open[k] << "\n";
                myfile << stocks[i][j].high[k] << "\n";
                myfile << stocks[i][j].low[k] << "\n";
                myfile << stocks[i][j].close[k] << "\n";
                myfile << stocks[i][j].adjClose[k] << "\n";
                myfile << stocks[i][j].volume[k] << "\n";

            }
        }
    }

    myfile.close();

    std::cout << "File Saved" << std::endl;
}

void load(){      //holt sich hashtabelle aus txt und setzt alles auf tmp
    std::string line;
    std::ifstream myfile ("savedata.txt");  //öffnet savedata.txt
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            std::string name = line;

            getline (myfile,line);
            std::string wkn = line;

            getline (myfile,line);
            std::string shorthand = line;

            stock tmp = add(name, wkn, shorthand);

            for (int i = 0; i < 30; ++i) {
                getline (myfile,line);      //holt ganze Zeile und speichert sie ins line
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
                tmp.volume[i] = std::stold(volume);
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
    std::cout << std::fixed;
    while (run){
        std::cout << "a... add entry" << std::endl;
        std::cout << "d... delete entry" << std::endl;
        std::cout << "i... import data" << std::endl;
        std::cout << "s... search for entry by name" << std::endl;
        std::cout << "p... plot entry" << std::endl;
        std::cout << "sa... save session" << std::endl;
        std::cout << "lo... load session" << std::endl;
        std::cout << "q... quit programm" << std::endl << std::endl;
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
            stocks[pos].push_back(tmp);     //neues Element
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
        std::cout << std::endl << std::endl << std::endl;
    }

    return 0;
}
