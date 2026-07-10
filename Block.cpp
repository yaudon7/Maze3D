#include "Block.h"
#include "Engine/Model.h"

Block::Block(GameObject* parent)
	:GameObject(parent), hModel_(-1) {
}

void Block::Initialize()
{
	hModel_ = Model::Load("Block.fbx");
	transform_.scale_
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
