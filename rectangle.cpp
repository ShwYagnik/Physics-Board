#include "rectangle.h"
#include<iostream>
using namespace std;
int xBasic;
int yBasic;

Rectangle::Rectangle()
{

}

void Rectangle::draw(QPainter* pt1)
{
    if(this->getPenColor()==0)
    {
        QPen pen(Qt::black,Qt::SolidLine);
        pen.setWidth(5);
        pt1->setPen(pen);
    }
    if(this->getPenColor()==1)
    {
        QPen pen(Qt::blue,Qt::SolidLine);
        pen.setWidth(5);
        pt1->setPen(pen);
    }
    if(this->getPenColor()==2)
    {
        QPen pen(Qt::red,Qt::SolidLine);
        pen.setWidth(5);
        pt1->setPen(pen);
    }
    if(this->getPenColor()==3)
    {
        QPen pen(Qt::green,Qt::SolidLine);
        pen.setWidth(5);
        pt1->setPen(pen);
    }
    if(this->getPenColor()==4)
    {
        QPen pen(Qt::yellow,Qt::SolidLine);
        pen.setWidth(5);
        pt1->setPen(pen);
    }
    if(this->getX()>this->getX1() && this->getY()>this->getY1())
    {
        this->setWidth(this->getX()-this->getX1());
        this->setHeight(this->getY()-this->getY1());
    pt1->drawRect(this->getX1(),this->getY1(),this->getX()-this->getX1(),this->getY()-this->getY1());
}
    else
    {
        this->setWidth(this->getX1()-this->getX());
        this->setHeight(this->getY1()-this->getY());
         pt1->drawRect(this->getX(),this->getY(),this->getX1()-this->getX(),this->getY1()-this->getY());
    }
}

void Rectangle::select(QPainter* ptt1)
{
    cout<<"SELECT CALLED"<<endl;
QPen pen(Qt::darkRed,Qt::SolidLine);
pen.setWidth(5);
ptt1->setPen(pen);
if(this->getX()<this->getX1() && this->getY()<this->getY1())
{
ptt1->drawRect(this->getX()-5,this->getY()-5,10,10);
ptt1->drawRect(this->getX()-5,(this->getY()+this->getHeight())-5,10,10);
ptt1->drawRect((this->getX()+this->getWidth())-5,this->getY()-5,10,10);
ptt1->drawRect((this->getX()+this->getWidth())-5,(this->getY()+this->getHeight())-5,10,10);
ptt1->drawRect(this->getX()+(this->getWidth())/2-4,this->getY()-5,10,10);
ptt1->drawRect((this->getX()+this->getWidth())-5,this->getY()-4+(this->getHeight()/2),10,10);
ptt1->drawRect(this->getX()-5,this->getY()+(this->getHeight()/2)-4,10,10);
ptt1->drawRect(this->getX()+(this->getWidth()/2)-4,(this->getY()+this->getHeight())-5,10,10);
}
else
{
ptt1->drawRect(this->getX1()-5,this->getY1()-5,10,10);
ptt1->drawRect(this->getX1()-5,(this->getY1()+this->getHeight())-5,10,10);
ptt1->drawRect((this->getX1()+this->getWidth())-5,this->getY1()-5,10,10);
ptt1->drawRect((this->getX1()+this->getWidth())-5,(this->getY1()+this->getHeight())-5,10,10);
ptt1->drawRect(this->getX1()+(this->getWidth())/2-4,this->getY1()-5,10,10);
ptt1->drawRect((this->getX1()+this->getWidth())-5,this->getY1()-4+(this->getHeight()/2),10,10);
ptt1->drawRect(this->getX1()-5,this->getY1()+(this->getHeight()/2)-4,10,10);
ptt1->drawRect(this->getX1()+(this->getWidth()/2)-4,(this->getY1()+this->getHeight())-5,10,10);
}
}

