#include<iostream>
#include<random>

int random(){
    std::random_device rd;
    std::default_randome_engine eng(rd());
    std::uniform_int_distribution<int> dist(1,9);
    return dist(eng);
}