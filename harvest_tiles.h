#ifndef HARVEST_TILES_H
#define HARVEST_TILES_H
#include <string>

enum Resource { wheat, wood, sheep, stone };

class Node
{
public:
	Node() {};
    Node(Resource resource);
    int getResourse();
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
private:
	int value;
	Node top;
	Node bottom;

};
#endif