bool Rectangle::isOwnedByMe(int xMe, int yMe)
{
    bool found=false;
    if(this->getX()>this->getX1() && this->getY()>this->getY1())
    {
    if(xMe>=this->getX1()-5 && xMe<=(this->getX1()+this->getWidth())+30)
    {
        if(yMe>=this->getY1()-5 && yMe<=(this->getY1()+this->getHeight())+30)
        {
            basic(xMe,yMe);
            found=true;

        }
    }
    }
    else
    {
        if(xMe>=this->getX()-5 && xMe<=(this->getX()+this->getWidth())+5)
        {
            if(yMe>=this->getY()-5 && yMe<=(this->getY()+this->getHeight())+5)
            {
                basic(xMe,yMe);
                found=true;
            }
        }
    }
  //  cout<<"Rectangle ki is Owned by you chali"<<endl;
   // cout<<"Rectangle ke found ki value"<<found<<endl;
    return found;
}

bool Rectangle::toResize(int xRe, int yRe)
{
    bool yes=false;
   if(this->getX()<this->getX1() && this->getY()<this->getY1())
   {
      if(xRe>=(this->getX()+(this->getWidth()/2))-30 && xRe<=(this->getX()+(this->getWidth()/2))+30 && yRe>=this->getY()-30 && yRe<=this->getY()+30)
      {

          yToResize=true;
          xToResize=false;
          y1ToResize=false;
          x1ToResize=false;
        //  cout<<"yToResize@@@@@@@@@@@@@@@@@@@"<<endl;
          yes=true;

      }
      else
      {

          if(xRe>=(this->getX()+this->getWidth()/2)-30 && xRe<=(this->getX()+(this->getWidth()/2))+30 && yRe>=(this->getY()+this->getHeight())-30 && yRe<=(this->getY()+this->getHeight())+30)
          {

             yToResize=false;
              xToResize=false;
              y1ToResize=true;
              x1ToResize=false;
              //cout<<"y1ToResize@@@@@@@@@@@@@@@@@@@"<<endl;
              yes=true;

             // cout<<"Rectangle se "<<this->getX()+this->getWidth()/2-10<<"    "<<this->getY()+this->getHeight()-10<<endl;
          }
          else
          {
              if(yRe>=(this->getY()+(this->getHeight()/2))-30 && yRe<=(this->getY()+(this->getHeight()/2))+30 && xRe>=this->getX()-30 && xRe<=this->getX()+30 )
                 {

                  yToResize=false;
                  xToResize=true;
                  y1ToResize=false;
                  x1ToResize=false;
                  //cout<<"xToResize@@@@@@@@@@@@@@@@@@@"<<endl;
                  yes=true;

              }
              else
              {
                  if(yRe>=(this->getY()+(this->getHeight()/2))-25 && yRe<=(this->getY()+(this->getHeight()/2))+25 && xRe>=(this->getX()+this->getWidth())-60 && xRe<=(this->getX()+this->getWidth())+60 )
                            {
                      yToResize=false;
                      xToResize=false;
                      y1ToResize=false;
                      x1ToResize=true;
                     // cout<<"x1ToResize@@@@@@@@@@@@@@@@@@@"<<endl;
                      yes=true;
                        }
                  else

                     {
                      yToResize=false;
                      xToResize=false;
                      y1ToResize=false;
                      x1ToResize=false;
                  yes=false;
                  }
              }
          }
      }


   }
   else
   {
       if(xRe>=(this->getX1()+(this->getWidth()/2))-10 && xRe<=(this->getX1()+(this->getWidth()/2))+10 && yRe>=this->getY1()-10 && yRe<=this->getY1()+10)
       {

           yToResize=false;
           xToResize=false;
           y1ToResize=true;
           x1ToResize=false;
           //cout<<"yToResize@@@@@@@@@@@@@@@@@@@"<<endl;
           yes=true;

       }
       else
       {

           if(xRe>=(this->getX1()+this->getWidth()/2)-10 && xRe<=(this->getX1()+(this->getWidth()/2))+10 && yRe>=(this->getY1()+this->getHeight())-10 && yRe<=(this->getY1()+this->getHeight())+10)
           {

              yToResize=true;
               xToResize=false;
               y1ToResize=false;
               x1ToResize=false;
              // cout<<"y1ToResize@@@@@@@@@@@@@@@@@@@"<<endl;
               yes=true;

              // cout<<"Rectangle se "<<this->getX()+this->getWidth()/2-10<<"    "<<this->getY()+this->getHeight()-10<<endl;
           }
           else
           {
               if(yRe>=(this->getY1()+(this->getHeight()/2))-10 && yRe<=(this->getY1()+(this->getHeight()/2))+10 && xRe>=this->getX1()-10 && xRe<=this->getX1()+10 )
                  {

                   yToResize=false;
                   xToResize=false;
                   y1ToResize=false;
                   x1ToResize=true;
                   //cout<<"xToResize@@@@@@@@@@@@@@@@@@@"<<endl;
                   yes=true;

               }
               else
               {
                   if(yRe>=(this->getY1()+(this->getHeight()/2))-10 && yRe<=(this->getY1()+(this->getHeight()/2))+10 && xRe>=(this->getX1()+this->getWidth())-10 && xRe<=(this->getX1()+this->getWidth())+10 )
                             {
                       yToResize=false;
                       xToResize=true;
                       y1ToResize=false;
                       x1ToResize=false;
                       //cout<<"x1ToResize@@@@@@@@@@@@@@@@@@@"<<endl;
                       yes=true;
                         }
                   else

                      {
                       yToResize=false;
                       xToResize=false;
                       y1ToResize=false;
                       x1ToResize=false;
                   yes=false;
                   }
               }
           }
       }

       }

   //cout<<"Rectangle ke toResize ka jawaab~~~~~~~~~~~~~~~~~~~~~~"<<yes<<endl;
   return yes;
}

