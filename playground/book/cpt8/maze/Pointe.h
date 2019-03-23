//
// Created by schwarzeni on 2019-03-10.
//

#ifndef PLAYGROUND_POINTER_H
#define PLAYGROUND_POINTER_H

namespace cpt8_maze {
    class Point {
    public:

        Point(int x, int y) : x(x), y(y) {
            this->point = nullptr;
        }

        Point(int x, int y, cpt8_maze::Point *pt) : x(x), y(y), point(pt) {}

        int getX() const {
            return x;
        }

        void setX(int x) {
            Point::x = x;
        }

        int getY() const {
            return y;
        }

        void setY(int y) {
            Point::y = y;
        }

        cpt8_maze::Point *getPoint() const {
            return point;
        }

    private:
        int x;
        int y;
        cpt8_maze::Point *point;
    };
}

#endif //PLAYGROUND_POINTER_H
