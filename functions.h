/*
 * API for using OpenGl to draw
 *
 * @2019
*/
#include "headers.h"

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
    std::vector <float> points_x;
    std::vector <float> points_y;

    
    int init_obj(){
    return 0;
    }
    
    int draw_obj(int line, int point){
    points_x.clear();
    points_y.clear();
    math_func(abs(x));
    glClearColor(0.0, 0.0 , 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLineWidth(1.5);
            
    glBegin(LINE);
            
    glColor3f(1.0,1.0,1.0);
    glVertex2f(0.5,0.0);
    glVertex2f(-0.5,0.0);
    glVertex2f(0.0,-0.5);
    glVertex2f(0.0,0.5);

    glEnd();

    glBegin(GL_TRIANGLES);
    
    glVertex2f(0.5,0.0);
    glVertex2f(0.48,-0.01);
    glVertex2f(0.48,0.01);
    
    glVertex2f(0.0,0.5);
    glVertex2f(0.01,0.48);
    glVertex2f(-0.01,0.48);
        glEnd();
    if (line==0 && point==0) return -1;
    
    
    if (line!=0){
       auto it = points_x.begin();
       auto at = points_y.begin();
       auto it1 = it+1;
       auto at1 = at+1;
       glLineWidth(5.0),*it,*at;
        
        glBegin(LINE);
        
        while(it<--points_x.end()){
        glColor3f(1.0,1.0,1.0);
        glVertex2f(*it,*at);
        glVertex2f(*it1,*at1);
        it++;
        at++;
        it1++;
        at1++;
        }
        glEnd();}
    
    if (point!=0){
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
       
       return 0;}
    return 0;
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
};



}
