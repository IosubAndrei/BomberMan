#pragma once

struct FrameDetails
{
	int m_height;
	int m_width;
	int m_y;
	int m_x;
	int m_ID;

	FrameDetails(int _height, int _width, int _x, int _y, int _ID) :m_height(_height),
		m_width(_width), m_y(_y), m_x(_x), m_ID(_ID)
	{}
};