void Rectangle::resize(int xNew, int yNew)
{
   // cout<<"Resize of rectangle chali"<<endl;
    if(this->getX()<this->getX1() && this->getY()<this->getY1())
    {
    if(xToResize==true)
    {
        if(xNew>=200 && xNew<=1700)
        {

         this->setX(xNew);
       // this->setY(yNew);

        }
    }
    if(x1ToResize==true)
    {
        if(xNew>=200 && xNew<=1700)
        {

        this->setX1(xNew);
        //this->setY1(yNew);

        }
    }
    if(yToResize==true)
    {
        if(yNew>=110 && yNew<=1013)
        {
        //this->setX(xNew-(this->getWidth()/2));
        this->setY(yNew);
    }
    }
    if(y1ToResize==true)
    {
        if(yNew>=110 && yNew<=1013)
        {
        //this->setX1(xNew+(this->getWidth()/2));
        this->setY1(yNew);
    }
    }
    }
    else
    {
        if(xToResize==true)
        {
            if(xNew>=200 && xNew<=1700)
            {
            this->setX(xNew);
           // this->setY(yNew);
        }
        }
        if(x1ToResize==true)
        {
            if(xNew>=200 && xNew<=1700)
            {
            this->setX1(xNew);
            //this->setY1(yNew);
        }
        }
        if(yToResize==true)
        {
            if(yNew>=110 && yNew<=1013)
            {
            //this->setX(xNew);
            this->setY(yNew);
        }
        }
        if(y1ToResize==true)
        {
            if(yNew>=110 && yNew<=1013)
            {
           // this->setX1(xNew);
            this->setY1(yNew);
        }
        }

    }
}

