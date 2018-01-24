#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "Graphics.h"
#include "Location.h"
#include "Colors.h"
#include <assert.h>

class Board {
public:
	Board(Graphics &gfx);
	void DrawCell(Location &loc, const Color c);
	void DrawBorder(const Color c);
	int GetWidth() const { return this->_width; }
	int GetHeight() const { return this->_height; }
	bool isInsideBoard(const Location &loc)const;
	int GetDem() const { return this->_dimension; }

private:
	static constexpr int xpos = 10;
	static constexpr int ypos = 10;
	static constexpr int _dimension = 10;
	static constexpr int _width = Graphics::ScreenWidth- xpos;
	static constexpr int _height = Graphics::ScreenHeight- ypos;

	//assert()
	Graphics &_gfx;

};

#endif 