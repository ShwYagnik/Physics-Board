#ifndef ERASER_H
#define ERASER_H
#include<drawablecomponent.h>
#include<QPainter>

class eraser:public DrawableComponent
{
public:
    eraser();
    void draw(QPainter*);
    void select(QPainter*);
    bool isOwnedByMe(int,int);
    bool toResize(int, int);
    void resize(int, int);
    void move(int, int);
    void basic(int, int);
    int getX1() const;
    void setX1(int value);

    int getY1() const;
    void setY1(int value);

private:
    int x1;
    int y1;

};

#endif // ERASER_H
