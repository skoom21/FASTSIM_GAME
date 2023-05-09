#include "Tile.h"

void Tile::innitsprite()
{
	if(!this->texture.loadFromFile("Textures/Tile/Tile.png"))
	{
				cout << "ERROR::Tile::Failed to load texture" << "\n";
	}
	texture.setSmooth(true);
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(IntRect(0, 0, 50, 50));
	this->sprite.setScale(0.5f, 0.5f);
	this->sprite.setPosition(this->pos);

}

Tile::Tile()
{
}

Tile::Tile(bool ispassable, bool isexit, float x, float y, Texture texture)
{
	this->ispassable = ispassable;
	this->isexit = isexit;
	this->pos.x = x;
	this->pos.y = y;
	this->texture = texture;
	innitsprite();
}


void Tile::update()
{

}

void Tile::render(RenderTarget& target)
{
	target.draw(this->shape);
}
