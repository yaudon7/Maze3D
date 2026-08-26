#include "Slime.h"
#include "Engine//Model.h"

Slime::Slime(GameObject* parent)
	:GameObject(parent, "Slime"), hModel_(-1)
{
}

void Slime::Initialize()
{
	hModel_ = Model::Load("Slime.fbx");

	SphereCollider* collider = new SphereCollider({ 0,0,0 }, 0.5f);
	AddCollider(collider);
}

void Slime::Update()
{
}

void Slime::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Slime::Release()
{
}


