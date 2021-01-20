#pragma once

#include <vector>
#include <memory>

#include "Camera.h"


class CameraFactory
{
public:
	std::unique_ptr<Camera> createCamera(int height, int width, int exposure = -1, int gain = -1);
	std::vector<std::shared_ptr<Camera>> findAllCameras();
};

