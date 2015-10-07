#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    model.loadModel("statue_head.obj",true);
    model.calculateDimensions();
    model.optimizeScene();
    model.setPosition(0,0,0);
    mMesh = model.getMesh(0);
    grid.setupIndicesAuto();
    
    ofVec3f gridCenter = model.getSceneCenter(); //IS actually center
    
    ofVec3f gridMin = model.getSceneMin()*model.getNormalizedScale();
    ofVec3f gridMax = model.getSceneMax()*model.getNormalizedScale();
    
    ofVec3f gDelta = (gridMax-gridMin)/2;
    //float gW = sqrt((gridMax.x*gridMax.x)+(gridMin.x*gridMin.x));
    //float gH = sqrt((gridMax.y*gridMax.y)+(gridMin.y*gridMin.y));
    //float gD = sqrt((gridMax.z*gridMax.z)+(gridMin.z*gridMin.z));
    /*
    mBox.push_back(ofPoint(gridMax.x,gridMax.y,gridMin.z));
    mBox.push_back(ofPoint(gridMax.x,gridMax.y,gridMax.z));
    mBox.push_back(ofPoint(gridMin.x,gridMax.y,gridMax.z));
    mBox.push_back(ofPoint(gridMin.x,gridMax.y,gridMin.z));
    mBox.push_back(ofPoint(gridMax.x,gridMin.y,gridMin.z));//problem at gridMin
    mBox.push_back(ofPoint(gridMax.x,gridMin.y,gridMax.z));
    mBox.push_back(ofPoint(gridMin.x,gridMin.y,gridMax.z));
    mBox.push_back(ofPoint(gridMin.x,gridMin.y,gridMin.z));
    */
    
    mBox.push_back(ofPoint(gDelta.x,gDelta.y,-gDelta.z));
    mBox.push_back(ofPoint(gDelta.x,gDelta.y,gDelta.z));
    mBox.push_back(ofPoint(-gDelta.x,gDelta.y,gDelta.z));
    mBox.push_back(ofPoint(-gDelta.x,gDelta.y,-gDelta.z));
    mBox.push_back(ofPoint(gDelta.x,-gDelta.y,-gDelta.z));//problem at gridMin
    mBox.push_back(ofPoint(gDelta.x,-gDelta.y,gDelta.z));
    mBox.push_back(ofPoint(-gDelta.x,-gDelta.y,gDelta.z));
    mBox.push_back(ofPoint(-gDelta.x,-gDelta.y,-gDelta.z));
    
    
    grid.addVertex(gridCenter);
    grid.addVertices(mBox);
    grid.setMode(OF_PRIMITIVE_LINE_LOOP);
    
    //euler lines
    euler.addVertex(ofPoint(-300,0,0));
    euler.addVertex(ofPoint(300,0,0));
    euler.addVertex(ofPoint(0,-300,0));
    euler.addVertex(ofPoint(0,300,0));
    euler.addVertex(ofPoint(0,0,-300));
    euler.addVertex(ofPoint(0,0,300));
    
    euler.setMode(OF_PRIMITIVE_LINES);
    
    glEnable(GL_POINT_SMOOTH);
    glPointSize(15);
}

//--------------------------------------------------------------
void ofApp::update(){
    model.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofEnableDepthTest();
    
    cam.begin();
        ofSetColor(ofColor(200,200,200));
        euler.draw();
        ofSetColor(ofColor(100,200,240));
        grid.drawWireframe();
        ofSetColor(100);
        model.drawWireframe();
    cam.end();
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
