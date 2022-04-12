#pragma once

struct Color
{
public:
	unsigned char r;
	unsigned char g;
	unsigned char b;

	Color(unsigned char& r, unsigned char& g, unsigned char& b) : r(r), g(g), b(b) {}
	Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}
};

inline constexpr unsigned char operator "" _uc(unsigned long long arg) noexcept
{
	return static_cast<unsigned char>(arg);
}