#include "eraser.h"

eraser::eraser()
{

}

void eraser::draw(QPainter* pt4)
{
  QPen pen(Qt::white,Qt::SolidLine);
QBrush brush(Qt::white,Qt::SolidPattern);
pen.setWidth(7);
pt4->drawRect(this->getX1(),this->getY1(),15,15);
}

void eraser::select(QPainter *)
{
    //do nothing
}

bool eraser::isOwnedByMe(int, int)
{
    return false;
}

bool eraser::toResize(int, int)
{
    return false;
}

void eraser::resize(int, int)
{
    //do nothing
}

void eraser::move(int, int)
{
    //do nothing
}

void eraser::basic(int, int)
{
    //do nothing
}

int eraser::getX1() const
{
    return x1;
}

void eraser::setX1(int value)
{
    x1 = value;
}

int eraser::getY1() const
{
    return y1;
}

void eraser::setY1(int value)
{
    y1 = value;
}
