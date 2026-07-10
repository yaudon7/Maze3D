#include "Block.h"
#include "Engine/Model.h"

Block::Block(GameObject* parent)
	:GameObject(parent), hModel_(-1) {
}

void Block::Initialize()
{
	hModel_ = Model::Load("Block1.fbx");
	transform_.position_.x -= 5.0f;
	transform_.rotate_.z = 90;
}

void Block::Update()
{
}

void Block::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Block::Release()
{
}
