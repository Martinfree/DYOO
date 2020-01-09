/*
 * API for using OpenGl to draw
 *
 * @2019
*/

#include "functions.h"

#define OBJECT functions::Function

OBJECT obj;
//GtkGLArea *area;
extern "C"{
G_MODULE_EXPORT void draw(GtkGLArea *area){
   if (gtk_gl_area_get_error(area) != NULL)
    g_print("ERROR"); 
    glClearColor(0.0, 0.0 , 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    obj.x=10;
    obj.draw_obj(1,1);
    glFlush();
   //glLoadIdentity();
    
}}

//windows extensions
/*
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
    
    
    GlutWindow::init_window(FUNCTION);
    return 0;
}
*/
