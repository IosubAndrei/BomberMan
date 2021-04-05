#pragma once
#include <vector>
#include <utility>

struct TileLayer
{
	const std::vector<std::vector<int>> m_tileLayer;

	TileLayer(std::vector<std::vector<int>>&& _tileLayer):
		m_tileLayer(std::move(_tileLayer))
	{
	}
};