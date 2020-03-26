#pragma once

#include "Mesh.h"
#include "glm/common.hpp"


class Camera {

public:
	Mesh* player;
	Camera(Mesh*);
	float distanceFromPlayer = 50;
	float angleAroundPlayer = 0;

	glm::vec3 position = glm::vec3(0, 0, 0);
	float pitch = 20;
	float yaw = 0;
	
	void move(float fov, float pitch1, float yaw1);
	void calculateCameraPosition(float, float);
	float calculateHorizontalDistance();
	float calculateVerticalDistance();
	void calculateZoom(float fov);
	void calculatePitch(float pitch1);
	void calculateAroundPlayer(float yaw1);
	

};