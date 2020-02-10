#include "harvest_tiles.h"
#include <iostream>
#include <ctime>
#include <random>
#include <array>
#include <chrono>
std::random_device rd;
std::mt19937 gen(rd());
std::array<int, 4> resource_array{ 0,1,2,3 };

int main()
{
    HarvestTiles Harvest;
    Harvest.drawHarvestTile();
    Harvest.printTile(Harvest.orientation(180));
    std::cout<<std::endl;
    Building::drawBuilding().printBuilding();
    std::getchar();
    return 0;
    
}

//Node functions

Node::Node(Resource resource) {
    
    this->resource = resource;        // this->res=Resources[resource];
}

void Node::setResource(Resource resource){
    this->resource=resource;
}

int Node:: getResource(){
    return resource;
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
HarvestTiles::HarvestTiles() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(resource_array.begin(), resource_array.end(), std::default_random_engine(seed)); //shuffles the array.
    
    harvestTile = new Node[4];
    int i = 0;
    int numRes=numOfResourcePerTile();
    while (i < numRes) {
        *(harvestTile+(i)) = Node(Resource(resource_array[i]));
        i++;
    }
    std::uniform_int_distribution<> rand_roll(0, numOfResourcePerTile()-1);
    
    if (numRes == 3) {
        int lastResource = rand_roll(gen);
        *(harvestTile+3) = Node(Resource(resource_array[lastResource]));
    }
    else {
        int thirdResource = rand_roll(gen);
        *(harvestTile+2) = Node(Resource(resource_array[thirdResource]));
        int fourthResource = rand_roll(gen);
        *(harvestTile+3) = Node(Resource(resource_array[fourthResource]));
    }
    
}
void HarvestTiles::printTile(Node* node){
    for (int j = 0; j < 4; j++) {
        if(j<2)
            std::cout <<(node+j)->getResourceName()+ " " ;
        else if(j==2){
            std::cout <<"\n"+(node+j)->getResourceName()+ " "  ;
        }
        else
            std::cout <<(node+j)->getResourceName()<<std::endl ;
    }
}

HarvestTiles::~HarvestTiles() {
    delete[] harvestTile;
    harvestTile = nullptr;
    delete[] rotatedHarvestTile;
    rotatedHarvestTile=nullptr;
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

void HarvestTiles::drawHarvestTile(){
    printTile(harvestTile);
}

Node* HarvestTiles::orientation(int degrees) {
    rotatedHarvestTile = new Node[4];
    
    switch(degrees){
        case 90:
            *(rotatedHarvestTile)=Node(Resource((harvestTile+2)->getResource()));
            *(rotatedHarvestTile+1)=Node(Resource((harvestTile)->getResource()));
            *(rotatedHarvestTile+2)=Node(Resource((harvestTile+3)->getResource()));
            *(rotatedHarvestTile+3)=Node(Resource((harvestTile+1)->getResource()));
            break;
            
        case 180:
            *(rotatedHarvestTile)=Node(Resource((harvestTile+3)->getResource()));
            *(rotatedHarvestTile+1)=Node(Resource((harvestTile+2)->getResource()));
            *(rotatedHarvestTile+2)=Node(Resource((harvestTile+1)->getResource()));
            *(rotatedHarvestTile+3)=Node(Resource((harvestTile)->getResource()));
            break;
            
        case 270:
            *(rotatedHarvestTile)=Node(Resource((harvestTile)->getResource()));
            *(rotatedHarvestTile+1)=Node(Resource((harvestTile+2)->getResource()));
            *(rotatedHarvestTile+2)=Node(Resource((harvestTile+1)->getResource()));
            *(rotatedHarvestTile+3)=Node(Resource((harvestTile+3)->getResource()));
            break;
    }
    return rotatedHarvestTile;
}

//Building function declarations

Building::Building() {
    setBuildingValue();
    setBuildingNode();
}
int Building::getBuildingValue(){
    return value;
}

void Building::setBuildingValue(){//change to init
    std::uniform_int_distribution<> value_roll(1, 6);
    value= value_roll(gen);
}
void Building::setBuildingNode(){
    std::uniform_int_distribution<> resource_roll(0, 3);
    int resourceType=resource_roll(gen);
    building= new Node(Resource(resourceType));
    
}
void Building::printBuilding(){
    std::cout<<"Building Tile resource: "<<building->getResourceName()<<std::endl;
    std::cout<<"Building Tile value: "<<getBuildingValue()<<std::endl;

    
}
 Building Building::drawBuilding() {
    return Building();
}
Building::~Building(){
    delete building;
    building=nullptr;
}

//void Building::isOnTop(char userInput){
//    while(1){
//        if (userInput=='t'||userInput=='T') {
//            isTop=true;
//            break;
//        }
//        else if (userInput=='b'||userInput=='B') {
//                isTop=false;
//                break;
//        }
//        else std::cout<<"Please enter valid value"<<std::endl;
//        }
//}


