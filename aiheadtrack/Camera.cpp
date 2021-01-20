#include "Camera.h"


Camera::Camera(int width, int height, int fps, int index) :
	capture(),
	index(index),
	size(0, 0)
{
	this->width = width;
	this->height = height;
	this->fps = fps;

	CV_BACKEND = cv::CAP_DSHOW;  // First we try to get a camera through direct show backend.
	if (!isCameraAvailable())
	{
		CV_BACKEND = cv::CAP_MSMF;  // Then if none found, we try again with media foundation backend.
		if (!isCameraAvailable())
		{
			throw std::runtime_error("No camera is available.");
		}
	}

	isValid = true;

	if (width < 0 || height < 0)
	{
		this->width = camNativeWidth;
		this->height = camNativeHeight;
	}

	if (fps < 0)
	{
		this->fps = camNativeFps;
	}
	exposure, gain = -1;
}

Camera::~Camera()
{
	stop();
}
bool Camera::isCameraAvailable()
{
	bool available = false;

	capture.open(index, CV_BACKEND);
	available = capture.isOpened();
	if (available)
	{
		cv::Mat frame;
		capture.read(frame);
		if (frame.empty())
		{
			// TODO if camera isnt available then we need to also reset these native parameters.
			return false;
		}
		camNativeWidth = (int)capture.get(cv::CAP_PROP_FRAME_WIDTH);
		camNativeHeight = (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT);
		camNativeFps = std::max(30, (int)capture.get(cv::CAP_PROP_FPS));  // limit framerate to 30.
		capture.release();
	}
	return available;
}

void Camera::start()
{
	capture.open(index, CV_BACKEND);
	if (!capture.isOpened())
	{
		throw std::runtime_error("No compatible camera found.");
	}
	capture.set(cv::CAP_PROP_FRAME_HEIGHT, this->height);
	capture.set(cv::CAP_PROP_FRAME_WIDTH, this->width);
	capture.set(cv::CAP_PROP_FPS, this->fps);
}

void Camera::stop()
{
	capture.release();
}

bool Camera::getFrame(uint8_t* buffer)
{
	cv::Mat frame;
	bool hasRead = capture.read(frame);
	if (!hasRead)
	{
		return false;
	}
	cv::flip(frame, frame, 1);  // Flip matrix on the horizontal (columns) axis.
	for (int i = 0; i < frame.cols * frame.rows * 3; i++)
	{
		buffer[i] = frame.data[i];
	}
	return true;
}