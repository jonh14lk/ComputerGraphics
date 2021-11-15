#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

const int width = 750;
const int height = 750;

struct square
{
  float x1, y1, x2, y2;
  float r, g, b;

  float rand_float()
  {
    float x = rand() % 100;
    x /= 100;
    return x;
  }
  square(float x1, float y1, float x2, float y2) : x1(x1), y1(y1), x2(x2), y2(y2)
  {
    r = rand_float(), g = rand_float(), b = rand_float();
  }
  void draw()
  {
    float x = x1, y = y1;
    for (int i = 0; i < 4; i++)
    {
      glColor3f(r, g, b);
      glVertex3f(x, y, 0.0);
      (x == x1) ? x = x2 : (y == y1) ? y = y2
                                     : x = x1;
    }
  }
};
struct state
{
  vector<square> v;
  int sz, id, back_id;

  state()
  {
    float x = -1.0, y = -0.9;
    while (y <= 1.0)
    {
      v.push_back(square(x, 0.0, y, 0.1));
      x += 0.19, y += 0.19;
    }
    id = 0, back_id = -5, sz = v.size();
  }
  void nxt_state()
  {
    if (back_id >= 0)
      v[back_id].y1 -= 0.1, v[back_id].y2 -= 0.1;
    v[id].y1 += 0.1, v[id].y2 += 0.1;
    id = (id + 1) % sz;
    back_id = (back_id + 1) % sz;
  }
};

stack<state> st;
state current;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glBegin(GL_QUADS);
  for (auto &i : current.v)
  {
    i.draw();
  }
  glEnd();
  glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
  if (key == 's' || key == 'S')
  {
    st.push(current);
    current.nxt_state();
  }
  else if ((key == 'a' || key == 'A') && st.size())
  {
    current = st.top();
    st.pop();
  }
  display();
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(width, height);
  glutCreateWindow("Ola - CG UFAL");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
