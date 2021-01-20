#include "CameraFactory.h"
#include <iostream>


int main()
{
	CameraFactory factory;
	std::vector<std::shared_ptr<Camera>> cameras = factory.findAllCameras(640, 480);
	for (std::shared_ptr<Camera> camera : cameras)
	{
		std::cout << camera << std::endl;
	}
	return 0;
}