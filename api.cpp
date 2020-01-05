/*
 * API for using OpenGl to draw
 *
 * @2019
*/

//C libraries
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//C++ libraries
#include <iostream>
#include <vector>
#include <iterator>
#include <string>

//Graphoc libraries
#include <GL/gl.h>
#include <GL/glut.h>


#define POINT GL_POINTS
#define LINE GL_LINES
#define FUNCTION "function"


namespace functions
{

float range=4;
// class for functions => ax^4+bx^3+cx^2+dx+constant=0;
class Function{
public:
    float x;
    float a;
    float b;
    float c;
    float d;
    float constant;
    
    int init_obj(){
    return 0;
    }
    
    int draw_obj(int line, int point){
    glLineWidth(3.0);
            
    glBegin(LINE);
            
    glColor3f(1.0,1.0,1.0);
    glVertex2f(0.5,0.0);
    glVertex2f(-0.5,0.0);
    glVertex2f(0.0,-0.5);
    glVertex2f(0.0,0.5);

    glEnd();
    if (line==NULL && point==NULL) return -1;
    
    
    if (line!=NULL){
       auto it = points_x.begin();
       auto at = points_y.begin();
       auto it1 = it+1;
       auto at1 = at+1;
       glLineWidth(5.0);
        
        glBegin(LINE);
        
        while(it<--points_x.end()){
        glColor3f(1.0,1.0,1.0);
        glVertex2f(*it,*at);
        glVertex2f(*it1,*at1);
        printf("%f,%f\n",*it,*at);
        it++;
        at++;
        it1++;
        at1++;
        }
        glEnd();}
    
    if (point!=NULL){
       auto it = points_x.begin();
       auto at = points_y.begin();
       glPointSize(3.0);
       
       glBegin(POINT);
       
       while(it<points_x.end()){
       glColor3f(1.0,1.0,1.0);
       glVertex2f(*it,*at);
       it++;
       at++;
       }
       glEnd();
       
       glFlush();
       return 0;}
    }
    
    void setup_obj(){
    glClearColor(0.0, 0.0 , 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();}
    
    void math_func(float i){
    float y;
    if (i!=-abs(x)){
        points_x.push_back(i/100);
        y=a*pow(i,4)+b*pow(i,3)+c*pow(i,2)+d*i+constant;
        points_y.push_back(y/100);
        i--;
        math_func(i);}
    else {
        points_x.push_back(i/100);
        y=a*pow(i,4)+b*pow(i,3)+c*pow(i,2)+d*i+constant;
        points_y.push_back(y/100);
        return;
    }
}    
private:
    std::vector <float> points_x;
    std::vector <float> points_y;

};



}

#define OBJECT functions::Function

OBJECT obj;

void draw(){
    glClearColor(0.0, 0.0 , 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    obj.draw_obj(1,1);
}
//windows extensions
namespace GlutWindow{
    void init_window(std::string param){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100,140);
    glutCreateWindow("DYOO  [0.1 build]");
    glutDisplayFunc(draw);
    glutMainLoop();}
}


int main(int argc, char** argv){
    glutInit(&argc , argv);
    std::vector <OBJECT> objects;
    
    float k;
    
    objects.push_back(obj);
    
    printf("Please setup function\n x^4+bx^3+cx^2+dx+constant=0;\na=");
    scanf("%f", &obj.a);
    printf("b=");
    scanf("%f", &obj.b);
    printf("c=");
    scanf("%f", &obj.c);
    printf("d=");
    scanf("%f", &obj.d);
    printf("constant=");
    scanf("%f", &obj.constant);
    printf("x=");
    scanf("%f", &obj.x);
 
    printf("function===> %fx^4+%fx^3+%fx^2+%fx+%f\n for %f to %f\n",obj.a,obj.b,obj.c,obj.d,obj.constant,-obj.x,obj.x);
    
    obj.math_func(abs(obj.x));
    
    GlutWindow::init_window(FUNCTION);
    return 0;
}
