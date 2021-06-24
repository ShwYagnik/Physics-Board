#include "line.h"
#include<iostream>
#include<QtMath>
bool onesToBeReplaced=false;
bool twosToBeReplaced=false;
using namespace std;
line::line()
{

}

void line::draw(QPainter* pt3)
{
    if(this->getPenColor()==0)
    {
        QPen pen(Qt::black,Qt::SolidLine);
        pen.setWidth(5);
        pt3->setPen(pen);
    }
    if(this->getPenColor()==1)
    {
        QPen pen(Qt::blue,Qt::SolidLine);
        pen.setWidth(5);
        pt3->setPen(pen);
    }
    if(this->getPenColor()==2)
    {
        QPen pen(Qt::red,Qt::SolidLine);
        pen.setWidth(5);
        pt3->setPen(pen);
    }
    if(this->getPenColor()==3)
    {
        QPen pen(Qt::green,Qt::SolidLine);
        pen.setWidth(5);
        pt3->setPen(pen);
    }
    if(this->getPenColor()==4)
    {
        QPen pen(Qt::yellow,Qt::SolidLine);
        pen.setWidth(5);
        pt3->setPen(pen);
    }
    pt3->drawLine(this->getX1(),this->getY1(),this->getX2(),this->getY2());
}

void line::select(QPainter* ptt3)
{
   // cout<<"Lineeee Select called"<<endl;
    QPen pen(Qt::darkRed,Qt::SolidLine);
    pen.setWidth(5);
    ptt3->setPen(pen);
    ptt3->drawRect(this->getX1()-5,this->getY1()-5,10,10);
    ptt3->drawRect(this->getX2()-5,this->getY2()-5,10,10);
}

bool line::isOwnedByMe(int xMe, int yMe)
{
    bool found=false;
   //(y-y1)(x2-x1)=(x-x1)(y2-y1)
    //if(cross==0)
    int d1=qSqrt(((xMe-this->getX1())*(xMe-this->getX1()))+((yMe-this->getY1())*(yMe-this->getY1())));
    int d2=qSqrt(((this->getX2()-xMe)*(this->getX2()-xMe))+((this->getY2()-yMe)*(this->getY2()-yMe)));
    int d3=qSqrt(((this->getX2()-this->getX1())*(this->getX2()-this->getX1()))+((this->getY2()-this->getY1())*(this->getY2()-this->getY1())));
    if(d1+d2==d3)
    {
        basic(xMe,yMe);
        found=true;
    }
   // cout<<"LINE KE IS OWNEd BY ME KA JAWAAB"<<found<<endl;
    return found;
}

bool line::toResize(int xR, int yR)
{
    bool yes=false;
    if(xR>=this->getX1()-10 && xR<=this->getX1()+10 && yR>=this->getY1()-10 && yR<=this->getY1()+10)
    {
        onesToBeReplaced=true;
        twosToBeReplaced=false;
        yes=true;
    }
    if(xR>=this->getX2()-10 && xR<=this->getX2()+10 && yR>=this->getY2()-10 && yR<=this->getY2()+10)
    {
        twosToBeReplaced=true;
        onesToBeReplaced=false;
        yes=true;
    }
   // cout<<"LINE KI TO RESIZE KA JAWAAB"<<yes<<endl;
    return yes;
}

void line::resize(int xResize, int yResize)
{

    if(onesToBeReplaced==true)
    {
        this->setX1(xResize);
        this->setY1(yResize);
    }
    if(twosToBeReplaced==true)
    {
        this->setX2(xResize);
        this->setY2(yResize);
    }
}

void line::move(int xMove, int yMove)
{
this->setX1(xMove-this->getChangeInX1());
    this->setY1(yMove-this->getChnageInY1());
    this->setX2(xMove+this->getChangeInX2());
    this->setY2(yMove+this->getChangeInY2());
}

void line::basic(int xB, int yB)
{

    this->setChangeInX1(xB-this->getX1());
    this->setChnageInY1(yB-this->getY1());
    this->setChangeInX2(this->getX2()-xB);
    this->setChangeInY2(this->getY2()-yB);

}

QString line::getName()
{
 return "Line";
}

int line::getX1() const
{
    return x1;
}

void line::setX1(int value)
{
    x1 = value;
}

int line::getX2() const
{
    return x2;
}

void line::setX2(int value)
{
    x2 = value;
}

int line::getY1() const
{
    return y1;
}

void line::setY1(int value)
{
    y1 = value;
}

int line::getY2() const
{
    return y2;
}

void line::setY2(int value)
{
    y2 = value;
}

int line::getChangeInX1() const
{
    return changeInX1;
}

void line::setChangeInX1(int value)
{
    changeInX1 = value;
}

int line::getChnageInY1() const
{
    return chnageInY1;
}

void line::setChnageInY1(int value)
{
    chnageInY1 = value;
}

int line::getChangeInX2() const
{
    return changeInX2;
}

void line::setChangeInX2(int value)
{
    changeInX2 = value;
}

int line::getChangeInY2() const
{
    return changeInY2;
}

void line::setChangeInY2(int value)
{
    changeInY2 = value;
}

int line::getPenColor() const
{
    return penColor;
}

void line::setPenColor(int value)
{
    penColor = value;
}
