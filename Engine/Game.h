/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "SevenSegment.h"
#include "Board.h"
#include <random>
#include "Snake.h"
#include "SpriteCodex.h"
#include "Power.h"
#include <vector>
#include <algorithm>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
	bool isGoodInput();
	bool isNextASegment();
	bool isNextAPower();


	//game loop functions
	void GetInputFromKeybrd();
	void UpdatePowerUps();
	void UpdateSnake();

private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	int count = 0;
	static constexpr int powers = 5;


	//testvar for win condition
	int test = 0;
	//

	Board board;
	Snake snake;
	Location _delta_loc = { 1,0 };
	std::vector<Power> _powers;


	int _nPowersEaten = 0;
	int snekMovePeriod = 20;
	int snekMoveCounter = 0;
	bool _DidTheSnakeJustEat;

	bool isGameOver = false;
	std::mt19937 rng;
};