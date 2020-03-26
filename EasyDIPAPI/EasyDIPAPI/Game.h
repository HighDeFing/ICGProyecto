#pragma once

#include "Mesh.h"
#include <glm/common.hpp>

class Game {

public:

	bool Check_Collision(Mesh* one, Mesh* two)
	{
		// Collision x-axis?
		bool collisionX = glm::abs((one->vec4ftraslate.x + one->size.x) - (two->vec4ftraslate.x + two->size.x)) <= glm::abs((2 * two->size.x * two->vec4fscale.x));

		/*std::cout << "glm::abs((one->vec4ftraslate.x+one->size.x) - (two->vec4ftraslate.x+two->size.x))=" << glm::abs((one->vec4ftraslate.x + one->size.x) - (two->vec4ftraslate.x + two->size.x)) << '\n';
		std::cout << "2*two->size.x*two->vec4fscale.x" << 2*two->size.x*two->vec4fscale.x << '\n';*/
		// Collision z-axis?
		bool collisionZ = glm::abs((one->vec4ftraslate.z + one->size.z) - (two->vec4ftraslate.z + two->size.z)) <= glm::abs((2 * two->size.z * two->vec4fscale.z));

		return collisionX && collisionZ;

	}
};