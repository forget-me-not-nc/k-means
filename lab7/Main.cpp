#include <ctime>
#include <chrono>

#include "Resources.h"

//--------------------------------

void changeViewPort(int w, int h);
void render();
void update();
void customInit();

unsigned char random(int min, int max);
void initPixels(vector<Pixel>& p);
void drawPixels(vector<Pixel>& p);
void drawClusterCenters(vector<Cluster>& c);
double transfer(unsigned char v);

//--------------------------------

double angle = 0.0;

bool initFlag = false;
bool done = false;

K_means algorithm;

//--------------------------------

int main(int argc, char* argv[])
{
	srand((unsigned int)time(NULL));

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(800, 800);

	glutCreateWindow("Lab 7");

	customInit();

	glutReshapeFunc(changeViewPort);
	glutDisplayFunc(render);
	glutIdleFunc(update);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		fprintf(stderr, "GLEW error");
		return 1;
	}

	glutMainLoop();

	return 0;
}

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	if (!initFlag)
	{
		glPushMatrix();

			drawPixels(algorithm.pixels);
			drawClusterCenters(algorithm.clusters);

		glPopMatrix();

		glutSwapBuffers();

		initFlag = true;

		Sleep(3000);

		return;
	}
	else
	{
		if (algorithm.isComputing()) algorithm.iterate();
		else if (!algorithm.isComputing() && !done)
		{
			MessageBoxA(GetActiveWindow(), "Computing is done!!", "Alert!", MB_OK);
			
			done = true;
		}

		glPushMatrix();

			glRotated(angle, 0, 1, 0);

			drawPixels(algorithm.pixels);
			drawClusterCenters(algorithm.clusters);

		glPopMatrix();

		glutSwapBuffers();
	}
}

void update()
{
	angle += 0.2f;
	angle = fmod(angle, 360);

	glutPostRedisplay();
}

void customInit()
{
	gluLookAt(0.0, 0.0, 0.0, 2.0, 0.3, -1.5, 0.0, 1.0, 0.0);

	initPixels(allPixels);

	algorithm = K_means(clusters, allPixels);

	glScalef(0.8, 0.8, 0.8);
}

unsigned char random(int min, int max)
{
	return static_cast<unsigned char>(min + rand() % ((max + 1) - min));
}

void initPixels(vector<Pixel>& p)
{
	for (unsigned int i = 0; i < PIXELS_COUNT; i++)
	{
		p.push_back(Pixel(Color(
			random(0, 255),
			random(0, 255),
			random(0, 255)
		))
		);
	}
}

void drawClusterCenters(vector<Cluster>& c)
{
	glPointSize(15);
	glEnable(GL_POINT_SMOOTH);

	glBegin(GL_POINTS);

	for (unsigned char i = 0; i < c.size(); i++)
	{
		glColor3ub(c[i].center.selfColor.r, c[i].center.selfColor.g, c[i].center.selfColor.b);

		glVertex3d(
			transfer(c[i].center.selfColor.r),
			transfer(c[i].center.selfColor.g),
			transfer(c[i].center.selfColor.b)
		);
	}

	glEnd();

	glDisable(GL_POINT_SMOOTH);
	glPointSize(1);
}

void drawPixels(vector<Pixel>& p)
{
	glPointSize(5);
	glEnable(GL_POINT_SMOOTH);

	glBegin(GL_POINTS);

		for (unsigned int i = 0; i < p.size(); i++)
		{
			glColor3ub(p[i].approximateColor.r, p[i].approximateColor.g, p[i].approximateColor.b);

			glVertex3d(
				transfer(p[i].selfColor.r), 
				transfer(p[i].selfColor.g),
				transfer(p[i].selfColor.b)
			);
		}
		
	glEnd();

	glDisable(GL_POINT_SMOOTH);
	glPointSize(1);
}

double transfer(unsigned char v)
{
	return ((double)v * AXIS_OFFSET) - 1.0;
}