#include "circle.h"
#include<QtMath>
#include<iostream>
using namespace std;
bool ir=false;
Circle::Circle()
{

}

void Circle::draw(QPainter* pt2)
{
    if(this->getPenColor()==0)
    {
        QPen pen(Qt::black,Qt::SolidLine);
        pen.setWidth(5);
        pt2->setPen(pen);
    }
    if(this->getPenColor()==1)
    {
        QPen pen(Qt::blue,Qt::SolidLine);
        pen.setWidth(5);
        pt2->setPen(pen);
    }
    if(this->getPenColor()==2)
    {
        QPen pen(Qt::red,Qt::SolidLine);
        pen.setWidth(5);
        pt2->setPen(pen);
    }
    if(this->getPenColor()==3)
    {
        QPen pen(Qt::green,Qt::SolidLine);
        pen.setWidth(5);
        pt2->setPen(pen);
    }
    if(this->getPenColor()==4)
    {
        QPen pen(Qt::yellow,Qt::SolidLine);
        pen.setWidth(5);
        pt2->setPen(pen);
    }
    int radius=qSqrt((xF-x)*(xF-x)+(yF-y)*(yF-y));
    this->setRadius(radius);
   int theta=0;
   int h=x;
   int k=y;
   float step=6.0f;
  int x1=h+radius*cos(theta);
   int y1=k+radius*sin(theta);
   int x2;
   int y2;
   while(theta<=500)
   {
       x2=h+radius*cos(theta);
       y2=k+radius*sin(theta);
      pt2->drawLine(x1,y1,x2,y2);
      x1=x2;
      y1=y2;
       theta=theta+step;
   }
}

void Circle::select(QPainter* ptt2)
{
    QPen pen(Qt::darkRed,Qt::SolidLine);
    pen.setWidth(5);
    ptt2->setPen(pen);
    int x11=this->getX()+radius*cos(300);
    int y11=this->getY()+radius*sin(300);
    int x12=this->getX()+radius*cos(498);
    int y12=this->getY()+radius*sin(498);
    int x13=this->getX()+radius*cos(198);
    int y13=this->getY()+radius*sin(198);
    int x14=this->getX()+radius*cos(0);
    int y14=this->getY()+radius*sin(0);
   // cout<<"Circle's select method invoked"<<endl;
     ptt2->drawRect(x11-4,y11-4,10,10);
     ptt2->drawRect(x12-4,y12-4,10,10);
      ptt2->drawRect(x13-4,y13-4,10,10);
       ptt2->drawRect(x14-4,y14-4,10,10);

}

bool Circle::isOwnedByMe(int xMe, int yMe)
{
    bool found=false;
    int distance=qSqrt((xMe-this->getX())*(xMe-this->getX())+(yMe-this->getY())*(yMe-this->getY()));
   if(distance<=(this->getRadius())+15)
   {
       ir=toResize(xMe,yMe);
       if(ir==false)
       {
       basic(xMe,yMe);
       }
      found=true;
   }

    //cout<<"Circle ke found ki value"<<found<<endl;
    return found;
}

bool Circle::toResize(int xRe, int yRe)
{
    bool yes=false;
    int x11=this->getX()+radius*cos(300);
    int y11=this->getY()+radius*sin(300);
    int x12=this->getX()+radius*cos(498);
    int y12=this->getY()+radius*sin(498);
    int x13=this->getX()+radius*cos(198);
    int y13=this->getY()+radius*sin(198);
    int x14=this->getX()+radius*cos(0);
    int y14=this->getY()+radius*sin(0);
    if(xRe>=x11-10 && xRe<=x11+10)
    {
        if(yRe>=y11-15 && yRe<=y11+15)
        {
        yes=true;
    }
    }
    else
    {
        if(xRe>=x12-15 && xRe<=x12+15)
        {
            if(yRe>=y12-15 && yRe<=y12+15)
            {
            yes=true;
        }

        }
        else
        {
            if(xRe>=x13-15 && xRe<=x13+15)
            {
                if(yRe>=y13-15 && yRe<=y13+15)
                {
                yes=true;
            }

            }

            else
            {
                if(xRe>=x14-15 && xRe<=x14+15)
                {
                    if(yRe>=y14-15 && yRe<=y14+15)
                    {
                    yes=true;
                }

                }
                else
                {
                    yes=false;
                }
            }
        }
    }
   // cout<<"Circle ke toResize ka jawaab~~~~~~~~~~~~~~~~~~~~~~"<<yes<<endl;
    return yes;
}

void Circle::resize(int xNew, int yNew)
{
    if(xNew>=200 && xNew<=1700)
    {
        if(yNew>=110 && yNew<=1013)
        {
            int newRadius=qSqrt((xNew-this->getX())*(xNew-this->getX()+(yNew-this->getY())*(yNew-this->getY())));
            float area=3.14*newRadius*newRadius;
           // cout<<"NEW AREAAAAAAAAAAAAAAA"<<area<<endl;
                this->setXF(xNew);
    this->setYF(yNew);

        }
    }
}

void Circle::move(int xChange, int yChange)
{
   // cout<<"Circle's Move calledjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj"<<endl;

    this->setX(xChange-this->getChangeInX());
        this->setY(yChange-this->getChangeInY());
        this->setXF(xChange-this->getChangeInxF());
        this->setYF(yChange-this->getChangeInyF());


}
void Circle::basic(int xB, int yB)
{

    this->setChangeInX(xB-this->getX());
        this->setChangeInY(yB-this->getY());
        this->setChangeInxF(xB-this->getXF());
    this->setChangeInyF(yB-this->getYF());
}

QString Circle::getName()
{
    return "Circle";
}


int Circle::getX() const
{
    return x;
}

void Circle::setX(int value)
{
    x = value;
}

int Circle::getY() const
{
    return y;
}

void Circle::setY(int value)
{
    y = value;
}

int Circle::getSide() const
{
    return side;
}

void Circle::setSide(int value)
{
    side = value;
}

int Circle::getXF() const
{
    return xF;
}

void Circle::setXF(int value)
{
    xF = value;
}

int Circle::getYF() const
{
    return yF;
}

void Circle::setYF(int value)
{
    yF = value;
}

int Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(int value)
{
    radius = value;
}

int Circle::getChangeInX() const
{
    return changeInX;
}

void Circle::setChangeInX(int value)
{
    changeInX = value;
}

int Circle::getChangeInY() const
{
    return changeInY;
}

void Circle::setChangeInY(int value)
{
    changeInY = value;
}

int Circle::getChangeInxF() const
{
    return changeInxF;
}

void Circle::setChangeInxF(int value)
{
    changeInxF = value;
}

int Circle::getChangeInyF() const
{
    return changeInyF;
}

void Circle::setChangeInyF(int value)
{
    changeInyF = value;
}

int Circle::getPenColor() const
{
    return penColor;
}

void Circle::setPenColor(int value)
{
    penColor = value;
}
