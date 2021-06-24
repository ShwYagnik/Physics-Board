#include "pictures.h"
#include<iostream>
using namespace std;
int xToResize;
int yToResize;
int x1ToResize;
int y1ToResize;
int xBasic1;
int yBasic1;

Pictures::Pictures()
{
    QPixmap pix1(":/images/concaveLens.png");
      this->picList.push_back(pix1);
    QPixmap pix2(":/images/concaveMirror1.png");
      this->picList.push_back(pix2);

    QPixmap pix3(":/images/convexLens.png");
      this->picList.push_back(pix3);

    QPixmap pix4(":/images/convexMirror.png");
      this->picList.push_back(pix4);

    QPixmap pix5(":/images/prism.png");
      this->picList.push_back(pix5);

    QPixmap pix6(":/images/pulley.png");
      this->picList.push_back(pix6);

    QPixmap pix7(":/images/kepe.png");
      this->picList.push_back(pix7);

    QPixmap pix8(":/images/circuit.png");
      this->picList.push_back(pix8);

    QPixmap pix9(":/images/pnDiode.png");
      this->picList.push_back(pix9);
    QPixmap pix10(":/images/pnp.png");
      this->picList.push_back(pix10);

    QPixmap pix11(":/images/npn.png");
      this->picList.push_back(pix11);

    QPixmap pix12(":/images/magnet.png");
      this->picList.push_back(pix12);

    QPixmap pix13(":/images/solenoid.png");
      this->picList.push_back(pix13);

    QPixmap pix14(":/images/torroid.png");
      this->picList.push_back(pix14);
    QPixmap pix15(":/images/self.png");
      this->picList.push_back(pix15);

    QPixmap pix16(":/images/mutual.png");
      this->picList.push_back(pix16);




}

void Pictures::draw(QPainter* pt4)
{

   // cout<<"Draw chala of PIXMAPPPPP"<<endl;
    this->setWidth(this->getX1()-this->getX());
    this->setHeight(this->getY1()-this->getY());
    pt4->drawPixmap(this->getX(),this->getY(),this->getWidth(),this->getHeight(),this->picList[this->getListItem()]);
}

void Pictures::select(QPainter* ptt4)
{
    QPen pen(Qt::darkRed,Qt::SolidLine);
    pen.setWidth(5);
    ptt4->setPen(pen);
    if(this->getX()<this->getX1() && this->getY()<this->getY1())
    {
    ptt4->drawRect(this->getX()-5,this->getY()-5,10,10);
    ptt4->drawRect(this->getX()-5,(this->getY()+this->getHeight())-5,10,10);
    ptt4->drawRect((this->getX()+this->getWidth())-5,this->getY()-5,10,10);
    ptt4->drawRect((this->getX()+this->getWidth())-5,(this->getY()+this->getHeight())-5,10,10);
    ptt4->drawRect(this->getX()+(this->getWidth())/2-4,this->getY()-5,10,10);
    ptt4->drawRect((this->getX()+this->getWidth())-5,this->getY()-4+(this->getHeight()/2),10,10);
    ptt4->drawRect(this->getX()-5,this->getY()+(this->getHeight()/2)-4,10,10);
    ptt4->drawRect(this->getX()+(this->getWidth()/2)-4,(this->getY()+this->getHeight())-5,10,10);
    }
    else
    {
    ptt4->drawRect(this->getX1()-5,this->getY1()-5,10,10);
    ptt4->drawRect(this->getX1()-5,(this->getY1()+this->getHeight())-5,10,10);
    ptt4->drawRect((this->getX1()+this->getWidth())-5,this->getY1()-5,10,10);
    ptt4->drawRect((this->getX1()+this->getWidth())-5,(this->getY1()+this->getHeight())-5,10,10);
    ptt4->drawRect(this->getX1()+(this->getWidth())/2-4,this->getY1()-5,10,10);
    ptt4->drawRect((this->getX1()+this->getWidth())-5,this->getY1()-4+(this->getHeight()/2),10,10);
    ptt4->drawRect(this->getX1()-5,this->getY1()+(this->getHeight()/2)-4,10,10);
    ptt4->drawRect(this->getX1()+(this->getWidth()/2)-4,(this->getY1()+this->getHeight())-5,10,10);
    }
}

bool Pictures::isOwnedByMe(int xMe, int yMe)
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
}

bool Pictures::toResize(int xRe, int yRe)
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

void Pictures::resize(int xNew, int yNew)
{
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

void Pictures::move(int xChange, int yChange)
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

void Pictures::basic(int xB, int yB)
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

QString Pictures::getName()
{
 return "Illustration";
}

int Pictures::getListItem() const
{
    return listItem;
}

void Pictures::setListItem(int value)
{
    listItem = value;
}

QPixmap Pictures::getImage(int data)
{
    return this->picList[data];
}

int Pictures::getX1() const
{
    return x1;
}

void Pictures::setX1(int value)
{
    x1 = value;
}

int Pictures::getX2() const
{
    return x2;
}

void Pictures::setX2(int value)
{
    x2 = value;
}

int Pictures::getY1() const
{
    return y1;
}

void Pictures::setY1(int value)
{
    y1 = value;
}

int Pictures::getY2() const
{
    return y2;
}

void Pictures::setY2(int value)
{
    y2 = value;
}

int Pictures::getWidth() const
{
    return width;
}

void Pictures::setWidth(int value)
{
    width = value;
}

int Pictures::getHeight() const
{
    return height;
}

void Pictures::setHeight(int value)
{
    height = value;
}

int Pictures::getX() const
{
    return x;
}

void Pictures::setX(int value)
{
    x = value;
}

int Pictures::getY() const
{
    return y;
}

void Pictures::setY(int value)
{
    y = value;
}

int Pictures::getChangeInX() const
{
    return changeInX;
}

void Pictures::setChangeInX(int value)
{
    changeInX = value;
}

int Pictures::getChangeInY() const
{
    return changeInY;
}

void Pictures::setChangeInY(int value)
{
    changeInY = value;
}

int Pictures::getChangeInX1() const
{
    return changeInX1;
}

void Pictures::setChangeInX1(int value)
{
    changeInX1 = value;
}

int Pictures::getChangeInY1() const
{
    return changeInY1;
}

void Pictures::setChangeInY1(int value)
{
    changeInY1 = value;
}
