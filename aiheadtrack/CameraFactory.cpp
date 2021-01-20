#include "CameraFactory.h"


std::vector<std::shared_ptr<Camera>> CameraFactory::findAllCameras(int width, int height, int exposure, int gain, int maxIndex)
{
	std::vector<std::shared_ptr<Camera>> cameras;

	for (int index = 0; index < maxIndex; index++)
	{
		try
		{
			std::shared_ptr<Camera> camera = std::make_shared<Camera>(width, height, index); // TODO pass settings to camera.
			cameras.push_back(std::move(camera));
			std::cout << "Device found with ID: " << index << std::endl;
		}
		catch (std::runtime_error)
		{
			std::cout << "No found device found with ID: " << index << std::endl;
		}
	}
	return cameras;
}