#include "Globals.h"
#include "Application.h"
#include "ModuleMap.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleMap::ModuleMap(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	checkpointCounter = 0;
}

ModuleMap::~ModuleMap()
{}

// Load assets
bool ModuleMap::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	//Camera init
	

	//Audio Load
	
	//Create map
	/*FirstPhaseObjects();
	SecondPhaseObjects();
	ThirdPhaseObjects();
	LastPhaseObjects();
	CreateSensors();
	CreateConstrains();*/

	return ret;
}

// Load assets
bool ModuleMap::CleanUp()
{
	LOG("Unloading Intro scene");
	map_objects.clear();
	map_sensors.clear();
	obs_bodys.Clear();
	obs_primitives.Clear();
	return true;
}

// Update
update_status ModuleMap::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	

	return UPDATE_CONTINUE;
}

void ModuleMap::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

PhysBody3D* ModuleMap::CreateRectangle(vec3 position, vec4 rotation, vec3 size, Color s_color, float mass)
{

	Cube* object = new Cube();

	object->SetPos(position.x, position.y, position.z);
	object->size = size;
	object->color = s_color;
	object->SetRotation(rotation.x, { rotation.y, rotation.z, rotation.w });

	map_objects.add(object);
	return App->physics->AddBody(*object, mass);
}

PhysBody3D* ModuleMap::CreateCylinder(vec3 position, vec4 rotation, float radius, float height, Color s_color, float mass)
{
	Cylinder* object = new Cylinder();

	object->SetPos(position.x, position.y, position.z);
	object->color = s_color;
	object->SetRotation(rotation.x, { rotation.y, rotation.z, rotation.w });

	object->height = height;
	object->radius = radius;

	map_objects.add(object);
	return App->physics->AddBody(*object, mass);
}

void ModuleMap::CreateSensor(vec3 position, vec4 rotation, vec3 size, Color s_color, SensorType s_type, vec3 mod, vec4 target_rotation)
{
	/*Cube* object = new Cube();

	object->SetPos(position.x, position.y,.z);
	object->size = size;
	object->color = s_color;
	object->SetRotation(rotation.x, { rotation.y, rotation.z, rotation.w });

	if (s_type == SensorType::CHECKPOINT) 
	{
		checkPoints[checkpointCounter] = map_sensors.add(App->physics->AddSensor(*object, mod, s_type, target_rotation))->data;
		checkpointCounter++;
	}
	else
	{
		map_sensors.add(App->physics->AddSensor(*object, mod, s_type, target_rotation));
	}*/
}

void ModuleMap::FirstPhaseObjects()
{
	//------------------------ROAD LIMITS---------------------------------------
	//Left side ------------------------------------------------
	
	
}

void ModuleMap::SecondPhaseObjects()
{
	
}

void ModuleMap::ThirdPhaseObjects()
{
	
}

void ModuleMap::LastPhaseObjects()
{
	
}

void ModuleMap::CreateSensors()
{
	//Here we add all sensors:
	CreateSensor({ -50,1,137 }, { 90,0,0,1 }, { 10,0.1f,14 }, Green, SensorType::BOOSTER, { 0,10,0 });

	
	//Winning condition
	CreateSensor({ 30, 28, 148 }, { -45,1,0,0 }, { 8, 1, 8 }, White, SensorType::FINISH, { 0,0,0 });
}

void ModuleMap::CreateConstrains()
{
	
}
