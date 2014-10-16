//
//  square.cpp
//  4ParticlesWithGui
//
//  Created by Joshua Hollenbeck on 10/15/14.
//
//

#include "square.h"

square::square()
{
    //basic variables
    squareLocation = ofPoint(700,0);
    
    
    //physics
    squareVelocity = ofPoint(ofRandom(0,2),ofRandom(0,-10));
    squareAcceleration = ofPoint(0.0,0.0);
    squareScaler = 2;
    squareMass = 20;

}

void square::update()
{
    squareVelocity = squareVelocity + squareAcceleration;
    squareVelocity.limit(10);
    squareLocation = squareLocation+squareVelocity;
    squareAcceleration*=0;

}

void square::draw()
{
    ofRect(squareLocation,20,20);
}

void square::applyForce(ofPoint f)
{
    ofPoint force = f/squareMass;  //create/init ofPoint force which is set to the incoming force/mass per
    
    squareAcceleration+=force;    //add and assign our force to bigCircleAcceleration, per accumulation of forces
}
