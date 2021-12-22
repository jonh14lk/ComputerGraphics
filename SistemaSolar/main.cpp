#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

struct color
{
  float r, g, b;
  color() {}
  color(float r, float g, float b) : r(r), g(g), b(b) {}
};
struct planet
{
  int year, day, speed;
  float width, height, size;
  color c;

  planet(float width, float height, float size, int speed, color c) : width(width), height(height), size(size), speed(speed), c(c)
  {
    year = 0;
    day = 0;
  }
  void move(char key)
  {
    if (key == 'y' || key == 'y')
    {
      day += speed;
      year += speed;
    }
    if (key == 'd' || key == 'D')
    {
      day += speed;
      year -= speed;
    }
  }
  void draw()
  {
    glPushMatrix();
    glColor3f(c.r, c.g, c.b);
    glRotatef(year, 0, -1, 0);
    glTranslatef(width, height, 0.0);
    glRotatef(day, 0, 1, 0);
    glutSolidSphere(size, 100, 50);
    glPopMatrix();
  }
};
struct planet_moon
{
  int year, day, speed;
  int year2, day2, speed2;

  planet_moon()
  {
    year = 0;
    day = 0;
    day2 = 0;
    speed = 1;
    speed2 = 5;
  }
  void move(char key)
  {
    if (key == 'y' || key == 'y')
    {
      day += speed;
      year += speed;
      day2 += speed2;
    }
    if (key == 'd' || key == 'D')
    {
      day += speed;
      year -= speed;
      day2 += speed2;
    }
  }
  void draw()
  {
    glPushMatrix();
    glColor3f(0.58, 0.29, 0);
    glRotatef(year, 0, -1, 0);
    glTranslatef(-2, -1, 0);
    glPushMatrix();
    glRotatef(day, 0, 1, 0);
    glutSolidSphere(0.2, 100, 50);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 0, 0);
    glRotatef(day2, 0, 1.0, 0); // lua girando no eixo x
    glTranslatef(-0.5, 0.1, 0);
    glutSolidSphere(0.05, 100, 50);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.6, 0.0);
    glRotatef(day2, 0.5, 1.0, 0); // lua girando no eixo xy
    glTranslatef(-0.5, 0, 0);
    glutSolidSphere(0.05, 100, 50);
    glPopMatrix();

    glPopMatrix();
  }
};
struct sun
{
  sun() {}
  void draw()
  {
    glPushMatrix();
    glColor3f(1.0, 1.0, 0);
    glRotatef(0, 1.0, 0, 0);
    glRotatef(0, 0, 0, 1.0);
    glutSolidSphere(0.8, 100, 100);
    glPopMatrix();
  }
};

sun s;
planet_moon m;
vector<planet> v;

void create() // planetas sem lua
{
  vector<color> colors{color(0.5, 0.5, 0.5), color(1.0, 0.3, 0), color(0, 0, 1), color(1, 0, 0), color(0.58, 0.29, 0)};
  v.push_back(planet(-2.5, -0.4, 0.15, 5, color(0.5, 0.5, 0.5)));
  v.push_back(planet(3.0, 0, 0.30, 2, color(0, 0, 1)));
  v.push_back(planet(2.0, 0.2, 0.10, 7, color(1, 0, 1)));
  v.push_back(planet(-1.0, 0.5, 0.15, 1, color(0.8, 0.4, 0)));
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  s.draw();
  for (auto &i : v)
    i.draw();
  m.draw();
  glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
  for (auto &i : v)
    i.move(key);
  m.move(key);
  glutPostRedisplay();
}
void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // posicao da camera
}
void init()
{
  glClearColor(0.0, 0.6, 0.8, 0.9); // cor do background
  glEnable(GL_DEPTH_TEST);          // ativar profundidade
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1000, 800);
  glutCreateWindow("Sistema Solar");
  glutInitWindowPosition(100, 100);
  create();
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}