#include "K_means.h"

#include <iostream>

void K_means::iterate()
{
	for (unsigned int p_index = 0; p_index < pixels.size(); p_index++)
	{
		double dist = 100000.0;
		unsigned int cluster = 0;

		for (unsigned int c_index = 0; c_index < clusters.size(); c_index++)
		{
			double tempDist = minDist(clusters[c_index].newCenter, pixels[p_index]);

			if (dist > tempDist)
			{
				dist = tempDist;
				cluster = c_index;
			}
		}

		clusters[cluster].setNewCenter(pixels[p_index]);
	}

	std::cout << "Iteration: " << currentIteration++ << std::endl;
}

bool K_means::isComputing()
{
	return currentIteration <= MAX_ITERATIONS;
}

double K_means::minDist(Pixel& clusterCenter, Pixel& pixel)
{
	return sqrt(
		pow((clusterCenter.selfColor.r - pixel.selfColor.r), 2) +
		pow((clusterCenter.selfColor.g - pixel.selfColor.g), 2) + 
		pow((clusterCenter.selfColor.b - pixel.selfColor.b), 2)
	);
}