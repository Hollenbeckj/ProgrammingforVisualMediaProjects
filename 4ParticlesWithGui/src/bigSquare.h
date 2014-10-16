//
//  bigSquare.h
//  4ParticlesWithGui
//
//  Created by Joshua Hollenbeck on 10/15/14.
//
//

#ifndef ___ParticlesWithGui__bigSquare__
#define ___ParticlesWithGui__bigSquare__

#include <iostream>

#include "ofMain.h"

class bigSquare
{
public:
    
    //constructor
    bigSquare();
    
    //variables
    ofPoint bigSquareLocation;       //ofPoint to describe location
    ofPoint bigSquareVelocity;       //ofPoint to describe velocity
    ofPoint bigSquareAcceleration;   //ofPoint to describe acceleration
    
    float bigSquareMass;
    int bigSquareScaler;
    
    //functions
    void update();          //update method for movement calculations
    void draw();         //draw method
    void applyForce(ofPoint);      //receives a force as a ofPoint and applies it to our acceleration
};

#endif /* defined(___ParticlesWithGui__bigSquare__) */
