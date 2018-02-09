//
// Created by jeavie on 09.02.2018.
//

#pragma once
#include <iostream>
#include <string>
#include "screen.h"

//поддержка экрана в форме матрицы символов

char screen[XMAX][YMAX];

enum color { black = '*', white = '.' };

void screen_init() {
    for (auto y = 0; y < YMAX; ++y)
        for (auto &x : screen[y])
            x = white;
}

void screen_destroy() {
    for (auto y = 0; y < YMAX; ++y)
        for (auto &x : screen[y])
            x = black;
}

bool on_screen(int a, int b) { //проверка попадания на экран
    return 0 <= a && a < XMAX && 0 <= b && b < YMAX;
}

void put_line(int x0, int y0, int x1, int y1) { // рисование отрезка по пряямой по алгоритму Брезенхэма
    int dx = 1;
    int a = x1 - x0;
    if (a < 0) dx = -1, a = -a;
    int dy = 1;
    int b = y1 - y0;
    if (b < 0) dy = -1, b = -b;
    int two_a = 2*a;
    int two_b = 2*b;
    int xcrit = -b + two_a;
    int eps = 0;

    for (;;) { // формирование прямой линии по точкам
        put_point(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        if (eps <= xcrit) x0 += dx, eps += two_b;
        if (eps >= a || a < b) y0 += dy, eps -= two_a;
    }
}

void screen_clear() { // очистка экрана
    screen_init();
}

void screen_refresh() {
    for (int y = YMAX - 1; 0 <= y; --y) { // с верхней строки до нижней
        for (auto x : screen[y]) // от левого столбца до правого
            std::cout << x;
        std::cout << '\n';
    }
}

//2. Библиотека фигур
struct shape {
    static shape* list; // начало списка фигур (одно на все фигуры)
    shape * next;
    shape() { next = list; list = this; }
    virtual point north() const = 0;
    virtual point south() const = 0;
    virtual point east() const = 0;
    virtual point west() const = 0;
    virtual point neast() const = 0;
    virtual point seast() const = 0;
    virtual point nwest() const = 0;
    virtual point swest() const = 0;
    virtual void draw() = 0;
    virtual void move(int, int) = 0;
    virtual void resize(int) = 0;
};

shape * shape :: list = nullptr; // инициализация списка фигур

class rotatable : virtual public shape { // фигуры, пригодные к повороту
public:
    virtual void rotate_left() = 0;
    virtual void rotate_right() = 0;
};

class reflectable : virtual  public shape { // фигуры, пригодные к зеркальному отражению
public:
    virtual void flip_horisontallly() = 0;
    virtual void flip_vertically() = 0;
};

class line : public shape{
protected:
    point w, e;
public:
    line (point a, point b) : w(a), e(b) { };
    line (point a, int L) : w(point(a.x + L - 1, a.y)), e(a) { };
};