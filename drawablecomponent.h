#ifndef DRAWABLECOMPONENT_H
#define DRAWABLECOMPONENT_H
#include<QPainter>

class DrawableComponent
{
public:
    DrawableComponent();
    virtual void draw(QPainter*)=0;
    virtual void select(QPainter*)=0;
    virtual bool isOwnedByMe(int,int)=0;
    virtual bool toResize(int,int)=0;
    virtual void resize(int,int)=0;
    virtual void move(int,int)=0;
    virtual void basic(int,int)=0;
    virtual QString getName()=0;

};

#endif // DRAWABLECOMPONENT_H
