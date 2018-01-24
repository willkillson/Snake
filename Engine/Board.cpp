#include "Board.h"
#include <assert.h>

Board::Board(Graphics & gfx)
	:
	_gfx(gfx)
{


}

void Board::DrawCell(Location & loc, Color c)
{

	assert(loc.x >= 0);
	assert(loc.x < this->_width);
	assert(loc.y >= 0);
	assert(loc.y < this->_height);
	this->_gfx.DrawRectDim(loc.x*this->_dimension+this->xpos, loc.y*this->_dimension + this->ypos, this->_dimension, this->_dimension,  c);
}

void Board::DrawBorder(const Color c)
{
	_gfx.DrawRectDim(0, 0, Graphics::ScreenWidth, _dimension, c);
	_gfx.DrawRectDim(0, 0, _dimension, Graphics::ScreenHeight, c);
	_gfx.DrawRectDim(Graphics::ScreenWidth-_dimension,0, _dimension, Graphics::ScreenHeight, c);
	_gfx.DrawRectDim(0 , Graphics::ScreenHeight- _dimension, Graphics::ScreenWidth, _dimension, c);
}

bool Board::isInsideBoard(const Location & loc) const
{

	return loc.x>=0 &&loc.x <= this->_width &&
		loc.y>=0&&loc.y<this->_height;
}
