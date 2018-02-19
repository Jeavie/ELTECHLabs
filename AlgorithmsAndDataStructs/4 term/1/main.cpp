#include <iostream>
#include "shape.h"

class h_circle : public rectangle, public reflectable{
    bool reflected;
public:
    h_circle(point a, point b, bool r = true) : rectangle (a, b), reflected(r) {}
    void draw();
    void flip_horisontally() {};
    void flip_vertically() { reflected = !reflected; };
};
 void h_circle :: draw() {
     int x0 = (sw.x + ne.x) / 2;
     int y0 = reflected ? sw.y : ne.y;
     int radius = (ne.x - sw.x) / 2;
     int x = 0;
     int y = radius;
     int delta = 2 - 2 * radius;
     int error = 0;
     while (y >= 0){
         if (reflected) {
             put_point(x0 + x, y0 + 0.7 * y);
             put_point(x0 - x, y0 + 0.7 * y);
         } else {
             put_point(x0 + x, y0 - 0.7 * y);
             put_point(x0 - x, y0 - 0.7 * y);
         }
         error = 2 * (delta + y) - 1;
         if (delta < 0 && error <= 0) {++x; delta += 2 * x + 1;
             continue;
         }
         error = 2 * (delta - x) - 1;
         if (delta > 0 && error > 0) {--y; delta += 1 - 2 * y;
             continue;
         }
         ++x; delta += 2 * (x - y); --y;
     }
 }

void down(shape& p, shape& q){
    point n = q.south();
    point s = p.north();
    p.move(n.x - s.x, n.y - s.y - 1);
}

class myshape : public rectangle{
    int w, h;
    line l_eye;
    line r_eye;
    line mouth;
public:
    myshape(point, point);
    void draw();
    void move(int, int);
    void resize(int) {}
};



myshape ::myshape(point a, point b) : rectangle (a, b),
                                      w(neast().x - swest().x + 1),
                                      h(neast().y - swest().y + 1),
                                      l_eye(point(swest().x + 2, swest().y + h * 3 / 4), 2),
                                      r_eye(point(swest().x + w - 4, swest().y + h * 3 / 4), 2),
                                      mouth(point(swest().x + 2, swest().y + h / 4), w - 4) {}

void myshape :: draw() {
    rectangle :: draw();
    int a = (swest().x + neast().x) / 2;
    int b = (swest().y + neast().y) / 2;
    put_point(point(a, b));
}

void myshape ::move(int a, int b) {
    rectangle :: move(a, b);
    l_eye.move(a, b);
    r_eye.move(a, b);
    mouth.move(a ,b);
}

int main() {
    setlocale(LC_ALL, "RUS");
    //Инициализаия фигур
    screen_init();
    rectangle p1(point(0, 0), point(12, 5));
    line p2(point(0, 15), 17);
    myshape p3(point(15, 10), point(27, 18));
    h_circle p4(point(40, 10), point(50, 20));
    shape_refresh();
    std :: cout << "GENERATED \n";
    std :: cin.get(); //смотреть исходный набор
    p1.rotate_right();
    p2.resize(2);
    p4.flip_vertically();
    shape_refresh();
    std :: cout << "PREPARED \n";
    std :: cin.get();
    //сборка изображения
    p3.move(10, 0);
    up(p2, p3);
    up(p1, p2);
    down(p4, p3);
    shape_refresh();
    std :: cout << "READY \n";
    std :: cin.get();
    screen_destroy();
    return 0;
}
