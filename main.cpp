#include "Game.h"
#include <GL/glut.h>

Game game;

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	int time = glutGet(GLUT_ELAPSED_TIME);
    game.update(time);
    game.render(time);

	glutSwapBuffers();
}

void init()
{
	int time = glutGet(GLUT_ELAPSED_TIME);

	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    game.load(time);
}

void keyboard(int key, int x, int y)
{
	int time = glutGet(GLUT_ELAPSED_TIME);

	game.keyboard(time, key, x, y);
}

void keyboard_up(int key, int x, int y)
{
	int time = glutGet(GLUT_ELAPSED_TIME);

	game.keyboard_up(time, key, x, y);
}

void reshape(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspestRatio = (float)width / height;
	if (width > height)
	{
		gluOrtho2D(0, 1000 * aspestRatio, 0, 1000);
	}
	else
	{
		gluOrtho2D(0, 1000, 0, 1000 / aspestRatio);
	}

	glViewport(0, 0, width, height);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutCreateWindow("Game");

	glClearColor(1.0, 1.0, 1.0, 0.0);
	init();

	glutDisplayFunc(render);
	glutIdleFunc(render);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);
	glutSpecialUpFunc(keyboard_up);

	glutMainLoop();
}