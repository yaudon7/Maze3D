#include "Ground.h"
#include "Player.h"
#include "Engine/Model.h"

Ground::Ground(GameObject* parent)
	:GameObject(parent), hModel_(-1) {
}

void Ground::Initialize()
{
	hModel_ = Model::Load("Ground.fbx");
	transform_.rotate_.y = -90;
}

void Ground::Update()
{
	
}

void Ground::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Ground::Release()
{
}
