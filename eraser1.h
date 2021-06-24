#ifndef ERASER1_H
#define ERASER1_H
#include<drawablecomponent.h>

class eraser1:public DrawableComponent
{
public:
    eraser1();
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

    int getY1() const;
    void setY1(int value);

private:
    int x1;
    int y1;

};

#endif // ERASER1_H
