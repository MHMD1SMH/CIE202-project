#pragma once
#include "drawable.h"

///////////////////////////////////////   collidable classes   /////////////////////////////////
//Base class for all collidable (objects that may collide with other objects)
    enum sideOfCollision{UPPER,LOWER,RIGHT,LEFT};
    struct ColliedInfo
    {
        bool isCollided=0;
        point PointOfCollision ;
        sideOfCollision side;
    };
class collidable :public drawable
{
protected:
    ColliedInfo ans;
    double deflectedangle, deflectedDistance;
public:
    collidable(point r_uprleft, int r_width, int r_height, game* r_pGame);
   
    virtual void collisionAction() = 0;    //action that should be performed upon collision
    ColliedInfo isCollided( const collidable* object1,const  collidable* object2);
    int DeflectedAngle(collidable* object1, collidable* ball);
};


