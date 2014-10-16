//
//  bigCircle.h
//  4ParticlesWithGui
//
//  Created by Joshua Hollenbeck on 10/14/14.
//
//

#ifndef ___ParticlesWithGui__bigCircle__
#define ___ParticlesWithGui__bigCircle__

#include <iostream>

#include "ofMain.h"
//#include "ofxGui.h"

class bigCircle
{
public:
    //constructor
    bigCircle();
    
    //variables
    ofPoint bigCircleLocation;       //ofPoint to describe location
    ofPoint bigCircleVelocity;       //ofPoint to describe velocity
    ofPoint bigCircleAcceleration;   //ofPoint to describe acceleration
    
    float bigCircleMass;                 //mass of our particle aka a scalar
    int bigCircleScaler;                  //scalar for our mass
    

    //functions
    void update();          //update method for movement calculations
    void draw();         //draw method
    void applyForce(ofPoint);      //receives a force as a ofPoint and applies it to our acceleration
    
};


#endif /* defined(___ParticlesWithGui__bigCircle__) */
