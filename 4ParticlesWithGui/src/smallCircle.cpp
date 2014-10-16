//
//  smallCircle.cpp
//  4ParticlesWithGui
//
//  Created by Joshua Hollenbeck on 10/14/14.
//
//

#include "smallCircle.h"

smallCircle::smallCircle()
{
    //basic variables
    smallCircleLocation = ofPoint(500,0);
    
    
    //physics
    smallCircleVelocity = ofPoint(ofRandom(0,1),ofRandom(0,-5));
    smallCircleAcceleration = ofPoint(0.0,0.0);
    smallCircleScaler = 2;
    smallCircleMass = 30;
    
}
void smallCircle::update()
{
    smallCircleVelocity = smallCircleVelocity + smallCircleAcceleration;
    smallCircleVelocity.limit(10);
    smallCircleLocation = smallCircleLocation+smallCircleVelocity;
    smallCircleAcceleration*=0;
    
}

void smallCircle::draw()
{
    
    ofCircle(smallCircleLocation, 5);
}

void smallCircle::applyForce(ofPoint f)
{
    ofPoint force = f/smallCircleMass;
    
    smallCircleAcceleration+=force;
    
}

