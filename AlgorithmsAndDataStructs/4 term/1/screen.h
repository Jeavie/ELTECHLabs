//
// Created by jeavie on 07.02.2018.
//

#pragma once
#include "shape.h"
//enum { XMAX = 80, YMAX = 40 };
const int XMAX = 80, YMAX = 40;
class point { //Точка
public:
    int x, y;
//    point() {};
    point(int a = 0, int b = 0) :x(a), y(b) { }
};
//Функции работы с экраном
void put_point(int a, int b); //Вывод точки
void put_point(point p) { put_point(p.x, p.y); }
extern void put_line(int, int, int, int); //Вывод линии
extern void put_line(point a, point b) { put_line(a.x, a.y, b.x, b.y); }
extern void screen_init();    //Создание экрана
extern void screen_destroy(); //Удаление экрана
extern void screen_refresh(); //Обновление экрана
extern void screen_clear();   //Очистка экрана