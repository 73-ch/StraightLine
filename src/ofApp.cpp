#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofEnableAlphaBlending();
    
    // 直線の方向ベクトル
    dVec = vec3(ofRandom(-1,1), ofRandom(-1,1), ofRandom(-1,1));
    // 基準点
    bPos = vec3(ofRandom(-100, 100), ofRandom(-100, 100), ofRandom(-100, 100));
    
    cout << dVec << endl;
    
    // seed
    float d = 0;
    
    mesh.setUsage(GL_DYNAMIC_DRAW);
    
    for (int i = 0; i < VERTEX_NUM; i++) {
        mesh.addVertex(vec3(0));
        float r = ofRandom(10);
        d += r;
        seeds.push_back(d);
    }
    
    count = 0;
    randomSeed = vec3(ofRandom(1), ofRandom(1), ofRandom(1));
    
    shader.load("verts.glsl", "frag.glsl");
}

//--------------------------------------------------------------
void ofApp::update(){
    int frame_num = ofGetFrameNum();
    if (frame_num > 200 && frame_num % 10) count++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    mesh.getVbo().setAttributeData(shader.getAttributeLocation("seed"), &seeds[0], 1, seeds.size() , GL_STATIC_DRAW, sizeof(float));
    
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    
    shader.begin();
    
    shader.setUniform3f("dVec", dVec);
    shader.setUniform3f("bPos", bPos);
    shader.setUniform1i("count", count);
    shader.setUniform3f("randomSeed", randomSeed);
    
    mesh.draw();
    
    shader.end();
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
