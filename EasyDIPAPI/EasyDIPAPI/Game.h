#pragma once

#include "Mesh.h"
#include <glm/common.hpp>


extern Shader *bwShader;

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
	glm::vec3 cameraPos;
	glm::mat4 view;
	glm::mat4 proj;
	std::vector <Mesh*> walls;
	std::vector <Mesh*> coins;
	bool hitting_wall = false;

	const float smooth_collition = 0.17;

	float move_pase = 0.020f*8;
	float radious = 1.20;
	bool Check_Collision(Mesh* one, Mesh* two)
	{
		// Collision x-axis?
		bool collisionX = glm::abs((one->vec4ftraslate.x + one->size.x) - (two->vec4ftraslate.x + two->size.x)) <= glm::abs((radious * two->size.x * two->vec4fscale.x));

		/*std::cout << "glm::abs((one->vec4ftraslate.x+one->size.x) - (two->vec4ftraslate.x+two->size.x))=" << glm::abs((one->vec4ftraslate.x + one->size.x) - (two->vec4ftraslate.x + two->size.x)) << '\n';
		std::cout << "2*two->size.x*two->vec4fscale.x" << 2*two->size.x*two->vec4fscale.x << '\n';*/
		// Collision z-axis?
		bool collisionZ = glm::abs((one->vec4ftraslate.z + one->size.z) - (two->vec4ftraslate.z + two->size.z)) <= glm::abs((radious * two->size.z * two->vec4fscale.z));
		
		return collisionX && collisionZ;
	}

	bool Check_walls1()
	{
		float xmin = -3.48f; float zmin = 4.20; float xmax = -2.96; float zmax = -2.3;
		if (Character->vec4ftraslate.x >= xmin && Character->vec4ftraslate.x <= xmax && Character->vec4ftraslate.z <= zmin && Character->vec4ftraslate.z >= zmax)
		{//is in box

			//is right
			if (Character->vec4ftraslate.x - move_pase <= xmin)
				Character->vec4ftraslate.x -= move_pase;
			//is left
			if (Character->vec4ftraslate.x + move_pase >= xmax)
				Character->vec4ftraslate.x += move_pase;
			//is down
			if (Character->vec4ftraslate.z + move_pase>= zmin)
				Character->vec4ftraslate.z += move_pase;
			//is up
			if (Character->vec4ftraslate.z - move_pase <= zmax)
				Character->vec4ftraslate.z -= move_pase;
			return true;
		}
		else
			return false;
	}

	bool Check_walls2()
	{
		float xmin = -2.40f; float zmin = 2.4; float xmax = -1.9f; float zmax = -4.20;
		if (Character->vec4ftraslate.x >= xmin && Character->vec4ftraslate.x <= xmax && Character->vec4ftraslate.z <= zmin && Character->vec4ftraslate.z >= zmax)
		{//is in box
			//is right
			if (Character->vec4ftraslate.x - move_pase <= xmin)
				Character->vec4ftraslate.x -= move_pase;
			//is left
			if (Character->vec4ftraslate.x + move_pase >= xmax)
				Character->vec4ftraslate.x += move_pase;
			//is down
			if (Character->vec4ftraslate.z + move_pase >= zmin)
				Character->vec4ftraslate.z += move_pase;
			//is up
			if (Character->vec4ftraslate.z - move_pase <= zmax)
				Character->vec4ftraslate.z -= move_pase;
			return true;
		}
		else
			return false;
	}

	bool Check_walls3()
	{
		float xmin = -1.34; float zmin = 4.20; float xmax = -0.83f; float zmax = 2.02;
		if (Character->vec4ftraslate.x >= xmin && Character->vec4ftraslate.x <= xmax && Character->vec4ftraslate.z <= zmin && Character->vec4ftraslate.z >= zmax)
		{//is in box
			//is right
			if (Character->vec4ftraslate.x - move_pase <= xmin)
				Character->vec4ftraslate.x -= move_pase;
			//is left
			if (Character->vec4ftraslate.x + move_pase >= xmax)
				Character->vec4ftraslate.x += move_pase;
			//is down
			if (Character->vec4ftraslate.z + move_pase >= zmin)
				Character->vec4ftraslate.z += move_pase;
			//is up
			if (Character->vec4ftraslate.z - move_pase <= zmax)
				Character->vec4ftraslate.z -= move_pase;
			return true;
		}
		else
			return false;
	}

	bool Check_walls4()
	{
		float xmin = -1.36; float zmin = 0.24; float xmax = -0.89; float zmax = -3.22;
		if (Character->vec4ftraslate.x >= xmin && Character->vec4ftraslate.x <= xmax && Character->vec4ftraslate.z <= zmin && Character->vec4ftraslate.z >= zmax)
		{//is in box
			//is right
			if (Character->vec4ftraslate.x - move_pase <= xmin)
				Character->vec4ftraslate.x -= move_pase;
			//is left
			if (Character->vec4ftraslate.x + move_pase >= xmax)
				Character->vec4ftraslate.x += move_pase;
			//is down
			if (Character->vec4ftraslate.z + move_pase >= zmin)
				Character->vec4ftraslate.z += move_pase;
			//is up
			if (Character->vec4ftraslate.z - move_pase <= zmax)
				Character->vec4ftraslate.z -= move_pase;
			return true;
		}
		else
			return false;
	}

	bool Check_walls5()
	{
		float xmin = -1.18; float zmin = -2.86; float xmax = 2.24; float zmax = -3.38;
		if (Character->vec4ftraslate.x >= xmin && Character->vec4ftraslate.x <= xmax && Character->vec4ftraslate.z <= zmin && Character->vec4ftraslate.z >= zmax)
		{//is in box
			//is right
			if (Character->vec4ftraslate.x - move_pase <= xmin)
				Character->vec4ftraslate.x -= move_pase;
			//is left
			if (Character->vec4ftraslate.x + move_pase >= xmax)
				Character->vec4ftraslate.x += move_pase;
			//is down
			if (Character->vec4ftraslate.z + move_pase >= zmin)
				Character->vec4ftraslate.z += move_pase;
			//is up
			if (Character->vec4ftraslate.z - move_pase <= zmax)
				Character->vec4ftraslate.z -= move_pase;
			return true;
		}
		else
			return false;
	}

	bool Check_walls6()
	{
		float xmin = -0.20; float zmin = 3.46; float xmax = 0.259f; float zmax = -2.26;
		if (Character->vec4ftraslate.x >= xmin && Character->vec4ftraslate.x <= xmax && Character->vec4ftraslate.z <= zmin && Character->vec4ftraslate.z >= zmax)
		{//is in box
			//is right
			if (Character->vec4ftraslate.x - move_pase <= xmin)
				Character->vec4ftraslate.x -= move_pase;
			//is left
			if (Character->vec4ftraslate.x + move_pase >= xmax)
				Character->vec4ftraslate.x += move_pase;
			//is down
			if (Character->vec4ftraslate.z + move_pase >= zmin)
				Character->vec4ftraslate.z += move_pase;
			//is up
			if (Character->vec4ftraslate.z - move_pase <= zmax)
				Character->vec4ftraslate.z -= move_pase;
			return true;
		}
		else
			return false;
	}

	bool Check_walls7()
	{
		float xmin = 0.819; float zmin = 3.38; float xmax = 1.36f; float zmax = -2.26;
		if (Character->vec4ftraslate.x >= xmin && Character->vec4ftraslate.x <= xmax && Character->vec4ftraslate.z <= zmin && Character->vec4ftraslate.z >= zmax)
		{//is in box
			//is right
			if (Character->vec4ftraslate.x - move_pase <= xmin)
				Character->vec4ftraslate.x -= move_pase;
			//is left
			if (Character->vec4ftraslate.x + move_pase >= xmax)
				Character->vec4ftraslate.x += move_pase;
			//is down
			if (Character->vec4ftraslate.z + move_pase >= zmin)
				Character->vec4ftraslate.z += move_pase;
			//is up
			if (Character->vec4ftraslate.z - move_pase <= zmax)
				Character->vec4ftraslate.z -= move_pase;
			return true;
		}
		else
			return false;
	}

	bool Check_walls8()
	{
		float xmin = 0.859; float zmin = 3.56; float xmax = 2.2f; float zmax = 3.04;
		if (Character->vec4ftraslate.x >= xmin && Character->vec4ftraslate.x <= xmax && Character->vec4ftraslate.z <= zmin && Character->vec4ftraslate.z >= zmax)
		{//is in box
			//is right
			if (Character->vec4ftraslate.x - move_pase <= xmin)
				Character->vec4ftraslate.x -= move_pase;
			//is left
			if (Character->vec4ftraslate.x + move_pase >= xmax)
				Character->vec4ftraslate.x += move_pase;
			//is down
			if (Character->vec4ftraslate.z + move_pase >= zmin)
				Character->vec4ftraslate.z += move_pase;
			//is up
			if (Character->vec4ftraslate.z - move_pase <= zmax)
				Character->vec4ftraslate.z -= move_pase;
			return true;
		}
		else
			return false;
	}

	bool Check_walls9()
	{
		float xmin = 1.88; float zmin = 3.46; float xmax = 2.38f; float zmax = -2.18;
		if (Character->vec4ftraslate.x >= xmin && Character->vec4ftraslate.x <= xmax && Character->vec4ftraslate.z <= zmin && Character->vec4ftraslate.z >= zmax)
		{//is in box
			//is right
			if (Character->vec4ftraslate.x - move_pase <= xmin)
				Character->vec4ftraslate.x -= move_pase;
			//is left
			if (Character->vec4ftraslate.x + move_pase >= xmax)
				Character->vec4ftraslate.x += move_pase;
			//is down
			if (Character->vec4ftraslate.z + move_pase >= zmin)
				Character->vec4ftraslate.z += move_pase;
			//is up
			if (Character->vec4ftraslate.z - move_pase <= zmax)
				Character->vec4ftraslate.z -= move_pase;
			return true;
		}
		else
			return false;
	}

	bool Check_walls10()
	{
		float xmin = 2; float zmin = -1.74; float xmax = 3.3f; float zmax = -2.3;
		if (Character->vec4ftraslate.x >= xmin && Character->vec4ftraslate.x <= xmax && Character->vec4ftraslate.z <= zmin && Character->vec4ftraslate.z >= zmax)
		{//is in box
			//is right
			if (Character->vec4ftraslate.x - move_pase <= xmin)
				Character->vec4ftraslate.x -= move_pase;
			//is left
			if (Character->vec4ftraslate.x + move_pase >= xmax)
				Character->vec4ftraslate.x += move_pase;
			//is down
			if (Character->vec4ftraslate.z + move_pase >= zmin)
				Character->vec4ftraslate.z += move_pase;
			//is up
			if (Character->vec4ftraslate.z - move_pase <= zmax)
				Character->vec4ftraslate.z -= move_pase;
			return true;
		}
		else
			return false;
	}

	bool Check_walls11()
	{
		float xmin = 2.98; float zmin = -1.86; float xmax = 3.44f; float zmax = -4.20;
		if (Character->vec4ftraslate.x >= xmin && Character->vec4ftraslate.x <= xmax && Character->vec4ftraslate.z <= zmin && Character->vec4ftraslate.z >= zmax)
		{//is in box
			//is right
			if (Character->vec4ftraslate.x - move_pase <= xmin)
				Character->vec4ftraslate.x -= move_pase;
			//is left
			if (Character->vec4ftraslate.x + move_pase >= xmax)
				Character->vec4ftraslate.x += move_pase;
			//is down
			if (Character->vec4ftraslate.z + move_pase >= zmin)
				Character->vec4ftraslate.z += move_pase;
			//is up
			if (Character->vec4ftraslate.z - move_pase <= zmax)
				Character->vec4ftraslate.z -= move_pase;
			return true;
		}
		else
			return false;
	}

	bool Check_walls12()
	{
		float xmin = 2.98; float zmin = 4.20; float xmax = 3.48f; float zmax = -1.14;
		if (Character->vec4ftraslate.x >= xmin && Character->vec4ftraslate.x <= xmax && Character->vec4ftraslate.z <= zmin && Character->vec4ftraslate.z >= zmax)
		{//is in box
			//is right
			if (Character->vec4ftraslate.x - move_pase <= xmin)
				Character->vec4ftraslate.x -= move_pase;
			//is left
			if (Character->vec4ftraslate.x + move_pase >= xmax)
				Character->vec4ftraslate.x += move_pase;
			//is down
			if (Character->vec4ftraslate.z + move_pase >= zmin)
				Character->vec4ftraslate.z += move_pase;
			//is up
			if (Character->vec4ftraslate.z - move_pase <= zmax)
				Character->vec4ftraslate.z -= move_pase;
			return true;
		}
		else
			return false;
	}

	bool check_coin1()
	{
		float xmin = -4.08; float zmin = 3.4; float xmax = -3.58f; float zmax = 3.06;
		if (Character->vec4ftraslate.x >= xmin && Character->vec4ftraslate.x <= xmax && Character->vec4ftraslate.z <= zmin && Character->vec4ftraslate.z >= zmax)
		{
			std::cout << "yes" << std::endl;
			return true;
		}
		else
		return false;
	}

	bool is_in_wall() 
	{
		return Check_walls1() ||
			Check_walls2() ||
			Check_walls3() ||
			Check_walls4() ||
			Check_walls5() ||
			Check_walls6() ||
			Check_walls7() ||
			Check_walls8() ||
			Check_walls9() ||
			Check_walls10() ||
			Check_walls11() ||
			Check_walls12();
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
	void handle_right_colliton(Mesh* object)
	{
		float penetration = smooth_collition * glm::abs((Character->vec4ftraslate.x + Character->size.x) - (object->vec4ftraslate.x + object->size.x));
		Character->vec4ftraslate.x -= penetration;
	}
	void handle_left_colliton(Mesh* object)
	{
		float penetration = smooth_collition * glm::abs((Character->vec4ftraslate.x + Character->size.x) - (object->vec4ftraslate.x + object->size.x));
		Character->vec4ftraslate.x += penetration;
	}
	void handle_up_colliton(Mesh* object)
	{
		float penetration = smooth_collition * glm::abs((Character->vec4ftraslate.z + Character->size.z) - (object->vec4ftraslate.z + object->size.z));
		Character->vec4ftraslate.z += penetration;
	}
	void handle_down_colliton(Mesh* object)
	{
		float penetration = smooth_collition * glm::abs((Character->vec4ftraslate.z + Character->size.z) - (object->vec4ftraslate.z + object->size.z));
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
		Direction dir = VectorDirection(set_target(one, two));
		if (dir == RIGHT || dir == LEFT)
		{
			//this is backwards for some reason, but whatever...
			if (dir == LEFT)
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
		correct_character_movement_bounds();
	}

	//TODO Handle the rest of the collisions with other objects
	void handle_rest_collisions(std::vector <Mesh*> models)
	{
		if (models.size() > 0) {
			for (int i = 0; i < models.size(); i++)
			{
				if (Check_Collision(Character, models[i]))
				{
					Resolve_collition(Character, models[i]);
				}
			}
		}
		correct_character_movement_bounds();
	}

	void correct_character_movement_bounds()
	{
		float move_pase = 0.020f;
		if (Character->vec4ftraslate.x + move_pase > 4.180)
				Character->vec4ftraslate.x = 4.180;
		if (Character->vec4ftraslate.x - move_pase < -4.180)
			Character->vec4ftraslate.x = -4.180;
		if (Character->vec4ftraslate.z + move_pase > 4.160)
			Character->vec4ftraslate.z = 4.160;
		if (Character->vec4ftraslate.z - move_pase < -4.160)
			Character->vec4ftraslate.z = -4.160;

	}

	//TODO draw the rest of the objects of the map
	void draw_objects_map()
	{
		//std::cout <<"X:" << Character->vec4ftraslate.x << "\n";
		//std::cout <<"Z:" << Character->vec4ftraslate.z << "\n";
		hitting_wall = is_in_wall();
		check_coin1();
		if (walls.size() > 0) {
			for (int i = 0; i < walls.size(); i++)
			{
				
				if (bwShader) {
					if (i < coins.size()) {
						bwShader->use();
						bwShader->setVec3("cameraPos", cameraPos);
						coins[i]->setmodelMatrix();
						coins[i]->BindTexture();
						coins[i]->Bind();
						coins[i]->setView(view);
						coins[i]->setproj(proj);
						coins[i]->Draw();
					}
					bwShader->use();
					bwShader->setVec3("cameraPos", cameraPos);
					walls[i]->setmodelMatrix();
					walls[i]->BindTexture();
					walls[i]->Bind();
					walls[i]->setView(view);
					walls[i]->setproj(proj);
					walls[i]->Draw();

				}
			}
		}
	 }

	void load_coin1(Mesh* mesh) 
	{
		mesh->loadCreateTexture("./../texture/container.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 2.410;
		mesh->vec4fscale.y = 2.970f;
		mesh->vec4fscale.z = 2.800f;
		mesh->vec4ftraslate.x = -3.240f;
		mesh->vec4ftraslate.y = 0.000f;
		mesh->vec4ftraslate.z = 1.180f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		walls.push_back(mesh);
	}
	//TODO load the rest of the objects of the map
	void load_wall1(Mesh *mesh)
	{
		mesh->loadCreateTexture("./../texture/container.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 2.410;
		mesh->vec4fscale.y = 2.970f;
		mesh->vec4fscale.z = 2.800f;
		mesh->vec4ftraslate.x = -3.240f;
		mesh->vec4ftraslate.y = 0.000f;
		mesh->vec4ftraslate.z = 1.180f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		walls.push_back(mesh);
	}

	void load_wall2(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/container.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 2.410;
		mesh->vec4fscale.y = 2.970f;
		mesh->vec4fscale.z = 2.800f;
		mesh->vec4ftraslate.x = -2.200f;
		mesh->vec4ftraslate.y = 0.000f;
		mesh->vec4ftraslate.z = -1.020f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		walls.push_back(mesh);
	}

	void load_wall3(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/container.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 2.410;
		mesh->vec4fscale.y = 2.970f;
		mesh->vec4fscale.z = 0.900f;
		mesh->vec4ftraslate.x = -1.100f;
		mesh->vec4ftraslate.y = 0.000f;
		mesh->vec4ftraslate.z = 3.260f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		walls.push_back(mesh);
	}



	void load_wall4(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/container.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 2.410;
		mesh->vec4fscale.y = 2.970f;
		mesh->vec4fscale.z = 2.280f;
		mesh->vec4ftraslate.x = 0.000f;
		mesh->vec4ftraslate.y = 0.000f;
		mesh->vec4ftraslate.z = 0.600f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		walls.push_back(mesh);
	}


	void load_wall5(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/container.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 2.410;
		mesh->vec4fscale.y = 2.970f;
		mesh->vec4fscale.z = 1.340f;
		mesh->vec4ftraslate.x = -1.100f;
		mesh->vec4ftraslate.y = 0.000f;
		mesh->vec4ftraslate.z = -1.500f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		walls.push_back(mesh);
	}

	void load_wall6(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/container.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 2.410;
		mesh->vec4fscale.y = 2.970f;
		mesh->vec4fscale.z = 2.280f;
		mesh->vec4ftraslate.x = 1.080f;
		mesh->vec4ftraslate.y = 0.000f;
		mesh->vec4ftraslate.z = 0.580f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		walls.push_back(mesh);
	}

	void load_wall7(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/container.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 2.410;
		mesh->vec4fscale.y = 2.970f;
		mesh->vec4fscale.z = 2.280f;
		mesh->vec4ftraslate.x = 2.120f;
		mesh->vec4ftraslate.y = 0.000f;
		mesh->vec4ftraslate.z = 0.630f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		walls.push_back(mesh);
	}

	void load_wall8(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/container.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 2.410;
		mesh->vec4fscale.y = 2.970f;
		mesh->vec4fscale.z = 2.280f;
		mesh->vec4ftraslate.x = 3.220f;
		mesh->vec4ftraslate.y = 0.000f;
		mesh->vec4ftraslate.z = 1.680f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		walls.push_back(mesh);
	}

	void load_wall9(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/container.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 2.410;
		mesh->vec4fscale.y = 2.970f;
		mesh->vec4fscale.z = 0.950f;
		mesh->vec4ftraslate.x = 3.220f;
		mesh->vec4ftraslate.y = 0.000f;
		mesh->vec4ftraslate.z = -3.120f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		walls.push_back(mesh);
	}

	void load_wall10(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/container.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 1.340;
		mesh->vec4fscale.y = 2.970f;
		mesh->vec4fscale.z = 2.800f;
		mesh->vec4ftraslate.x = 0.520f;
		mesh->vec4ftraslate.y = 0.000f;
		mesh->vec4ftraslate.z = -3.080f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = 0.000;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 1.000;
		walls.push_back(mesh);
	}

	void load_wall11(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/container.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 0.430;
		mesh->vec4fscale.y = 2.970f;
		mesh->vec4fscale.z = 2.800f;
		mesh->vec4ftraslate.x = 2.660f;
		mesh->vec4ftraslate.y = 0.000f;
		mesh->vec4ftraslate.z = -2.000f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = 0.000;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 1.000;
		walls.push_back(mesh);
	}

	void load_wall12(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/container.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 0.440;
		mesh->vec4fscale.y = 2.970f;
		mesh->vec4fscale.z = 2.800f;
		mesh->vec4ftraslate.x = 1.520f;
		mesh->vec4ftraslate.y = 0.000f;
		mesh->vec4ftraslate.z = 3.300f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = 0.000;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 1.000;
		walls.push_back(mesh);
	}


	void load_coin1(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/gold.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 0.250;
		mesh->vec4fscale.y = 0.250f;
		mesh->vec4fscale.z = 0.250f;
		mesh->vec4ftraslate.x = -2.720f;
		mesh->vec4ftraslate.y = 0.140f;
		mesh->vec4ftraslate.z = 0.000f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		coins.push_back(mesh);
	}

	void load_coin2(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/gold.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 0.250;
		mesh->vec4fscale.y = 0.250f;
		mesh->vec4fscale.z = 0.250f;
		mesh->vec4ftraslate.x = -1.060f;
		mesh->vec4ftraslate.y = 0.140f;
		mesh->vec4ftraslate.z = 1.040f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		coins.push_back(mesh);
	}

	void load_coin3(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/gold.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 0.250;
		mesh->vec4fscale.y = 0.250f;
		mesh->vec4fscale.z = 0.250f;
		mesh->vec4ftraslate.x = 1.7200f;
		mesh->vec4ftraslate.y = 0.140f;
		mesh->vec4ftraslate.z = 2.700f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		coins.push_back(mesh);
	}

	void load_coin4(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/gold.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 0.250;
		mesh->vec4fscale.y = 0.250f;
		mesh->vec4fscale.z = 0.250f;
		mesh->vec4ftraslate.x = 2.720f;
		mesh->vec4ftraslate.y = 0.140f;
		mesh->vec4ftraslate.z = -2.800f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		coins.push_back(mesh);
	}

	void load_coin5(Mesh* mesh)
	{
		mesh->loadCreateTexture("./../texture/gold.jpg");
		mesh->only_color = false;
		mesh->only_texture = true;
		mesh->texture_drawing = true;
		mesh->zbuffer = true;
		mesh->mallado = true;
		mesh->relleno = true;
		mesh->back_face_culling = true;
		mesh->vec4fscale.x = 0.250;
		mesh->vec4fscale.y = 0.250f;
		mesh->vec4fscale.z = 0.250f;
		mesh->vec4ftraslate.x = 3.780f;
		mesh->vec4ftraslate.y = 0.140f;
		mesh->vec4ftraslate.z = 2.800f;
		mesh->Qrotacion[0] = 0.000;
		mesh->Qrotacion[1] = -0.71;
		mesh->Qrotacion[2] = 0.000;
		mesh->Qrotacion[3] = 0.70;
		coins.push_back(mesh);
	}




};