void Rectangle::move(int xChange, int yChange)
{
    if(this->getX()<this->getX1() && this->getY()<this->getY1())
    {
       // cout<<" X KI VALUE BEFORE::::::::::"<<this->getX()<<endl;
        // cout<<" Y KI VALUE BEFORE::::::::::"<<this->getY()<<endl;
        //cout<<"XCHANGE MINUS BASIC::::::::::::::"<<xChange-xBasic<<endl;
         //cout<<"YCHANGE MINUS BASIC::::::::::::::"<<yChange-yBasic<<endl;
        if(xChange-this->getChangeInX()>=200 && xChange-this->getChangeInX()<=1700 && xChange-this->getChangeInX1()>=200 && xChange-this->getChangeInX1()<=1700)
        {
            if(yChange-this->getChangeInY()>=110 && yChange-this->getChangeInY()<=1013 && yChange-this->getChangeInY1()>=110 && yChange-this->getChangeInY1()<=1013)
            {

        this->setX(xChange-this->getChangeInX());
    this->setY(yChange-this->getChangeInY());
         this->setX1(xChange+this->getChangeInX1());
         this->setY1(yChange+this->getChangeInY1());

       }
    }

    }
    else
    {

        if(xChange-this->getChangeInX()>=200 && xChange-this->getChangeInX()<=1700 && xChange-this->getChangeInX1()>=200 && xChange-this->getChangeInX1()<=1700)
        {
            if(yChange-this->getChangeInY()>=110 && yChange-this->getChangeInY()<=1013 && yChange-this->getChangeInY1()>=110 && yChange-this->getChangeInY1()<=1013)
            {

        this->setX1(xChange-this->getChangeInX1());
        this->setY1(yChange-this->getChangeInY1());
        this->setX(xChange+this->getChangeInX());
        this->setY(yChange+this->getChangeInY());

           }
        }

    }
}

void Rectangle::basic(int xB, int yB)
{
    if(this->getX()<this->getX1() && this->getY()<this->getY1())
    {
        if(xB>=200 && xB<=1700)
        {
            if(yB>=110 && yB<=1013)
            {
        this->setChangeInX(xB-this->getX());
           this->setChangeInY(yB-this->getY());
            this->setChangeInX1(this->getX1()-xB);
         this->setChangeInY1(this->getY1()-yB);
    }
        }
    }
    else
    {
        if(xB>=200 && xB<=1700)
        {
            if(yB>=110 && yB<=1013)
            {
        this->setChangeInX1(xB-this->getX1());
        this->setChangeInY1(yB-this->getY1());
        this->setChangeInX(this->getX()-xB);
           this->setChangeInY(this->getY()-yB);
    }
        }
    }
}

QString Rectangle::getName()
{
    return "Rectangle";
}

int Rectangle::getX() const
{
    return x;
}

void Rectangle::setX(int value)
{
    x = value;
}

int Rectangle::getY() const
{
    return y;
}

void Rectangle::setY(int value)
{
    y = value;
}

int Rectangle::getWidth() const
{
    return width;
}

void Rectangle::setWidth(int value)
{
    width = value;
}

int Rectangle::getHeight() const
{
    return height;
}

void Rectangle::setHeight(int value)
{
    height = value;
}

int Rectangle::getX1() const
{
    return x1;
}

void Rectangle::setX1(int value)
{
    x1 = value;
}

int Rectangle::getY1() const
{
    return y1;
}

void Rectangle::setY1(int value)
{
    y1 = value;
}

int Rectangle::getChangeInX() const
{
    return changeInX;
}

void Rectangle::setChangeInX(int value)
{
    changeInX = value;
}

int Rectangle::getChangeInY() const
{
    return changeInY;
}

void Rectangle::setChangeInY(int value)
{
    changeInY = value;
}

int Rectangle::getChangeInX1() const
{
    return changeInX1;
}

void Rectangle::setChangeInX1(int value)
{
    changeInX1 = value;
}

int Rectangle::getChangeInY1() const
{
    return changeInY1;
}

void Rectangle::setChangeInY1(int value)
{
    changeInY1 = value;
}

int Rectangle::getPenColor() const
{
    return penColor;
}

void Rectangle::setPenColor(int value)
{
    penColor = value;
}
