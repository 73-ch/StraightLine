#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofEnableAlphaBlending();
    
    // 直線の方向ベクトル
    dVec = vec3(ofRandom(-1,1), ofRandom(-1,1), ofRandom(-1,1));
    // 基準点
    bPos = vec3(ofRandom(-100, 100), ofRandom(-100, 100), ofRandom(-100, 100));
    
    // seed
    float d = 0;
    
    mesh.setUsage(GL_DYNAMIC_DRAW);
    
    for (int i = 0; i < VERTEX_NUM; i++) {
        mesh.addVertex(vec3(0));
        float r = ofRandom(0.3);
        d += r;
        seeds.push_back(d);
    }
    
    shader.load("verts.glsl", "frag.glsl");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    shader.begin();
    mesh.getVbo().setAttributeData(shader.getAttributeLocation("seed"), &seeds[0], 1, VERTEX_NUM, GL_STATIC_DRAW, sizeof(float));
    shader.setUniform3f("dVec", dVec);
    shader.setUniform3f("bPos", bPos);
    
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    mesh.draw();
    
    shader.end();
    ofSetColor(255, 255, 255, 50);
//    ofDrawBox(0, 0, 0, 100, 100, 100);
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
