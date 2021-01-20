#include "CameraFactory.h"


std::unique_ptr<Camera> createCamera(int height, int width, int exposure = -1, int gain = -1)
{
	std::unique_ptr<Camera> camera;
	bool error = false;

	try
	{
		camera = std::make_unique<Camera>(width, height, 30, this->)
	}
}

std::vector<std::shared_ptr<Camera>> findAllCameras()
{

}