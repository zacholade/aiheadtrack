#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "Camera.h"


class CameraFactory
{
public:
	std::vector<std::shared_ptr<Camera>> findAllCameras(int width, int height, int exposure = -1, int gain = -1, int maxIndex = 5);
};
