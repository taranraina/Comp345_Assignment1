#include "harvest_tiles.h"
#include <iostream>
#include <ctime>
#include <random>
#include <array>
#include <chrono>
std::random_device rd;
std::mt19937 gen(rd());

int main()
{
    HarvestTiles Harvest;
    std::getchar();
    return 0;
    
}

//number of resource per tile
int HarvestTiles::numOfResourcePerTile(){
    int num_resources = 0;
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double rand_val = dis(gen);
    std::cout << rand_val << std::endl;  //just to see the val for debug purposes, remove
    if (rand_val < 0.5) num_resources = 2;
    else num_resources = 3;
    return num_resources;
}

HarvestTiles::HarvestTiles() {
    std::array<int, 4> resource_array{ 0,1,2,3 };
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(resource_array.begin(), resource_array.end(), std::default_random_engine(seed));
    
    for (int i = 0; i < 4; i++) {
        std::cout << "this is resource: " <<resource_array[i] << std::endl;
    } //just for a print
    
    
    //    Node res[2][2];
    ht = new Node[4];
    int i = 0;
    
    //*(*(arr + i) + j))
    while (i < numOfResourcePerTile()) {
        *(ht+(i)) = Node(Resource(resource_array[i]));
        i++;
    }
    
    for (int j = 0; j < 4; j++) {
        std::cout << " this is the ht res " <<(ht+j)->getResourceName() << std::endl;
        
    }
    //PROBLEM IS HERE
    std::uniform_int_distribution<> rand_roll(0, num_resources-1);
    
    if (num_resources == 3) {
        int rand = rand_roll(gen);
        *(ht+3) = Node(Resource(resource_array[rand]));
    }
    else {
        int rand1 = rand_roll(gen);
        *(ht+2) = Node(Resource(resource_array[rand1]));
        int rand2 = rand_roll(gen);
        *(ht+3) = Node(Resource(resource_array[rand2]));
    }
    
    //debug the ht array
    for (int j = 0; j < 4; j++) {
        std::cout << "this is the new ht res " <<(ht+j)->getResourceName() << std::endl;
    }
}

HarvestTiles::~HarvestTiles() {
    delete[] ht;
    ht = nullptr;
}

void HarvestTiles::orientation(int degrees) {
    //in this method somehow maintain the integrity of the orientation
}



//Node functions

Node::Node(Resource resource) {
    
    this->resource = resource;        // this->res=Resources[resource];
}

std::string Node::getResourceName(){
    switch (resource) {
        case wheat  :  res="wheat"; break;
        case wood:  res="wood"; break;
        case sheep : res="sheep";  break;
        case stone : res= "stone";  break;
            
    }
    return res;
}

int Node:: getResourse(){
    return resource;
}

//Building function

Building::Building() {
    
}
