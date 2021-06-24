#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<drawablecomponent.h>
#include<QPainter>

class Rectangle:public DrawableComponent
{
public:
    Rectangle();
    void draw(QPainter*);
    void select(QPainter*);
    bool isOwnedByMe(int,int);
    bool toResize(int, int);
    void resize(int, int);
    void move(int, int);
    void basic(int, int);
    QString getName();
    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

    int getX1() const;
    void setX1(int value);

    int getY1() const;
    void setY1(int value);

    int getChangeInX() const;
    void setChangeInX(int value);

    int getChangeInY() const;
    void setChangeInY(int value);

    int getChangeInX1() const;
    void setChangeInX1(int value);

    int getChangeInY1() const;
    void setChangeInY1(int value);

    int getPenColor() const;
    void setPenColor(int value);

private:
    int x;
    int y;
    int x1;
    int y1;
    int width;
    int height;
    bool xToResize;
    bool yToResize;
    bool x1ToResize;
    bool y1ToResize;
    int changeInX;
    int changeInY;
    int changeInX1;
    int changeInY1;
    int penColor;
};

#endif // RECTANGLE_H
