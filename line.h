#ifndef LINE_H
#define LINE_H
#include<drawablecomponent.h>
#include<QPainter>

class line:public DrawableComponent
{
public:
    line();
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

    int getChangeInX1() const;
    void setChangeInX1(int value);

    int getChnageInY1() const;
    void setChnageInY1(int value);

    int getChangeInX2() const;
    void setChangeInX2(int value);

    int getChangeInY2() const;
    void setChangeInY2(int value);

    int getPenColor() const;
    void setPenColor(int value);

private:
    int x1;
    int x2;
    int y1;
    int y2;
    int changeInX1;
    int chnageInY1;
    int changeInX2;
    int changeInY2;
    int penColor;

};

#endif // LINE_H
