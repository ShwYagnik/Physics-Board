#ifndef TMVIEW_H
#define TMVIEW_H
#include<drawablecomponent.h>
#include<QPainter>
#include<QList>

class TMView
{
public:
    TMView();
    void add(DrawableComponent*);
    void draw(QPainter*);
    bool ask(int,int);
    int getListIndex();
    void select(QPainter*);
    bool toResize(int,int);
    void resize(int,int);
    void move(int,int);
    void releaseDataStructures();
    void releaseDataStructures1();
    void createPermanent();
    void destroyPermanent();
    void destroy();
    void selectOnClick(int index,QPainter*);
    QStringList getName();
    bool keyPressed=false;
    bool scribbleActivated=false;
private:
    QList<DrawableComponent*> list;
    QList<int>list1;
    QList<int>pList;


};

#endif // TMVIEW_H
