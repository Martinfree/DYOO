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


struct line{
    float begin_point[2];
    float end_point[2];
};

struct point{
    float point_p[2];
};


struct object
{
    struct point P;
    struct line L; 
};

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
    if (lines==NULL && points==NULL) return -1;

    struct object obj;
    
    if (lines!=NULL)
    {
        randomize(&obj.L,0.2);
        printf("BRGf%f:::f%f\n",obj.L.begin_point[0],obj.L.begin_point[1]);
        printf("ENDf%f:::f%f\n",obj.L.end_point[0],obj.L.end_point[1]);
        printf("POINTSf%f:::f%f\n",obj.P.point_p[0],obj.P.point_p[1]);
        printf("\n\n\n\n%d",sizeof(obj));
        
    //glLineWidth(5.0);
    
    glBegin(LINE);
        glColor3f(1.0,1.0,1.0);
        glVertex2fv(obj.L.begin_point);
        glVertex2fv(obj.L.end_point); 
    glEnd();
   
    }
    if (points!=NULL)
    {

    glBegin(POINT);
        glColor3f(1.0,1.0,1.0);
        glVertex2fv(obj.P.point_p);
    glEnd();
     
    
    }
    /*
        struct line l1;
        randomize(&l1,0.2);
        glColor3f(1.0,1.0,1.0);
        glVertex2fv(l1.point1);
        glVertex2fv(l1.point2);
        
        struct line l2;
        randomize(&l2,0.6);
        glVertex2fv(l2.point1);
        glVertex2fv(l2.point2);
        
        struct line l3;
        randomize(&l3,0.8);
        glVertex2fv(l3.point1);
        glVertex2fv(l3.point2);
    */
    
    return 0;
}



void draw()
{
    glClearColor(0.0, 0.0 , 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    

        if(cempl(1,1)==-1)
        {
            printf("ERROR: No data to draw\n");
        }


    glFlush();
    return;
}

void init_window(int argc, char** argv)
{

    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 140);
    glutCreateWindow("Draw  [0.1 build]");
    glutDisplayFunc(draw);
    glutMainLoop();

}


int main(int argc, char** argv) 
{
    init_window(argc,argv);

    return 0;
}
