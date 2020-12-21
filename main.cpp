#include "Game.h"
#include <GL/glut.h>

Game game;

void render() {
    glClear(GL_COLOR_BUFFER_BIT);

    int time = glutGet(GLUT_ELAPSED_TIME);
    game.update(time);
    game.render(time);

    glutSwapBuffers();
}

void init() {
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    int time = glutGet(GLUT_ELAPSED_TIME);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    game.load(time);
}

void keyboard(int key, int x, int y) {
    int time = glutGet(GLUT_ELAPSED_TIME);

    game.keyboard(time, key, x, y);
}

void keyboard_up(int key, int x, int y) {
    int time = glutGet(GLUT_ELAPSED_TIME);

    game.keyboard_up(time, key, x, y);
}

void reshape(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 1300, 0, 1000);

    glViewport(0, 0, width, height);
}

void keyboardFunc(unsigned char key, int x, int y){
    game.keyboardFunc(key);
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(800, 600);
    glutCreateWindow("Pacman 2020");

    glClearColor(0, 0, 0, 0);
    init();
    glutDisplayFunc(render);
    glutIdleFunc(render);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboardFunc);
    glutSpecialFunc(keyboard);
    glutSpecialUpFunc(keyboard_up);

    glutMainLoop();
}