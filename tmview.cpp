#include "tmview.h"
#include<iostream>
using namespace std;
int s;
bool truFound=false;
bool moved=false;
bool resized=false;
int j=0;
int xRem;
int yRem;
TMView::TMView()
{

}

void TMView::add(DrawableComponent* drawing)
{
    this->list.push_back(drawing);
    cout<<"Index at which pushing is done"<<this->list.size()<<endl;
}

void TMView::draw(QPainter* pts)
{
    pts->eraseRect(200,110,1500,903);
    QPen pen(Qt::black,Qt::SolidLine);
    pen.setWidth(9);
    pts->setPen(pen);
    QBrush brush(Qt::white,Qt::SolidPattern);
    pts->setBrush(brush);
    pts->drawRect(200,110,1500,903);
    QPen pen1(Qt::lightGray);
   pen1.setWidth(1);
   pts->setPen(pen1);
    int y=115;
    int d=0;
    while(d<=30)
    {
    pts->drawLine(200+9,y,1700-9,y);
    y=y+50;
    d++;
    }
    DrawableComponent* d1;
    int x=0;
    while(x<this->list.size())
    {
    d1=this->list[x];
    d1->draw(pts);
    x++;
    }
}

bool TMView::ask(int xAsk, int yAsk)
{
    bool found=false;
    DrawableComponent* d0;
  int x=0;
  while(x<this->list.size())
  {
     d0=this->list[x];
     //cout<<x<<"==================="<<endl;
     cout<<this->list.size()<<"list size--------------------"<<endl;
     found=d0->isOwnedByMe(xAsk,yAsk);
     if(found==true)
     {
      s=x;
      xRem=xAsk;
      yRem=yAsk;
     //cout<<"Found at ki value:"<<s<<endl;
      break;
     }
  x++;
  }
  truFound=found;
  return found;
}

int TMView::getListIndex()
{
    return s;
}

void TMView::select(QPainter* ptse)
{
    if(keyPressed==false)
    {
    /*DrawableComponent* d2;
    d2=this->list[s];
    d2->select(ptse);*/
        int j=0;
        int x=0;
        while(x<this->pList.size())
        {
            if(s==this->pList[x])
            {
                j=1;
                break;
            }
            x++;
        }
        if(j==0)
        {
            DrawableComponent* d2;
                d2=this->list[s];
                d2->select(ptse);
        }
        else
        {
            cout<<"GROUP MEMBER HAI"<<endl;
            int h=0;
            while(h<this->pList.size())
            {
                DrawableComponent* df;
                df=this->list[this->pList[h]];
                cout<<"VALUE OF KKKKKKKKKK"<<h<<endl;
                df->basic(xRem,yRem);
                h++;
            }
            int k=0;
            while(k<this->pList.size())
            {
                DrawableComponent* df;
                df=this->list[this->pList[k]];
                cout<<"VALUE OF KKKKKKKKKK"<<k<<endl;
                df->select(ptse);
                k++;
            }
        }
}
    else
    {
       /* DrawableComponent* da;
        da=this->list[s];
        list1.push_back(da);
        //cout<<this->list1.size()<<"  Temporary List Ka Sizeoooooooooooooo"<<endl;
        DrawableComponent* df;
        int x=0;
        while(x<this->list1.size())
        {
            df=this->list1[x];
            df->select(ptse);
            x++;
        }*/
        list1.push_back(s);
        int x=0;
        while(x<this->list1.size())
        {
            DrawableComponent* df;
            df=this->list[this->list1[x]];
            df->select(ptse);
            x++;
        }

    }
}

bool TMView::toResize(int xR, int yR)
{
    bool yes=false;
    DrawableComponent* d3;
    d3=this->list[s];
   yes=d3->toResize(xR,yR);
   return yes;
}

void TMView::resize(int xNew, int yNew)
{
    DrawableComponent* d4;
    d4=this->list[s];
    resized=true;
    d4->resize(xNew,yNew);
}

void TMView::move(int xChange, int yChange)
{
   /* DrawableComponent* d5;
    d5=this->list[s];
    //cout<<"Component mmmmmmmmmmmmmmmmmmmmmmmmmmm"<<s<<endl;
    moved=true;
    d5->move(xChange,yChange);*/
    int p=0;
    int j=0;
    while(p<this->pList.size())
    {
        if(s==this->pList[p])
        {
            j=1;
            break;
        }
        p++;
    }
    if(j==0)
    {
        DrawableComponent* d5;
            d5=this->list[s];
           moved=true;
            d5->move(xChange,yChange);
    }
    else
    {
        DrawableComponent* dp;
        int g=0;
        while(g<this->pList.size())
        {
            dp=this->list[this->pList[g]];
            dp->move(xChange,yChange);
            g++;
        }
    }

}

void TMView::releaseDataStructures()
{
    this->list1.clear();
    this->pList.clear();
    DrawableComponent* dg;
    while(this->list.size())
    {
        cout<<" VDSSSFSFSFSS"<<this->list.size()<<endl;
    dg=this->list.front();
    this->list.pop_front();
    delete(dg);
    }
}

void TMView::releaseDataStructures1()
{
    this->list1.clear();
}

void TMView::createPermanent()
{
    int x=0;
    cout<<"this->list1.size()"<<this->list1.size()<<endl;
    while(x<this->list1.size())
    {
        cout<<"ATTTTTT: "<<this->list1.at(x)<<endl;
        cout<<"X KI VALUEEEEEE "<<x<<endl;
        cout<<"SIZE OF PLIST:  "<<pList.size()<<endl;
       pList.push_back(this->list1.at(x));
        x++;
    }
    this->list1.clear();
}

void TMView::destroyPermanent()
{
    this->pList.clear();
}

void TMView::destroy()
{
    //cout<<"TMVIEW KA DESTROY CHALA"<<endl;
    //cout<<"SKI VALUEE"<<s<<endl;
    if(this->list.size()>0)
    {
        if(truFound==true || moved==true || resized==true)
        {
            cout<<"ERASEEEEEEEE  "<<s<<endl;
    this->list.removeAt(s);
            moved=false;
            resized=false;
}
    }
}

void TMView::selectOnClick(int index,QPainter* pts)
{
    DrawableComponent* dc;
    dc=this->list[index];
    dc->select(pts);
    cout<<"Select on click chaliiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"<<endl;
    index=-1;
}

QStringList TMView::getName()
{
    QStringList sList;
    DrawableComponent* d8;
   int x=0;
   while(x<this->list.size())
   {
     d8=this->list[x];
    if(QString::compare("Scribble Tool",d8->getName(),Qt::CaseSensitivity::CaseInsensitive)==0)
    {
        if(scribbleActivated==true)

        {
          //  cout<<"Scribble is activated"<<endl;
            sList.push_back(d8->getName());

            scribbleActivated=false;
        }
        x++;
        continue;
    }
    else
    {
          if(QString::compare("Eraser",d8->getName(),Qt::CaseSensitivity::CaseInsensitive)!=0)
          {
      sList.push_back(d8->getName());
          }

    }



       x++;
   }
   //cout<<"Size of List::"<<sList.size()<<endl;
   return sList;
}


