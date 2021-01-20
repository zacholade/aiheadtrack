#pragma once

#include <opencv2/highgui/highgui.hpp>

class Camera {
private:
	int width, height, fps;
	int camNativeHeight, camNativeWidth, camNativeFps;
	bool isValid = false;  // Is the camera a valid camera to use
	cv::VideoCapture capture;
	cv::Size size;
	float exposure, gain;
	int index;
	int CV_BACKEND = cv::CAP_DSHOW;

	bool isCameraAvailable();

public:
	Camera(int width = 640, int height = 480, int fps = 30, int index = 0);
	~Camera();
	void start();
	void stop();
	bool getFrame(uint8_t* buffer);
};