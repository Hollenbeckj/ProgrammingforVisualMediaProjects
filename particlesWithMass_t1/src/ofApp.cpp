#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1920, 1080);
    ofSetFrameRate(30);
    ofSetFullscreen(true);
    
    ofSetBackgroundAuto(true);
    ofBackground(100, 50, 50);
    
    //p = BasicParticle();    //initialize our BasicParticle p
    
    BasicParticle tempP = BasicParticle();  //create a local BasicParticle to pass into our vector which will store BasicParticle objects
    
    particles.push_back(tempP);   //add a new BasicParticle to the rear of our vector
    
    //initializing our forces
    wind = ofPoint(0.2,0.0);
    gravity = ofPoint(0.0,0.1);
    
    counter = 0;    //counter used to trigger wind events
    maxParticles = 1000; //set our max amount of particles
}

//--------------------------------------------------------------
void ofApp::update(){
    //p.update();     //calculate our BasicParticle object's new position
    
    if(particles.size()<maxParticles){
        createNewParticle();        //create a new BasicParticle and place at the back of our vector
        //particleSizeChecker();      //check to see if there are too many particles in our vector
    }
    
    for(int i = 0; i < particles.size(); i++){      //iterate through our vector to update our BasicParticle Objects
        particles[i].applyForce(wind);      //pass our wind ofPoint and apply it on our particle via the applyForces method
        particles[i].applyForce(gravity);   //same for gravity
        
        particles[i].update();  //update our particle at location i within our vector
    }
    
    //cout<<"CURRENT NUMBER OF PARTICLES = "<<particles.size()<<endl;
    
    //ADD RANDOM WIND EVENT
    /*
    if (counter == 500) {
        wind.x = ofRandom(-2.0,2.0);
        wind.y = ofRandom(-2.0,2.0);
        counter++;
        cout<<"RANDOM WIND EVENT"<<endl;
        cout<<"WIND = "<<wind.x<<","<<wind.y<<endl;
    }else if(counter > 1000){
        wind.x = 0.2;
        wind.y = 0.0;
        counter = 0;
        cout<<"WIND RESET"<<endl;
    }else{
        counter++;
    }
    */
}

//--------------------------------------------------------------
void ofApp::draw(){
    //p.display();   //draw our particle on screen
    
    for(int i = 0; i < particles.size(); i++){      //iterate through our vector to draw our BasicParticle Objects
        particles[i].display();  //display our particle
    }
    
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15); //display fps

    frameNum++; //increment the frame number
    
    //recordIMGSeq();
}

void ofApp::recordIMGSeq(){
    ofImage image;  //ofImage to store screen grab
    image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());    //grab the screen
    image.saveImage("testSG_"+ofToString(frameNum)+".bmp");
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //on our mouse click add a new particle to our vector
    createNewParticle();        //create a new BasicParticle and place at the back of our vector
    particleSizeChecker();      //check to see if there are too many particles in our vector
}

//--------------particleSizeChecker--------------------
void ofApp::particleSizeChecker(){
    
    if(particles.size() > maxParticles){            //if there are over 1000 particles within our vector remove the oldest aka the 1st particle in the vector
        particles.erase(particles.begin());
    }
}
//------------END particleSizeChecker----------------------------

//---------------------createNewParticle-------------------------
void ofApp::createNewParticle(){
    BasicParticle tempP = BasicParticle();  //create a local BasicParticle to pass into our vector which will store BasicParticle objects
    
    particles.push_back(tempP);   //add a new BasicParticle to the rear of our vector
}
//------------------End createNewParticle------------------------

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
