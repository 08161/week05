#include <GL/glut.h>
#include <stdio.h>
float vx[2000],vy[2000];
int N=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0,1,0);
    glBegin(GL_TRIANGLE_FAN);
    for(int i=0;i<N;i++)
    {
        glVertex2f(vx[i],vy[i]);
    }
    glEnd();
    glutSwapBuffers();
}
void mouse(int buttin ,int state,int x,int y)
{

}
void motion(int x,int y)///mouse motion的函式
{
    printf("%d %d\n",x,y);
    vx[N]=(x-150)/150.0;
    vy[N]=-(y-150)/150.0;
    N++;
    display();
}
int main(int argc,char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("mouse week05");

    glutDisplayFunc(display);
    glutMotionFunc(motion);///移動時的函式
    glutMainLoop();
}
