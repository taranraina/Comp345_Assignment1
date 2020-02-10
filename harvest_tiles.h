#ifndef HARVEST_TILES_H
#define HARVEST_TILES_H
#include <string>

enum Resource { wheat, wood, sheep, stone };

class Node
{
public:
	Node() {};
    Node(Resource resource);
    int getResource();
    void setResource(Resource resource); 
    std::string getResourceName();
private:
	Resource resource;
   std::string resourceName;
};

class HarvestTiles
{
public:

	HarvestTiles();
    int numOfResourcePerTile();
    ~HarvestTiles();
    void drawHarvestTile();
	Node* orientation(int degrees);
    void printTile(Node* node);
private:
	Node* harvestTile;
    Node* rotatedHarvestTile;
    
};

class Building
{
public:
    Building();
    ~Building();
    Resource getBuildingResource();
    void setBuildingResource();
    int getBuildingValue();
    void setBuildingNode();
    void setBuildingValue();
    void printBuilding();
    void isOnTop(char userInput);
    static Building drawBuilding();
private:
	int value;
	Node* building;
    bool isTop;
};
#endif
