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

int HarvestTiles::numOfResourcePerTile(){ //number of resource per tile
    int num_resources = 0;
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double rand_val = dis(gen);
    //std::cout << rand_val << std::endl;  //just to see the val for debug purposes, remove
    if (rand_val < 0.5) num_resources = 2;
    else num_resources = 3;
    return num_resources;
}

HarvestTiles::HarvestTiles() {
    std::array<int, 4> resource_array{ 0,1,2,3 };
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(resource_array.begin(), resource_array.end(), std::default_random_engine(seed)); //shuffles the array.
    
    harvestTile = new Node[4];
    int i = 0;
    
    while (i < numOfResourcePerTile()) {
        *(harvestTile+(i)) = Node(Resource(resource_array[i]));
        i++;
    }
    std::uniform_int_distribution<> rand_roll(0, numOfResourcePerTile()-1);
    
    if (numOfResourcePerTile() == 3) {
        int lastResource = rand_roll(gen);
        *(harvestTile+3) = Node(Resource(resource_array[lastResource]));
    }
    else {
        int thirdResource = rand_roll(gen);
        *(harvestTile+2) = Node(Resource(resource_array[thirdResource]));
        int fourthResource = rand_roll(gen);
        *(harvestTile+3) = Node(Resource(resource_array[fourthResource]));
    }
    printTile();
    
}
void HarvestTiles::printTile(){
    for (int j = 0; j < 4; j++) {
        if(j<2)
            std::cout <<(harvestTile+j)->getResourceName()+ " " ;
        else if(j==2){
            std::cout <<"\n"+(harvestTile+j)->getResourceName()+ " "  ;
        }
        else
            std::cout <<(harvestTile+j)->getResourceName()<<std::endl ;
    }
}

HarvestTiles::~HarvestTiles() {
    delete[] harvestTile;
    harvestTile = nullptr;
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
        case wheat  :  resourceName="wheat"; break;
        case wood: resourceName="wood"; break;
        case sheep : resourceName="sheep";  break;
        case stone : resourceName= "stone";  break;
            
    }
    return resourceName;
}

int Node:: getResourse(){
    return resource;
}

//Building function

Building::Building() {
    
}
