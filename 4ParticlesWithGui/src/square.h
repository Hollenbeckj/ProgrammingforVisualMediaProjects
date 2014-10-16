//
//  square.h
//  4ParticlesWithGui
//
//  Created by Joshua Hollenbeck on 10/15/14.
//
//

#ifndef ___ParticlesWithGui__square__
#define ___ParticlesWithGui__square__

#include <iostream>
#include "ofMain.h"

class square
{
public:
    
    //constructor
    square();
    
    //variables
    ofPoint squareLocation;       //ofPoint to describe location
    ofPoint squareVelocity;       //ofPoint to describe velocity
    ofPoint squareAcceleration;   //ofPoint to describe acceleration
    
    float squareMass;
    int squareScaler;
    
    //functions
    void update();          //update method for movement calculations
    void draw();         //draw method
    void applyForce(ofPoint);      //receives a force as a ofPoint and applies it to our acceleration
};

#endif /* defined(___ParticlesWithGui__square__) */
