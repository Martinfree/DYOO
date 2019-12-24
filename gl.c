/*
 * This program was made like simple example how OpenGl works
 *
 * @2019
*/


#include <stdlib.h>
#include <stdio.h>

#include <GL/gl.h>
#include <GL/glut.h>

#define POINT GL_POINTS
#define LINE GL_LINES

char choice;
int range;

struct object
{
    float point_p[2];
};

void math_funcs(struct object *p)
{
    float y;
    float x = -range;
    if(choice=='1'){
        for(float x=-range;x<=range;x++)
        {
            p->point_p[0]=x/100;
            p->point_p[1]=(x*x)/100;
            p+=sizeof(char);
        }
            p->point_p[0]=x/100;
            p->point_p[1]=(x*x)/100;
            p+=sizeof(char);
    } else if(choice=='2'){
        for(float x=-range;x<=range;x++)
        {
            p->point_p[0]=x/100;
            p->point_p[1]=-(x*x)/100;
            p+=sizeof(char);
        }
            p->point_p[0]=x/100;
            p->point_p[1]=-(x*x)/100;
            p+=sizeof(char);
         
    } else printf("You stupid fuck");
}

void randomize(float* a,float b)
{
        srand((int)time(NULL));
        *a= b+0.1;
        a+=sizeof(char);
        *a= b-0.4;
        
        a+=sizeof(char);
        *a= b+0.75;
        a+=sizeof(char);
        *a= b-0.5;
}

int cempl(int lines, int points)
{
    glLineWidth(3.0);
    glBegin(LINE);
        glColor3f(1.0,1.0,1.0);
            glVertex2f(0.5,0.0);
            glVertex2f(-0.5,0.0);
            glVertex2f(0.0,-0.5);
            glVertex2f(0.0,0.5);

    glEnd();
     if (lines==NULL && points==NULL) return -1;

    struct object obj[2*range+1];
    math_funcs(obj);

    if (lines!=NULL)
    {
       
    glLineWidth(5.0);
    
    glBegin(LINE);
        glColor3f(1.0,1.0,1.0);
        for(int i=0;i<2*range;i++)
        {
            glVertex2f(obj[i].point_p[0],obj[i].point_p[1]);
            glVertex2f(obj[i+1].point_p[0],obj[i+1].point_p[1]);
        }
    glEnd();
    }
   
    if (points!=NULL)
    {
    
    glPointSize(3.0);
    glBegin(POINT);
        for(int i=0;i<2*range+1;i++)
        {
            glColor3f(0.0,0.0,0.0);
            glVertex2fv(obj[i].point_p);
        }
    glEnd();
    glFlush();
         
    
    }
    
    return 0;
}



void draw()
{
    glClearColor(0.0, 0.0 , 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
       
    if(cempl(1,1)==-1) printf("ERROR: No data to draw\n");


    return;
}

void init_window(int argc, char** argv)
{

    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100,140);
    glutCreateWindow("DYOO  [0.1 build]");
    glutDisplayFunc(draw);
    glutMainLoop();

}


int main(int argc, char** argv) 
{
    printf("Please choose function to draw\n'1' x^2\n'2' -x^2\n");
    choice=getchar();
    printf("select the range - from 0 to 10\n");
    range = getchar();
    scanf("%d", &range);
    init_window(argc,argv);

    return 0;
}
