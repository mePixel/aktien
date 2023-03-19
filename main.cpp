#include <iostream>
#include <string>
#include <list>

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

int main() {
    bool run=true;
    int p=17;

    std::list<stock> stocks[p];
    std::string input;

    while (run){
        std::cout << "what do you want to do?" << std::endl;

        std::cin >> input;

        if (input == "q"){
            quit(run);
        }else if (input == "a"){
            stock tmp = add();
            int pos = hash(std::stoi(tmp.name), p);
            stocks[pos].insert(tmp);
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
