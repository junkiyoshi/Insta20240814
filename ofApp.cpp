#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);

	ofEnableDepthTest();
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int width = 1000;
	int height = 1000;
	int len = 450;
	for (int z = -200; z <= 200; z += 20) {

		auto tmp_len = len * ofMap(z, -200, 200, 1, 0.5);
		auto color_value = ofMap(z, -200, 200, 39, 239);

		auto rotate_deg = ofMap(ofNoise(39, (z + 200) * 0.0025 + ofGetFrameNum() * 0.005), 0, 1, -180, 180);

		ofPushMatrix();
		ofTranslate(0, 0, z);
		ofRotate(rotate_deg);

		ofFill();
		ofSetColor(color_value);

		ofBeginShape();

		ofVertex(glm::vec2(width * -0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * 0.5));
		ofVertex(glm::vec2(width * -0.5, height * 0.5));

		ofNextContour(true);

		ofVertex(glm::vec2(width * -0.5 + tmp_len, height * -0.5 + tmp_len));
		ofVertex(glm::vec2(width * 0.5 - tmp_len, height * -0.5 + tmp_len));
		ofVertex(glm::vec2(width * 0.5 - tmp_len, height * 0.5 - tmp_len));
		ofVertex(glm::vec2(width * -0.5 + tmp_len, height * 0.5 - tmp_len));

		ofEndShape(true);

		ofNoFill();
		ofSetColor(39);

		ofBeginShape();

		ofVertex(glm::vec2(width * -0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * 0.5));
		ofVertex(glm::vec2(width * -0.5, height * 0.5));

		ofNextContour(true);

		ofVertex(glm::vec2(width * -0.5 + tmp_len, height * -0.5 + tmp_len));
		ofVertex(glm::vec2(width * 0.5 - tmp_len, height * -0.5 + tmp_len));
		ofVertex(glm::vec2(width * 0.5 - tmp_len, height * 0.5 - tmp_len));
		ofVertex(glm::vec2(width * -0.5 + tmp_len, height * 0.5 - tmp_len));

		ofEndShape(true);

		ofPopMatrix();
	}

	this->cam.end();

	/*
	int start = 125;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}