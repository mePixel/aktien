#include <iostream>

struct stock{
    std::string name;
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

int main() {
    bool run=true;
    int p=17;
    stock stocks[p];
    std::string input;

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
