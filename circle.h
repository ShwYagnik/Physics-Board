#ifndef CIRCLE_H
#define CIRCLE_H
#include<drawablecomponent.h>
#include<QPainter>

class Circle:public DrawableComponent
{
public:
    Circle();
    void draw(QPainter *);
    void select(QPainter *);
    bool isOwnedByMe(int, int);
    bool toResize(int, int);
    void resize(int, int);
    void move(int, int);
    void basic(int, int);
    QString getName();
    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    int getSide() const;
    void setSide(int value);

    int getXF() const;
    void setXF(int value);

    int getYF() const;
    void setYF(int value);

    int getRadius() const;
    void setRadius(int value);

    int getChangeInX() const;
    void setChangeInX(int value);

    int getChangeInY() const;
    void setChangeInY(int value);

    int getChangeInxF() const;
    void setChangeInxF(int value);

    int getChangeInyF() const;
    void setChangeInyF(int value);

    int getPenColor() const;
    void setPenColor(int value);

private:
    int x;
    int y;
    int side;
    int xF;
    int yF;
    int radius;
    int changeInX;
    int changeInY;
    int changeInxF;
    int changeInyF;
    int penColor;
};

#endif // CIRCLE_H
