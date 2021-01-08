#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	//App->camera->LookAt(vec3(0, 0, 0));

	FirstPhaseObjects();

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	for (int i = 0; i < checkpointCounter; i++)
	{
		Color col = Red;
		if (App->player->lastCheckPoint == checkPoints[i])
		{
			col = Black;
		}

		checkPoints[i]->lights[0]->color = col;
		checkPoints[i]->lights[1]->color = col;

		checkPoints[i]->lights[0]->Render();
		checkPoints[i]->lights[1]->Render();
	}

	p2List_item<Primitive*>* item = map_objects.getFirst();
	while (item)
	{
		item->data->Render();
		item = item->next;
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

PhysBody3D* ModuleSceneIntro::CreateRectangle(vec3 position, vec4 rotation, vec3 size, Color s_color, float mass)
{

	Cube* object = new Cube();

	object->SetPos(position.x, position.y, position.z);
	object->size = size;
	object->color = s_color;
	object->SetRotation(rotation.x, { rotation.y, rotation.z, rotation.w });

	map_objects.add(object);
	return App->physics->AddBody(*object, mass);
}

void ModuleSceneIntro::CreateSensor(vec3 position, vec4 rotation, vec3 size, Color s_color, SensorType s_type, vec3 mod, vec4 target_rotation)
{
	Cube* object = new Cube();

	object->SetPos(position.x, position.y, position.z);
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
	}
}

void ModuleSceneIntro::FirstPhaseObjects()
{

	CreateRectangle({ 7,1,0 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 3,1,0 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -1,1,0 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -5,1,0 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);

	CreateRectangle({ 7,1,3 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 7,1,9 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 7,1,15 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 6,1,21 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 4,1,27 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 3,1,33 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 3,5,39 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 3,5,45 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 3,6,51 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 3,6,57 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 3,6,63 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 3,6,69 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 3,6,75 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 3,6,81 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 3,6,87 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 3,1,93 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 3,1,99 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 3,1,105 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 4,1,108 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 6,1,114 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 8,1,120 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 10,1,126 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 10,1,132 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 9,1,137 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 7,1,141 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ 5,1,145 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 4,1,147 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 1,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -1,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -7,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -11,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -15,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -18,1,147 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -20,1,143 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -22,1,139 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -24,1,135 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -25,1,129 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -24,1,123 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -22,1,117 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -20,1,111 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -18,1,105 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -16,1,99 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -18,1,95 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -22,1,95 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -25,1,97 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -25,1,102 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -23,1,108 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -26,1,128 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -28,1,132 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -30,1,136 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -32,1,140 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -34,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -38,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -42,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -47,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -53,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -59,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -65,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -71,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -7,1,0 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -7,1,6 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -7,1,12 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -7,1,18 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -5,1,24 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,1,30 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,1,36 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,5,39 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,5,45 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,5,51 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,5,57 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,5,63 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,5,69 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,6,51 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,6,54 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,6,57 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,6,60 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,6,63 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,6,66 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,6,69 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,6,72 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,6,75 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,6,78 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,6,81 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,6,84 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,6,87 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,6,90 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,1,93 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,1,96 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,1,99 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,1,102 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,1,105 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -4,1,108 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -6,1,114 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -5,1,120 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -3,1,126 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,1,132 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -6,1,136 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -10,1,136 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -12,1,132 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -11,1,126 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -9,1,120 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -4,1,93 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -6,1,89 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -8,1,85 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -11,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -15,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -19,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -23,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -27,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -31,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -34,1,85 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -36,1,89 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -38,1,93 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -39,1,99 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -38,1,103 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -36,1,107 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -35,1,112 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -35,1,118 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -37,1,122 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -39,1,126 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -42,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -47,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -53,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -59,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -65,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);
	CreateRectangle({ -71,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -77,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, Black);

	CreateRectangle({ 0, 1, 30 }, { 70, 1, 0, 0 }, { 5, 15, 0.2f }, Red);
	CreateRectangle({ 0, 1, 49 }, { 0, 1, 0, 0 }, { 5, 5, 8.f }, Black);
	CreateRectangle({ 0, 4, 60 }, { 80, 1, 0, 0 }, { 5, 15, 0.2f }, Black);
	CreateRectangle({ 0, 2, 82 }, { -85, 1, 0, 0 }, { 5, 42, 0.2f }, Black);

	CreateRectangle({ -90,6,137 }, { -30,0,0,1 }, { 30,0.2f,14 }, Red);

}