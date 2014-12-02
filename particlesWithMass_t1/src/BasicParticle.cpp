//
//  BasicParticle.cpp
//  vectors_t1
//
//  Created by Emery Martin on 9/23/14.
//
//

#include "BasicParticle.h"

BasicParticle::BasicParticle(){     //default constructor
    
    location = ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));    //generate a random location to start from within the sketch window
    
    //velocity = ofPoint(ofRandom(-4,4),ofRandom(-4,4));    //this may overcome our forces
    velocity = ofPoint(0,0);                                //starting with 0 instead
    
    acceleration = ofPoint(0.0,0.0);      //set acceleration to nothing to start so rely purely on incoming forces
    
    //accelerationScaler = 0.5;   //scaler used to change the magnitude of our direction unit vector used for acceleration. Lower the scaler value the slower the particle is able to steer towards its target
    //accelerationScaler = ofRandom(0.1,0.5);
    
    s = 2;     //scalar of our mass
    
    mass = ofRandom(1,20);  //init mass as a random between 1-19.999...
}

void BasicParticle::update(){
    
    /*
    ofPoint mouseLocation = ofPoint(ofGetMouseX(),ofGetMouseY());       //init our mouse location vector with the current mouseX/Y locations
    
    ofPoint direction = mouseLocation - location;   //subtract location from mouseLocation to find the difference between the two vectors and establish our heading
    
    cout<<"DIRECTION = ("<<direction.x<<","<<direction.y<<endl;     //print out our direction
    
    direction.normalize();  //normalize our direction so that our magnitude is now 1 and we have only heading information
    
    acceleration = direction*accelerationScaler;   //set our acceleration to our direction and scale. Ensures acceleration is pointed in the direction we want our particle to travel and sets the rate of that acceleration
     */
    
    velocity = velocity+acceleration; //add acceleration to velocity to change over time
    
    velocity.limit(10); //limit velocity to 10. If our velocity hits 10 it will stay at 10.
    
    location = location+velocity;     //add velocity to location to move at a constant velocity.
    
    edgeCheck();    //if past the screen edge reset to opposite end of x or y
    
    acceleration*=0;    //scale acceleration by 0 and assign back to itself so forces do not continue to stack
}

//Method to apply force
void BasicParticle::applyForce(ofPoint f){
    ofPoint force = f/mass;  //create/init ofPoint force which is set to the incoming force/mass per
    
    acceleration+=force;    //add and assign our force to acceleration, per accumulation of forces
}


void BasicParticle::display(){
    
    ofSetColor(255,50);
    ofFill();
    ofEllipse(location, mass*s, mass*s);      //draw our particle
    
    /*
    //used to draw a line between our particle and the current mouse location
    ofPoint mouseLocation = ofPoint(ofGetMouseX(),ofGetMouseY());
    ofLine(location, mouseLocation);
    */
}


void BasicParticle::edgeCheck(){
    
    //do a bounds check for x. reset to opposite side of screen if out of bounds
    if(location.x > ofGetWidth()){
        location.x = ofGetWidth();
        velocity.x *= -1;       //flip our velocity if at left edge
    }else if(location.x < 0){
        location.x = 0;
        velocity.x *= -1;       //flip our velocity if at right edge
    }
    
    //do a bounds check for y. reset to opposite side of screen if out of bounds
    if(location.y > ofGetHeight()){
        location.y = ofGetHeight();
        velocity.y *= -1;      //flip our velocity if we hit the bottom edge
    }else if(location.y < 0){
        location.y = 0;
        velocity.y *= -1;       //flip our velocity if we hit the top edge
    }
    
}