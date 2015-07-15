#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
		
	//we load a font and tell OF to make outlines so we can draw it as GL shapes rather than textures
	font.loadFont("type/verdana.ttf", 100, true, false, true, 0.4, 72);
    shader.load("shaders/simple.vert", "shaders/simple.frag");

	doShader = false;
    
    vector<ofVec3f> positions;
    vector<unsigned int> indices;
    //vector<ofVec2f> texcoords;
    for(int i=0; i < 100; ++i){
        positions.push_back(ofVec3f(i*3,100+100*cos(i/10.0),0));
        indices.push_back(i);
        //texcoords.push_back(ofVec2f(1,1));
    }
    
    mesh.setVertexData(positions.data(), 100, GL_STATIC_DRAW);
    mesh.setIndexData(indices.data(), 100, GL_STATIC_DRAW);
    //mesh.setTexCoordData(texcoords.data(), 100, GL_STATIC_DRAW);
    
    
    fbo.allocate(64, 64);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(225);
	ofDrawBitmapString("'s' toggles shader", 10, 20);

	ofSetColor(245, 58, 135);
	ofFill();
    
    fbo.begin();
    ofClear(255,0,0,255);
    fbo.end();
    
    fbo.draw(300,0);
	
	if( doShader ){
		shader.begin();
			//we want to pass in some varrying values to animate our type / color 
			shader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
			shader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 );
			
			//we also pass in the mouse position 
			//we have to transform the coords to what the shader is expecting which is 0,0 in the center and y axis flipped. 
			shader.setUniform2f("mouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY );

	}
	
		//finally draw our text
		font.drawStringAsShapes("openFrameworks", 90, 260);
    //fbo.getTextureReference().bind();
    mesh.drawElements(GL_POINTS, 100);
    //fbo.getTextureReference().unbind();
	
	if( doShader ){
		shader.end();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	if( key == 's' ){
		doShader = !doShader;
	}	
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

