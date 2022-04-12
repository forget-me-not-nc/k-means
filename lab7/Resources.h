#pragma once

#include <Windows.h>
#include <GL/glew.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/geometric.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "K_means.h"

vector<Cluster> clusters =
{
	Cluster(Pixel(Color(230_uc, 20_uc, 20_uc))), //red
	Cluster(Pixel(Color(20_uc, 230_uc, 20_uc))), //green
	Cluster(Pixel(Color(20_uc, 20_uc, 230_uc))), //blue
	Cluster(Pixel(Color(230_uc, 230_uc, 20_uc))), //yellow
	Cluster(Pixel(Color(230_uc, 20_uc, 230_uc))), //purple
	Cluster(Pixel(Color(230_uc, 230_uc, 230_uc))), //white
};

vector<Pixel> allPixels;

const unsigned int PIXELS_COUNT = 2500;

const double AXIS_OFFSET = 1.85 / 256.0;


