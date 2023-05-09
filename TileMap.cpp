#include "TileMap.h"

TileMap::TileMap()
{
	this->gridSizeU = 64;
	this->layers = 1;
	this->maxsize.x = 1000;
	this->maxsize.y = 1000;
	this->map.resize(this->maxsize.x);
	for(size_t x =	0; x < this->maxsize.x; x++)
	{
		this->map.push_back(vector <vector <Tile>>());
		for (size_t y = 0; y < this->maxsize.y; y++)
		{
			this->map[x].resize(this->maxsize.x);

			this->map[x].push_back(vector <Tile>());
			for (size_t z = 0; z < 1; z++)
			{
				this->map[x][y].resize(this->maxsize.x);

				this->map[x][y].push_back(Tile());

			}
		}
	}
}

TileMap::~TileMap()
{
}
