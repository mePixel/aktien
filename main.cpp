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

void quit(){

}

int main() {
    int p=17;
    stock stocks[p];



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
