#pragma once

#include "Color.h"

struct Pixel
{
public:
	Color selfColor;
	Color approximateColor;

	Pixel(Color& c) : selfColor(c), approximateColor(c) {}
	Pixel(Color c) : selfColor(c), approximateColor(c) {}
};