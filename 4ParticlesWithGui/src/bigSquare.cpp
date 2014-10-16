//
//  bigSquare.cpp
//  4ParticlesWithGui
//
//  Created by Joshua Hollenbeck on 10/15/14.
//
//

#include "bigSquare.h"

bigSquare::bigSquare()
{
    //basic variables
    bigSquareLocation = ofPoint(1400,0);
    
    
    //physics
    bigSquareVelocity = ofPoint(ofRandom(0,-2),ofRandom(0,-10));
    bigSquareAcceleration = ofPoint(0.0,0.0);
    bigSquareScaler = 2;
    bigSquareMass = 5;
    
}

void bigSquare::update()
{
    bigSquareVelocity = bigSquareVelocity + bigSquareAcceleration;
    bigSquareVelocity.limit(10);
    bigSquareLocation = bigSquareLocation+bigSquareVelocity;
    bigSquareAcceleration*=0;
    
}

void bigSquare::draw()
{
    ofRect(bigSquareLocation,50,50);
}

void bigSquare::applyForce(ofPoint f)
{
    ofPoint force = f/bigSquareMass;  //create/init ofPoint force which is set to the incoming force/mass per
    
    bigSquareAcceleration+=force;    //add and assign our force to bigCircleAcceleration, per accumulation of forces
}
