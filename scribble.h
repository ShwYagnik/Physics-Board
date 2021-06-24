#ifndef SCRIBBLE_H
#define SCRIBBLE_H
#include<drawablecomponent.h>

class scribble:public DrawableComponent
{
public:
    scribble();
    void draw(QPainter*);
    void select(QPainter*);
    bool isOwnedByMe(int,int);
    bool toResize(int, int);
    void resize(int, int);
    void move(int, int);
    void basic(int, int);
    QString getName();
    int getX1() const;
    void setX1(int value);

    int getX2() const;
    void setX2(int value);

    int getY1() const;
    void setY1(int value);

    int getY2() const;
    void setY2(int value);

    int getPenColor() const;
    void setPenColor(int value);

private:
    int x1;
    int x2;
    int y1;
    int y2;
    int penColor;
};

#endif // SCRIBBLE_H
