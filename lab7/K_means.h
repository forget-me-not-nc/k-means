#pragma once

#include "Cluster.h"

class K_means
{
public:
	K_means() {};
	K_means(vector<Cluster>& c, vector<Pixel>& pixels) : clusters(c), pixels(pixels) {}
	~K_means() 
	{
		clusters.clear();
		pixels.clear();
	};

	vector<Cluster> clusters;
	vector<Pixel> pixels;

	void iterate();
	bool isComputing();

private:

	const static int MAX_ITERATIONS = 300;
	int currentIteration = 0;

	double minDist(Pixel& clusterCenter, Pixel& pixel);
};
