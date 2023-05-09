#pragma once
#include "Tile.h"

using namespace std;
using namespace sf;

class TileMap
{
private:
	unsigned gridSizeU;

	unsigned layers;

	Vector2u maxsize;

	vector <vector <vector <Tile>>> map;

public:

	TileMap();
	virtual ~TileMap();
};

