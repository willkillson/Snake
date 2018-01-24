#include "Snake.h"
#include <assert.h>



bool Snake::isInTileCeptEnd(const Location & target_loc) const
{
	int i = 0;
	int p = _nSeg-1;

	for (; i < p; i++)
	{
		if (this->_segments[i].GetLoc() == target_loc)
		{
			return true;
		}
	}
	return false;
}

bool Snake::isSpotFreeOfSegments(const Location & loc) const
{

	for (int i = 0; i < this->_nMaxSeg - 1; i++)
	{
		if (this->_segments[i].GetLoc() == loc)
		{
			return false;
		}
	}
	

	return true;
}

Snake::Snake(const Location & loc)
{

	this->_segments[0].InitHead(loc);

	

}
void Snake::MoveBy(const Location & delt_loc)
{


	for (int i = this->_nSeg - 1; i > 0; i--)
	{
		
		this->_segments[i].Follow(this->_segments[i - 1]);
	}

	this->_segments[0].MoveBy(delt_loc);

}
void Snake::Grow()
{
	if (this->_nSeg < this->_nMaxSeg)
	{
		this->_segments[_nSeg].InitBody(this->_cycle);
		this->_nSeg++;
	}
}
void Snake::Draw(Board & board) const
{
	for (int i = 0; i < this->_nSeg; i++)
	{
		this->_segments[i].Draw(board);
	}
}

Location Snake::GetNextHeadLocation(const Location & delt_loc) const
{
	Location l(_segments[0].GetLoc());
	l.add(delt_loc);
	return l;
}
	
void Snake::Segment::InitHead(const Location& loc)
{
	this->_loc = loc;
	this->_c = Snake::_headColor;
}
void Snake::Segment::InitBody(int& cycle)
{
	switch (cycle)
	{
	case (0):
		this->_c = Colors::MakeRGB(124, 252, 0);
		break;
	case(1):
		this->_c = Colors::MakeRGB(0, 100, 0);
		break;
	case(2):
		this->_c = Colors::MakeRGB(107, 142, 35);
		cycle = -1;
		break;
	}
	cycle++;
}
void Snake::Segment::Follow(const Segment& next)
{
	this->_loc = next._loc;
}
void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	this->_loc.add(delta_loc);
}
void Snake::Segment::Draw(Board& board) const
{
	Location loc = this->_loc;
	board.DrawCell(loc, this->_c);

}

