//
// Created by jeavie on 09.02.2018.
//
//
//#pragma once
//#include <iostream>
//#include <string>
//#include "screen.h"
//
//поддержка экрана в форме матрицы символов
//
//char screen[XMAX][YMAX];
//
//enum color { black = '*', white = '.' };
//
//void screen_init() {
//    for (auto y = 0; y < YMAX; ++y)
//        for (auto &x : screen[y])
//            x = white;
//}
//
//void screen_destroy() {
//    for (auto y = 0; y < YMAX; ++y)
//        for (auto &x : screen[y])
//            x = black;
//}
//
//bool on_screen(int a, int b) { //проверка попадания на экран
//    return 0 <= a && a < XMAX && 0 <= b && b < YMAX;
//}
//
//void put_line(int x0, int y0, int x1, int y1) { // рисование отрезка по пряямой по алгоритму Брезенхэма
//    int dx = 1;
//    int a = x1 - x0;
//    if (a < 0) dx = -1, a = -a;
//    int dy = 1;
//    int b = y1 - y0;
//    if (b < 0) dy = -1, b = -b;
//    int two_a = 2 * a;
//    int two_b = 2 * b;
//    int xcrit = -b + two_a;
//    int eps = 0;
//
//    for (;;) { // формирование прямой линии по точкам
//        put_point(x0, y0);
//        if (x0 == x1 && y0 == y1) break;
//        if (eps <= xcrit) x0 += dx, eps += two_b;
//        if (eps >= a || a < b) y0 += dy, eps -= two_a;
//    }
//}
//
//void screen_clear() { // очистка экрана
//    screen_init();
//}
//
//void screen_refresh() {
//    for (int y = YMAX - 1; 0 <= y; --y) { // с верхней строки до нижней
//        for (auto x : screen[y]) // от левого столбца до правого
//            std :: cout << x;
//        std :: cout << '\n';
//    }
//}
//
//2. Библиотека фигур
//struct shape {
//    static shape* list; // начало списка фигур (одно на все фигуры)
//    shape* next;
//    shape() { next = list; list = this; }
//    virtual point north() const = 0;
//    virtual point south() const = 0;
//    virtual point east() const = 0;
//    virtual point west() const = 0;
//    virtual point neast() const = 0;
//    virtual point seast() const = 0;
//    virtual point nwest() const = 0;
//    virtual point swest() const = 0;
//    virtual void draw() = 0;
//    virtual void move(int, int) = 0;
//    virtual void resize(int) = 0;
//};
//
//shape * shape :: list = nullptr; // инициализация списка фигур
//
//class rotatable : virtual public shape { // фигуры, пригодные к повороту
//public:
//    virtual void rotate_left() = 0;
//    virtual void rotate_right() = 0;
//};
//
//class reflectable : virtual  public shape { // фигуры, пригодные к зеркальному отражению
//public:
//    virtual void flip_horisontallly() = 0;
//    virtual void flip_vertically() = 0;
//};
//
//class line : public shape{
//protected:
//    point w, e;
//public:
//    line (point a, point b) : w(a), e(b) { };
//    line (point a, int L) : w(point(a.x + L - 1, a.y)), e(a) { };
//    point north() const { return point((w.x + e.x)/2, e.y < w.y ? w.y : e.y); }
//    point south() const { return point((w.x + e.x)/2, e.y < w.y ? e.y : w.y); }
//    point east() const { return point((w.x + e.x)/2, e.y < w.y ? e.y : w.y); }
//    point west() const { return point((w.x + e.x)/2, e.y < w.y ? e.y : w.y); }
//    point neast() const { return point((w.x + e.x)/2, e.y < w.y ? e.y : w.y); }
//    point seast() const { return point((w.x + e.x)/2, e.y < w.y ? e.y : w.y); }
//    point nwest() const { return point((w.x + e.x)/2, e.y < w.y ? e.y : w.y); }
//    point swest() const { return point((w.x + e.x)/2, e.y < w.y ? e.y : w.y); }
//    void move(int a, int b) {w.x += a; w.y +=b; e.x += a; e.y += b; }
//    void draw() { put_line(w, e); }
//    void resize (int d) { e.x += (e.x - w.x) * (d - 1); e.y += (e.y - w.y) * (d - 1); } // увеличение в (d) раз
//};
//
//class rectangle : public rotatable { // прямоугольник
//    /*
//    nw-----n-----ne
//    |             |
//    |             |
//    w      c      e
//    |             |
//    |             |
//    sw-----s-----se */
//protected:
//    point sw, ne;
//public:
//    rectangle (point, point);
//    point north() const { return point((sw.x + ne.x) / 2, ne.y); }
//    point south() const { return point((sw.x + ne.x) / 2, sw.y); }
//    point east() const { return point(sw.x, (sw.y + ne.y) / 2); }
//    point west() const { return point(ne.x, (sw.y + ne.y) / 2); }
//    point neast() const { return ne; }
//    point seast() const { return point(sw.x, ne.y); }
//    point nwest() const { return point(ne.x, sw.y); }
//    point swest() const { return sw; }
//    void rotate_right() { //Поворот относительно se
//        int w = ne.x - sw.x, h = ne.y - sw.y;
//        sw.x = ne.x - h * 2;
//        ne.y = sw.y + w / 2;
//    }
//    void rotate_left() { //Поворот относительно sw
//        int w = ne.x - sw.x, h = ne.y - sw.y;
//        ne.x = sw.x + h * 2;
//        ne.y = sw.y + w / 2;
//    }
//    void move(int a, int b)
//    {
//        sw.x += a;
//        sw.y += b;
//        ne.x += a;
//        ne.y += b;
//    }
//    void resize (int d){
//        ne.x += (ne.x - sw.x) * (d - 1);
//        ne.y += (ne.y - sw.y) * (d - 1);
//    }
//    void draw();
//};
//
//rectangle ::rectangle(point a, point b) {
//    if (a.x <= b.x){
//        if (a.y <= b.y) sw = a, ne = b;
//        else sw = point (a.x, b.y), ne = point (b.x, a.y);
//    } else {
//        if (a.y <= b.y) sw = point(b.x, a.y), ne = point(a.x, b.y);
//        else sw = b, ne = a;
//    }
//}
//
//void rectangle :: draw() {
//    put_line(nwest(), ne);
//    put_line(ne, seast());
//    put_line(seast(), sw);
//    put_line(sw, nwest());
//}
//
//void shape_refresh() { // перерисовкка всех фигур
//    screen_clear();
//    for (shape* p = shape :: list; p; p = p -> next) p -> draw();
//    screen_refresh();
//}
//
//void up(shape& p, const shape& q) { // поместить p над q, обычная функция, а не член класса
//    point n = q.north();
//    point s = p.south();
//    p.move(n.x - s.x, n.y - s.y + 1);
//}

