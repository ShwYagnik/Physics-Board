#include "scribble.h"

scribble::scribble()
{

}

void scribble::draw(QPainter* pt5)
{
    if(this->getPenColor()==0)
    {
        QPen pen(Qt::black,Qt::SolidLine);
        pen.setWidth(4);
        pt5->setPen(pen);
    }
    if(this->getPenColor()==1)
    {
        QPen pen(Qt::blue,Qt::SolidLine);
        pen.setWidth(4);
        pt5->setPen(pen);
    }
    if(this->getPenColor()==2)
    {
        QPen pen(Qt::red,Qt::SolidLine);
        pen.setWidth(4);
        pt5->setPen(pen);
    }
    if(this->getPenColor()==3)
    {
        QPen pen(Qt::green,Qt::SolidLine);
        pen.setWidth(4);
        pt5->setPen(pen);
    }
    if(this->getPenColor()==4)
    {
        QPen pen(Qt::yellow,Qt::SolidLine);
        pen.setWidth(4);
        pt5->setPen(pen);
    }
    pt5->drawLine(this->getX1(),this->getY1(),this->getX2(),this->getY2());
}

void scribble::select(QPainter *)
{
    //do nothing
}

bool scribble::isOwnedByMe(int, int)
{
    return false;
}

bool scribble::toResize(int, int)
{
    return false;
}

void scribble::resize(int, int)
{
    //do nothing
}

void scribble::move(int, int)
{
 //do nothing
}

void scribble::basic(int, int)
{
    //do nothing
}

QString scribble::getName()
{
    return "Scribble Tool";
}

int scribble::getX1() const
{
    return x1;
}

void scribble::setX1(int value)
{
    x1 = value;
}

int scribble::getX2() const
{
    return x2;
}

void scribble::setX2(int value)
{
    x2 = value;
}

int scribble::getY1() const
{
    return y1;
}

void scribble::setY1(int value)
{
    y1 = value;
}

int scribble::getY2() const
{
    return y2;
}

void scribble::setY2(int value)
{
    y2 = value;
}

int scribble::getPenColor() const
{
    return penColor;
}

void scribble::setPenColor(int value)
{
    penColor = value;
}
