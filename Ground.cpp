#include "Ground.h"
#include "Player.h"
#include "Engine/Model.h"
#include "Block.h"

namespace
{
	using std::vector;
	int model_t = -1;
	vector<vector<int>> mapData =
	{
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1}
	};
}
Ground::Ground(GameObject* parent)
	:GameObject(parent), hModel_(-1) {
}

void Ground::Initialize()
{
	model_t = Model::Load("jimen.fbx");
	transform_.rotate_.y = -90;
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(model_t, transform_);
	Model::Draw(model_t);
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (mapData[j][i] == 1)
			{
				//Instantiate<Block>(this);
			}
		}
	}
}

void Ground::Release()
{
}
