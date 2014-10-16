#include "ofApp.h"
#include "bigCircle.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //base app setup
    ofSetFullscreen(true);
    ofSetVerticalSync(true);
    ofEnableAntiAliasing();
    ofSetFrameRate(60);
    
    
    //gui setup
    gui.setup();
    //background color pannel setup
    gui.add(GravityX.setup("Global Gravity X",0.0,0.0,10.0)); //set gravity X to the gravity X slider
    gui.add(GravityY.setup("Global Gravity Y",0.3,0.0,10.0));//set gravity Y to the gravity Y slider
    
    //create a color gui for all 4 partciles systems using sliders
    gui.add(backgroundColor.setup("Background Color",ofColor(backgroundColorR,backgroundColorG,backgorundColorB),ofColor(0,0),ofColor(255,255)));
    
    gui.add(bigCircleColor.setup("Big Circle Color",ofColor(bigCircleColorR,bigCircleColorG,bigCircleColorB),ofColor(0,0),ofColor(255,255)));
    gui.add(smallCircleColor.setup("Small Circle Color",ofColor(smallCircleR,smallCircleG,smallCircleB),ofColor(0,0),ofColor(255,255)));
    gui.add(squareColor.setup("Square Color",ofColor(squareR,squareG,squareB),ofColor(0,0),ofColor(255,255)));
    
    gui.add(bigSquareColor.setup("Big Square Color",ofColor(bigSquareR,bigSquareG,bigSquareB),ofColor(0,0),ofColor(255,255)));

    
    //particles setup
    bigCircle bigP = bigCircle();
    BigCircles.push_back(bigP);
    
    smallCircle smallP = smallCircle();
    SmallCircles.push_back(smallP);
    
    square squareP = square();
    squares.push_back(squareP);
    
    bigSquare bigSquareP = bigSquare();
    BigSquares.push_back(bigSquareP);
    
    //global physics setup
    globalGravityX = 0.0;//set global gravity to be 0
    globalGravityY = 0.0;
    wind = ofPoint(0.0,0.0);// set wind to be 0
    
    //set the max amount of particles for all 4 particles systems
    maxBigCircles = 500;
    maxSmallCircles = 500;
    maxSquares = 500;
    maxBigSquares = 500;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //base app setup
    ofBackground(backgroundColor);
    
    //global physics update
    globalGravityX = GravityX;//set gravity on the x axis to the slider value in the GUI
    globalGravityY = GravityY;//set gravity on the y axis to the slider value in the GUI
    gravity = ofPoint(GravityX,GravityY);

    
    if(BigCircles.size()<maxBigCircles)
    {
        createNewBigCircle();//create a particle system using the Big Circle object
        checkBigParticles();// check the amount of big circles in the vector
    }
    
    if(SmallCircles.size()<maxSmallCircles)
    {
        createNewSmallCircle();//create a particle system using the small circle object
        checkSmallParticles();// check the amount of small Circles in the vector
    }
    
    if(squares.size()<maxSquares)
    {
        createNewSquare();//create a particle system using the square object
        checkSquareParticles();// check the amount of squares in the vector
    }
    
    if(BigSquares.size()<maxBigSquares)
    {
        createNewBigSquare();//create a particle system using the Big Square object
        checkBigSquareParticles();// check the amount of big squares in the vector
    }



    
    for(int i = 0; i < BigCircles.size(); i++)
    {
        BigCircles[i].applyForce(wind);//apply the wind force to the big circle particles
        BigCircles[i].applyForce(gravity);//apply the gravity force to the big circle particles
        BigCircles[i].update();
    }
    
    for(int i = 0; i < SmallCircles.size(); i++)
    {
        SmallCircles[i].applyForce(wind);//apply the wind force to the small circle particles
        SmallCircles[i].applyForce(gravity);//apply the gravity force to the small circle particles
        SmallCircles[i].update();
    }
    
    for(int i = 0; i < squares.size(); i++)
    {
        squares[i].applyForce(wind);//apply the wind force to the square particles
        squares[i].applyForce(gravity);//apply the gravity force to the square particles
        squares[i].update();
    }
    
    for(int i = 0; i < BigSquares.size(); i++)
    {
        BigSquares[i].applyForce(wind);//apply the wind force to the big square particles
        BigSquares[i].applyForce(gravity);//apply the gravity force to the big square particles
        BigSquares[i].update();
    }



    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i < BigCircles.size(); i++)
    {
        ofSetColor(bigCircleColor);//set the big circle color to be what the big circle color slider is
        BigCircles[i].draw();
    }
    
    for(int i = 0; i < SmallCircles.size(); i++)
    {
        ofSetColor(smallCircleColor);//set the small circle color to be what the small circle color slider is
        SmallCircles[i].draw();
    }
    
    for(int i = 0; i < squares.size(); i++)
    {
        ofSetColor(squareColor);//set the square color to be what the square color slider is
        squares[i].draw();
    }
    
    for(int i = 0; i < BigSquares.size(); i++)
    {
        ofSetColor(bigSquareColor);//set the big square color to be what the big square color slider is
        BigSquares[i].draw();
    }

    
    gui.draw();//draw gui
}

void ofApp::createNewBigCircle()
{
    bigCircle bigP = bigCircle();
    BigCircles.push_back(bigP);
}

void ofApp::createNewSmallCircle()
{
    smallCircle smallP = smallCircle();
    SmallCircles.push_back(smallP);
}

void ofApp::createNewSquare()
{
    square squareP = square();
    squares.push_back(squareP);
}

void ofApp::createNewBigSquare()
{
    bigSquare bigSquareP = bigSquare();
    BigSquares.push_back(bigSquareP);
}

void ofApp::checkBigParticles()
{
        if(BigCircles.size() == maxBigCircles)//if the size of the Vector is equal to the maximum set size then erase the oldest
        {
            BigCircles.erase(BigCircles.begin());//erase the oldest
        }
}

void ofApp::checkSmallParticles()
{
    if(SmallCircles.size() == maxSmallCircles)
    {
        SmallCircles.erase(SmallCircles.begin());//erase the oldest
    }

}
void ofApp::checkSquareParticles()
{
    if(squares.size() == maxSquares)
    {
        squares.erase(squares.begin());
    }
    
}

void ofApp::checkBigSquareParticles()
{
    if(BigSquares.size() == maxBigSquares)
    {
        BigSquares.erase(BigSquares.begin());
    }

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
    
}

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

