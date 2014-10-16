#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "bigCircle.h"
#include "smallCircle.h"
#include "square.h"
#include "bigSquare.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //partcile functions
    void particleSizeChecker();     //Function to check the size of our particle array
    void createNewBigCircle();       //Function to create new particles for our vector of BasicParticle objects
    void createNewSmallCircle();
    void createNewSquare();//create squares
    void createNewBigSquare();
    void checkBigParticles();
    void checkSmallParticles();
    void checkSquareParticles();//check squares
    void checkBigSquareParticles();
    
    //Base variables
    int backgroundColorR;
    int backgroundColorG;
    int backgorundColorB;
    
    int bigCircleColorR;
    int bigCircleColorG;
    int bigCircleColorB;
    
    int smallCircleR;
    int smallCircleG;
    int smallCircleB;
    
    int squareR;
    int squareG;
    int squareB;
    
    int bigSquareR;
    int bigSquareG;
    int bigSquareB;
    
    float globalGravityX;
    float globalGravityY;
    
    int maxBigCircles;   //maximum number of particles
    int maxSmallCircles;
    int maxSquares;
    int maxBigSquares;
    
    // physics forces
    ofPoint wind;   //ofPoint for the wind force
    ofPoint gravity;    //ofPoint for some fake gravity
    
    ofVec2f smallCircleRotation;

    //vectors
    vector<bigCircle> BigCircles;
    vector<smallCircle> SmallCircles;
    vector<square> squares;
    vector<bigSquare> BigSquares;
    
    
    //gui variables
    ofxPanel gui;
    ofxColorSlider backgroundColor; // slider for background color
    ofxColorSlider bigCircleColor; // slider for big Circle particles color
    ofxColorSlider smallCircleColor;
    ofxFloatSlider GravityX;
    ofxFloatSlider GravityY;
    ofxColorSlider squareColor;
    ofxColorSlider bigSquareColor;
    
};
