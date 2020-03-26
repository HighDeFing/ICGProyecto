#include "Camera.h"

Camera::Camera(Mesh* player)
{
	this->player = player;
}

void Camera::move(float fov, float pitch1, float yaw1)
{
	calculateZoom(fov);
	calculatePitch(pitch1);
	calculateAroundPlayer(yaw1);
	float horizontalDistance = calculateHorizontalDistance();
	float verticalDistance = calculateVerticalDistance();
	calculateCameraPosition(horizontalDistance, verticalDistance);
}

void Camera::calculateCameraPosition(float horizDistance, float verticDistance)
{
	float theta = player->Qrotacion.y + angleAroundPlayer; 
	float offsetX = (horizDistance * glm::sin(glm::radians(theta)));
	float offsetZ = (horizDistance * glm::cos(glm::radians(theta)));
	position.x = player->vec4ftraslate.x - offsetX;
	position.z = player->vec4ftraslate.z - offsetZ;
	position.y = player->vec4ftraslate.y + verticDistance;
	position = glm::normalize(position);
}

float Camera::calculateHorizontalDistance()
{
	return (float)(distanceFromPlayer * glm::cos(glm::radians(pitch)));
}

float Camera::calculateVerticalDistance()
{
	return (float)(distanceFromPlayer * glm::sin(glm::radians(pitch)));
}

void Camera::calculateZoom(float fov)
{
	distanceFromPlayer -= fov;
}

void Camera::calculatePitch(float pitch1)
{
	pitch -= pitch1;
}

void Camera::calculateAroundPlayer(float yaw1)
{
	angleAroundPlayer -= yaw1;
}
