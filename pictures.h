#ifndef PICTURES_H
#define PICTURES_H
#include<drawablecomponent.h>
#include<QPainter>
#include<QPixmap>
class Pictures:public DrawableComponent
{
public:
    Pictures();
    void draw(QPainter*);
    void select(QPainter*);
    bool isOwnedByMe(int,int);
    bool toResize(int, int);
    void resize(int, int);
    void move(int, int);
    void basic(int, int);
    QString getName();
    int getListItem() const;
    void setListItem(int value);
   QPixmap getImage(int data);
   int getX1() const;
   void setX1(int value);

   int getX2() const;
   void setX2(int value);

   int getY1() const;
   void setY1(int value);

   int getY2() const;
   void setY2(int value);

   int getWidth() const;
   void setWidth(int value);

   int getHeight() const;
   void setHeight(int value);

   int getX() const;
   void setX(int value);

   int getY() const;
   void setY(int value);

   int getChangeInX() const;
   void setChangeInX(int value);

   int getChangeInY() const;
   void setChangeInY(int value);

   int getChangeInX1() const;
   void setChangeInX1(int value);

   int getChangeInY1() const;
   void setChangeInY1(int value);

private:
   int listItem;
   QList<QPixmap> picList;
   int x1;
    int x2;
    int y1;
    int y2;
    int x;
    int y;
    int changeInX;
    int changeInY;
    int changeInX1;
    int changeInY1;
    int width;
    int height;
};

#endif // PICTURES_H
