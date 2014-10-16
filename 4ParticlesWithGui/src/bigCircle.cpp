//
//  bigCircle.cpp
//  4ParticlesWithGui
//
//  Created by Joshua Hollenbeck on 10/14/14.
//
//

#include "bigCircle.h"

bigCircle::bigCircle()
{
    //basic variables
    bigCircleLocation = ofPoint(0,0);
    
    
    //physics
    bigCircleVelocity = ofPoint(ofRandom(0,5),ofRandom(0,5));
    bigCircleAcceleration = ofPoint(0.0,0.0);
    bigCircleScaler = 2;
    bigCircleMass = 5;
    
}

void bigCircle::update()
{
    bigCircleVelocity = bigCircleVelocity + bigCircleAcceleration;
    bigCircleVelocity.limit(10);
    bigCircleLocation = bigCircleLocation+bigCircleVelocity;
    bigCircleAcceleration*=0;
    
}

void bigCircle::draw()
{
    
    ofCircle(bigCircleLocation, 30);     //draw our particle
    
}

void bigCircle::applyForce(ofPoint f)
{
    ofPoint force = f/bigCircleMass;  //create/init ofPoint force which is set to the incoming force/mass per
    
    bigCircleAcceleration+=force;    //add and assign our force to bigCircleAcceleration, per accumulation of forces
    
}
