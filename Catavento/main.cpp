#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)

struct vertex
{
  float x, y;
  vertex(float x, float y) : x(x), y(y) {}
  void rotate(float a, bool clockwise)
  {
    if (!clockwise)
      a = 360 - a;
    a = (a * PI) / 180;
    float new_x = (cos(a) * x) + ((sin(a) * -1) * y);
    float new_y = (sin(a) * x) + (cos(a) * y);
    x = new_x;
    y = new_y;
  }
  void translate(float a, float b)
  {
    x -= a;
    y -= b;
  }
};
struct color
{
  float r, g, b;
  color(float r, float g, float b) : r(r), g(g), b(b) {}
};
struct triangle
{
  color c;
  vertex v1, v2, v3;
  triangle(color c, vertex v1, vertex v2, vertex v3) : c(c), v1(v1), v2(v2), v3(v3) {}
  void draw()
  {
    glColor3f(c.r, c.g, c.b);
    glBegin(GL_TRIANGLES);
    glVertex2f(v1.x, v1.y);
    glVertex2f(v2.x, v2.y);
    glVertex2f(v3.x, v3.y);
    glEnd();
  }
  void rotate(float ang, bool clockwise)
  {
    v2.translate(v1.x, v1.y);
    v3.translate(v1.x, v1.y);
    v2.rotate(ang, clockwise);
    v3.rotate(ang, clockwise);
    v2.translate(-v1.x, -v1.y);
    v3.translate(-v1.x, -v1.y);
  }
};

vector<triangle> v;

void create_triangles()
{
  v.clear();
  v.push_back({color(1.0, 1.0, 1.0), vertex(250.0f, 250.0f), vertex(230.0f, 200.0f), vertex(270.0f, 200.0f)});
  v.push_back({color(1.0, 0.0, 0.0), vertex(250.0f, 250.0f), vertex(300.0f, 230.0f), vertex(300.0f, 270.0f)});
  v.push_back({color(0.0, 1.0, 0.0), vertex(250.0f, 250.0f), vertex(230.0f, 300.0f), vertex(270.0f, 300.0f)});
  v.push_back({color(0.0, 0.0, 1.0), vertex(250.0f, 250.0f), vertex(200.0f, 270.0f), vertex(200.0f, 230.0f)});
}
void draw_base()
{
  glColor3f(1.0, 1.0, .0);
  glBegin(GL_POLYGON);
  glVertex3f(249.0f, 250.0f, -1.0f);
  glVertex3f(251.0f, 250.0f, -1.0f);
  glVertex3f(249.0f, 100.0f, -1.0f);
  glVertex3f(251.0f, 100.0f, -1.0f);
  glEnd();
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  draw_base();
  for (auto &i : v)
  {
    i.draw();
  }
  glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
  if (key == 's' || key == 'S')
  {
    for (auto &i : v)
    {
      i.rotate(30, true);
    }
  }
  else if (key == 'a' || key == 'A')
  {
    for (auto &i : v)
    {
      i.rotate(30, false);
    }
  }
  glutPostRedisplay();
}
void init()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0);
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 400);
  glutInitWindowPosition(200, 200);
  glutCreateWindow("Flor de Abril");
  create_triangles();
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}