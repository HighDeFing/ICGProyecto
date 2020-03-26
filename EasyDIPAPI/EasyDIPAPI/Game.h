#pragma once

#include "Mesh.h"
#include <glm/common.hpp>

class Game {

	enum Direction {
		UP,
		RIGHT,
		DOWN,
		LEFT
	};

public:
	Direction coll_dir;
	Mesh* Character;

	float move_pase = 0.020f;
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

	//this gets the best direction where to bounce too.
	Direction VectorDirection(glm::vec2 target)
	{
		glm::vec2 compass[] = {
			glm::vec2(0.0f, 1.0f),	// up
			glm::vec2(1.0f, 0.0f),	// right
			glm::vec2(0.0f, -1.0f),	// down
			glm::vec2(-1.0f, 0.0f)	// left
		};
		GLfloat max = 0.0f;
		GLuint best_match = -1;
		for (GLuint i = 0; i < 4; i++)
		{
			GLfloat dot_product = glm::dot(glm::normalize(target), compass[i]);
			if (dot_product > max)
			{
				max = dot_product;
				best_match = i;
			}
		}
		//std::cout << best_match;
		return (Direction)best_match;
	}
	

	//THE only one that colides is the CHARACTER but it can be generalized
	void handle_right_colliton(Mesh *object)
	{
		float penetration = glm::abs((Character->vec4ftraslate.x + Character->size.x) - (object->vec4ftraslate.x + object->size.x));
		//std::cout << glm::abs((Character->vec4ftraslate.x + Character->size.x) - (object->vec4ftraslate.x + object->size.x));
		Character->vec4ftraslate.x -= penetration;
	}
	void handle_left_colliton(Mesh* object)
	{
		float penetration =  glm::abs((Character->vec4ftraslate.x + Character->size.x) - (object->vec4ftraslate.x + object->size.x));
		Character->vec4ftraslate.x += penetration;
	}
	void handle_up_colliton(Mesh* object)
	{
		float penetration = glm::abs((Character->vec4ftraslate.z + Character->size.z) - (object->vec4ftraslate.z + object->size.z));
		Character->vec4ftraslate.z += penetration;
	}
	void handle_down_colliton(Mesh* object)
	{
		float penetration = glm::abs((Character->vec4ftraslate.z + Character->size.z) - (object->vec4ftraslate.z + object->size.z));
		Character->vec4ftraslate.z -= penetration;
	}

	//this is the vector that it form between the two objects, just the difference of its position with the other position.
	glm::vec2 set_target(Mesh* one, Mesh* two)
	{
		return glm::vec2((one->vec4ftraslate.x + one->size.x) - (two->vec4ftraslate.x + two->size.x), (one->vec4ftraslate.z + one->size.z) - (two->vec4ftraslate.z + two->size.z));
	}

	//The way it handles collitions is getting two objects, the only one that can collide is the character those are the handles, but it can be generalized to the two objects
	//it bounces out off an object it collides, one bounces over two

	void Resolve_collition(Mesh* one, Mesh* two)
	{
		Direction dir = VectorDirection(set_target(one,two));
		if (dir == RIGHT || dir == LEFT) 
		{
			//this is backwards for some reason, but whatever...
			if(dir == LEFT)
			handle_right_colliton(two);
			else
			handle_left_colliton(two);
		}
		else
		{
			if (dir == UP)
			handle_up_colliton(two);
			else
			handle_down_colliton(two);
		}

	}

	//TODO Handle the rest of the collisions with other objects

	//TODO load the rest of the objects of the map
	 

};