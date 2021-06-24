#include "eraser1.h"

eraser1::eraser1()
{

}

void eraser1::draw(QPainter * pt6)
{
    QPen pen(Qt::white,Qt::SolidLine);
    QBrush brush(Qt::white,Qt::SolidPattern);
    pt6->setPen(pen);
    pt6->setBrush(brush);
    pt6->drawRect(this->getX1(),this->getY1(),10,10);
}

void eraser1::select(QPainter *)
{

}

bool eraser1::isOwnedByMe(int, int)
{
    return false;
}

bool eraser1::toResize(int, int)
{
    return false;

}

void eraser1::resize(int, int)
{

}

void eraser1::move(int, int)
{

}

void eraser1::basic(int, int)
{

}

QString eraser1::getName()
{
    return "Eraser";
}

int eraser1::getX1() const
{
    return x1;
}

void eraser1::setX1(int value)
{
    x1 = value;
}

int eraser1::getY1() const
{
    return y1;
}

void eraser1::setY1(int value)
{
    y1 = value;
}
