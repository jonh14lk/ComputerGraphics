#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

int eixoy, eixox, largura, altura;
int limit = 0;

void display(void)
{
  glPushMatrix();
  glRotatef((GLfloat)eixoy, 0.0, 1.0, 0.0);
  glRotatef((GLfloat)eixox, 1.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBegin(GL_QUADS); // Desenhar cubo da base da casa

  if (limit >= 1)
  {
    glColor3f(0.0, 0.0, 1.0); // Azul
    glVertex3f(15.0f, 15.0f, -15.0f);
    glVertex3f(-15.0f, 15.0f, -15.0f);
    glVertex3f(-15.0f, 15.0f, 15.0f);
    glVertex3f(15.0f, 15.0f, 15.0f);
  }
  if (limit >= 2)
  {
    glColor3f(1.0, 0.0, 0.0); // Vermelho
    glVertex3f(15.0f, -15.0f, 15.0f);
    glVertex3f(-15.0f, -15.0f, 15.0f);
    glVertex3f(-15.0f, -15.0f, -15.0f);
    glVertex3f(15.0f, -15.0f, -15.0f);
  }
  if (limit >= 3)
  {
    glColor3f(1.0, 1.0, 0.0); // Amarelo
    glVertex3f(15.0f, 15.0f, 15.0f);
    glVertex3f(-15.0f, 15.0f, 15.0f);
    glVertex3f(-15.0f, -15.0f, 15.0f);
    glVertex3f(15.0f, -15.0f, 15.0f);
  }
  if (limit >= 4)
  {
    glColor3f(0.0, 1.0, 0.0); // Verde
    glVertex3f(15.0f, -15.0f, -15.0f);
    glVertex3f(-15.0f, -15.0f, -15.0f);
    glVertex3f(-15.0f, 15.0f, -15.0f);
    glVertex3f(15.0f, 15.0f, -15.0f);
  }
  if (limit >= 5)
  {
    glColor3f(0.8, 0.6, 0.1); // Laranja
    glVertex3f(-15.0f, 15.0f, 15.0f);
    glVertex3f(-15.0f, 15.0f, -15.0f);
    glVertex3f(-15.0f, -15.0f, -15.0f);
    glVertex3f(-15.0f, -15.0f, 15.0f);
  }
  if (limit >= 6)
  {
    glColor3f(1.0, 0.0, 1.0); // ciano
    glVertex3f(15.0f, 15.0f, -15.0f);
    glVertex3f(15.0f, 15.0f, 15.0f);
    glVertex3f(15.0f, -15.0f, 15.0f);
    glVertex3f(15.0f, -15.0f, -15.0f);
  }

  glEnd(); // Fim do cubo

  glBegin(GL_TRIANGLES);

  if (limit >= 7)
  {
    glColor3f(0.0, 1.0, 0.0); // Verde
    glVertex3f(0.0f, 30.0f, 0.0f);
    glVertex3f(-15.0f, 15.0f, 15.0f);
    glVertex3f(15.0f, 15.0f, 15.0f);
  }
  if (limit >= 8)
  {
    glColor3f(1.0, 0.0, 0.0); // Vermelho
    glVertex3f(0.0f, 30.0f, 0.0f);
    glVertex3f(15.0f, 15.0f, 15.0f);
    glVertex3f(15.0f, 15.0f, -15.0f);
  }
  if (limit >= 9)
  {
    glColor3f(1.0, 1.0, 0.0); // Amarelo
    glVertex3f(0.0f, 30.0f, 0.0f);
    glVertex3f(15.0f, 15.0f, -15.0f);
    glVertex3f(-15.0f, 15.0f, -15.0f);
  }
  if (limit >= 10)
  {
    glColor3f(1.0, 0.0, 1.0); // ciano
    glVertex3f(0.0f, 30.0f, 0.0f);
    glVertex3f(-15.0f, 15.0f, -15.0f);
    glVertex3f(-15.0f, 15.0f, 15.0f);
  }

  glEnd();

  glFlush();
  glPopMatrix();
  glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
  if (key == 'y')
  {
    eixoy = (eixoy + 5) % 360;
  }
  else if (key == 'Y')
  {
    eixoy = (eixoy - 5) % 360;
  }
  else if (key == 'x')
  {
    eixox = (eixox + 5) % 360;
  }
  else if (key == 'X')
  {
    eixox = (eixox - 5) % 360;
  }
  else if (key == 'r') // desenha mais uma parte
  {
    limit++;
    cout << limit << endl;
  }
  else if (key == 'R') // retira uma parte
  {
    limit--;
    cout << limit << endl;
  }
  glutPostRedisplay();
}
void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glOrtho(-50, 50, -50, 50, -50, 50);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}
void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  largura = w;
  altura = h;
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Casa - CG UFAL");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}