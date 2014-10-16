//
//  smallCircle.h
//  4ParticlesWithGui
//
//  Created by Joshua Hollenbeck on 10/14/14.
//
//

#ifndef ___ParticlesWithGui__smallCircle__
#define ___ParticlesWithGui__smallCircle__

#include <iostream>
#include "ofMain.h"

class smallCircle
{
public:
    //constructor
    smallCircle();
    
    //variables
    ofPoint smallCircleLocation;       //ofPoint to describe location
    ofPoint smallCircleVelocity;       //ofPoint to describe velocity
    ofPoint smallCircleAcceleration;   //ofPoint to describe acceleration
    
    float smallCircleMass;
    int smallCircleScaler;

    //functions
    void update();          //update method for movement calculations
    void draw();         //draw method
    void applyForce(ofPoint);      //receives a force as a ofPoint and applies it to our acceleration
    
};
#endif /* defined(___ParticlesWithGui__smallCircle__) */
