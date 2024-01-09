#include "collidable.h"
#include "gameConfig.h"
collidable::collidable(point r_uprleft, int r_width, int r_height, game* r_pGame):
			drawable(r_uprleft, r_width, r_height,  r_pGame)
{
}

CollisionInfo collidable::checkCollision(collidable* obj1, collidable* obj2)
{
    CollisionInfo CI1;
    CI1.collided = false;

    int obj1left = obj1->uprLft.x;
    int obj1right = obj1->uprLft.x + obj1->width;
    int obj1top = obj1->uprLft.y;
    int obj1bottom = obj1->uprLft.y + obj1->height;

    int obj2left = obj2->uprLft.x;
    int obj2right = obj2->uprLft.x + obj2->width;
    int obj2top = obj2->uprLft.y;
    int obj2bottom = obj2->uprLft.y + obj2->height;
    // Check if the bounding boxes overlap for left or right sides
    // calculating the collision point(x,y) 

    if (obj1right == obj2left)
        if (obj1top <= obj2top && obj1top >= obj2bottom)
        {
            CI1.collided = true;
            CI1.collisionPointX = obj1right;
            CI1.collisionPointY = obj1top + (obj1top + obj2bottom) / 2;
        }
        else if (obj1bottom >= obj2top && obj1bottom <= obj2bottom)
        {
            CI1.collided = true;
            CI1.collisionPointX = obj1right;
            CI1.collisionPointY = obj2top + (obj2top + obj1bottom) / 2;
        }
        else if (obj2top <= obj1top && obj2bottom >= obj1bottom)

        {
            CI1.collided = true;
            CI1.collisionPointX = obj1right;
            CI1.collisionPointY = obj2top + (obj2bottom - obj2top) / 2;
        }
    if (obj2right == obj1left)
        if (obj1top <= obj2top && obj1top >= obj2bottom)
        {
            CI1.collided = true;
            CI1.collisionPointX = obj1right;
            CI1.collisionPointY = obj1top + (obj1top + obj2bottom) / 2;
        }
        else if (obj1bottom >= obj2top && obj1bottom <= obj2bottom)
        {
            CI1.collided = true;
            CI1.collisionPointX = obj1right;
            CI1.collisionPointY = obj2top + (obj2top + obj1bottom) / 2;
        }
        else if (obj2top <= obj1top && obj2bottom >= obj1bottom)

        {
            CI1.collided = true;
            CI1.collisionPointX = obj1right;
            CI1.collisionPointY = obj2top + (obj2bottom - obj2top) / 2;
        }

    //check heck if the bounding boxes overlap for top or bottom sides
    //calculating the collision point(x, y)
    if (obj1top == obj2bottom)
        if (obj1left <= obj2left && obj1left >= obj2right)
        {
            CI1.collided = true;
            CI1.collisionPointX = obj1left + (obj2right - obj1left) / 2;
            CI1.collisionPointY = obj1right;
        }
        else  if (obj2left <= obj1left && obj2left >= obj1right)
        {
            CI1.collided = true;
            CI1.collisionPointX = obj2left + (obj1right - obj2left) / 2;
            CI1.collisionPointY = obj1right;
        }
        else if (obj2left >= obj1left && obj2right <= obj1right)

        {
            CI1.collided = true;
            CI1.collisionPointX = obj2left + (obj2right - obj2left) / 2;
            CI1.collisionPointY = obj1right;
        }
    if (obj2top == obj1bottom)
        if (obj1left <= obj2left && obj1left >= obj2right)
        {
            CI1.collided = true;
            CI1.collisionPointX = obj1left + (obj2right - obj1left) / 2;
            CI1.collisionPointY = obj1right;
        }
        else  if (obj2left <= obj1left && obj2left >= obj1right)
        {
            CI1.collided = true;
            CI1.collisionPointX = obj2left + (obj1right - obj2left) / 2;
            CI1.collisionPointY = obj1right;
        }
        else if (obj2left >= obj1left && obj2right <= obj1right)

        {
            CI1.collided = true;
            CI1.collisionPointX = obj2left + (obj2right - obj2left) / 2;
            CI1.collisionPointY = obj1right;
        };

	return CI1;
}

point collidable::getPoint()
{
    return uprLft;
}

int collidable::getWidth()
{
    return width;
}

int collidable::getHeight()
{
    return height;
}
