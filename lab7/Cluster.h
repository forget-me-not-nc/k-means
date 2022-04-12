#pragma once

#include "Pixel.h"

#include <vector>

using std::vector;

struct Cluster
{
public:
	Pixel center;
	Pixel newCenter;

	Cluster(Pixel& center) : center(center), newCenter(center) {}
	Cluster(Pixel center) : center(center), newCenter(center) {}

	void setNewCenter(Pixel& newPixel)
	{
		//points.push_back(newPixel);

		newCenter.selfColor.r = (newPixel.selfColor.r + newCenter.selfColor.r) / 2;
		newCenter.selfColor.g = (newPixel.selfColor.g + newCenter.selfColor.g) / 2;
		newCenter.selfColor.b = (newPixel.selfColor.b + newCenter.selfColor.b) / 2;

		//newPixel.approximateColor.r = newCenter.selfColor.r;
		//newPixel.approximateColor.g = newCenter.selfColor.g;
		//newPixel.approximateColor.b = newCenter.selfColor.b;
		
		//check
		newPixel.approximateColor.r = center.selfColor.r;
		newPixel.approximateColor.g = center.selfColor.g;
		newPixel.approximateColor.b = center.selfColor.b;
	}
};

