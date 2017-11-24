#include <iostream>
#include <GLUT/GLUT.h>
#include <cstdlib>
#include <cmath>

using namespace std;

const int X_COORD = 25;// X - размерность ] должны
const int Y_COORD = 25;// Y - размерность ] быть равными
const float ITERATIONS = 0.00005;// прорисовка графика (чем меньше тем лучше)

int x_off = X_COORD / 2;// начало
int y_off = Y_COORD / 2;// оси координат

//исходная функция
#define expr x

void drawgrid(float SERIF_OFFSET, float SERIF_DISTANCE) {
    
    
    //SERIF_DISTANCE - расстояние между засечками
    //SERIF_OFFSET - высота засечки
    glBegin(GL_LINES);
    //задаем цвета осей
    glColor3f(0.0, 0.0, 0.0);
    
    //рисуем координатные оси
    //горизонталь
    glVertex2f(0.0, Y_COORD / 2);
    glVertex2f(X_COORD, Y_COORD / 2);
    //засечки по горизонтали
    int p = X_COORD / 2;
    for(int i = X_COORD / 2; i < X_COORD; i += SERIF_DISTANCE, p -= SERIF_DISTANCE) {
        //засечка слева от оси y
        glVertex2f(i, Y_COORD / 2);
        glVertex2f(i, Y_COORD / 2 + SERIF_OFFSET);
        
        //засечка справа от оси y
        glVertex2f(p, Y_COORD / 2);
        glVertex2f(p, Y_COORD / 2 + SERIF_OFFSET);
        
        //i - координата засечек от центра >0
        //p -координата засечек от центра <0
    }
    //вертикаль
    int t = Y_COORD / 2;
    glVertex2f(X_COORD / 2, Y_COORD);
    glVertex2f(X_COORD / 2, 0.0);
    //засечки по вертикали
    for(int i = Y_COORD / 2; i < Y_COORD; i += SERIF_DISTANCE, t -= SERIF_DISTANCE) {
        glVertex2f(X_COORD / 2, i);
        glVertex2f(Y_COORD / 2 + SERIF_OFFSET, i);
        
        glVertex2f(X_COORD / 2, t);
        glVertex2f(Y_COORD / 2 + SERIF_OFFSET, t);
    }
    glEnd();
}

void drawfunc(float val1, float val2) {
    //рисуем график
    glBegin(GL_POINTS);
    float j = 0;
    glColor3f(0.8, 0.0, 0.8);
    for(float x = val1; x < val2; x += ITERATIONS) {
        //перерасчитываем координаты
        j = sin(x/2)*sin(x/2)*sin(x/2)-sqrt(x);
        glVertex2f(x_off + x, y_off + j);//не убирать x и y!! это оффсет по осям!
    }
    glEnd();
}

void funcinfo(float val1, float val2) {
    //информация о графике
    float max = -10, min = 10, coord;
    
    for(float x = val1; x <= val2; x++) {
        coord = sin(x);
        if (max < coord) max = coord;
        if (min > coord) min = coord;
    }
    cout << "Max = " << max << endl << "Min = " << min << endl;
    //    cout << "Sin(PI) = " << sin(M_PI) << endl;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    drawgrid(1, 1);
    drawfunc(-M_PI/2, 12*M_PI);
    funcinfo(-M_PI/2, 12*M_PI);
    
    
    
    glutSwapBuffers();
    
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Machines Lab 3");
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //пространство координат
    glOrtho(0.0, X_COORD, 0.0, Y_COORD, -1.0, 1.0);
    
    glutDisplayFunc(display);
    glutMainLoop();
}



























//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <GLUT/GLUT.h>
////#include <>
//
//#include<math.h>
//
//
//const GLfloat factor =0.1f;
//
//void displayFunc()
//{
//    GLfloat x;
//
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    //{
//
//        glColor3f(1.0f, 1.0f, 1.0f);
//        glBegin(GL_LINES);
//        //{
//            // x-axis
//            glVertex3f(-100.0f, 0.0f, 0.0f);
//            glVertex3f(100.0f, 0.0f, 0.0f);
//
//            // y-axis
//            glVertex3f(0.0f, -100.0f, 0.0f);
//            glVertex3f(0.0f, 100.0f, 0.0f);
//
//            glEnd();
//            glBegin(GL_LINE_STRIP);
//            for (x = -2.0f / factor; x < 2.0f / factor; x += 0.05f)
//            {
//                glVertex2f((x*factor), sin(x)*sin(x) + cos(x)*cos(x)*cos(x));
//            }
//            glEnd();
//            glFlush();
//        //}
//    //}
//
//    glFlush();
////    glutSwapBuffers();
//}
//
//
//
//
////int main(int argc, char* argv[])
////{
////    glutInit(&argc, argv);
////    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
////    glutInitWindowPosition(100, 100);
////    glutInitWindowSize(640, 480);
////    glutCreateWindow("Sin^2(x)+ Cos^3(x)");
////    glutDisplayFunc(&myDisplay);
////    glutMainLoop();
////    return 0;
////
////}
//
//
//int main() {
//
//    GLFWwindow *window;
//
//    if(!glfwInit()) {
//        return -1;
//    }
//
//    window = glfwCreateWindow(1280, 720, "Sin^2(x)+ Cos^3(x)", NULL, NULL);
//
//    if(!window) {
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(window);
//
//
//    while (!glfwWindowShouldClose(window)) {
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        displayFunc();
//
//        glfwSwapBuffers(window);
//
//        glfwPollEvents();
//    }
//    glfwTerminate();
//
//
//
//    return 0;
//}
//
