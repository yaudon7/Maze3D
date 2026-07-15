#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"
#include "Player.h"

namespace
{
	using std::vector;
	int model_t = -1;
	int foodModel_ = -1;
}

Ground::Ground(GameObject* parent)
	:GameObject(parent), hModel_(-1),mapWidth_(-1),mapHeight_(-1)
{
	CsvReader csvData;
	csvData.Load("map.csv");
	mapWidth_ = csvData.GetWidth();
	mapHeight_ = csvData.GetHeight();
	mapData_ = vector<vector<int>>(mapHeight_, vector<int>(mapWidth_, 0));
	for(int x = 0; x < mapWidth_;x++)
		for (int y = 0; y < mapHeight_;y++)
		{
			mapData_[y][x] = csvData.GetValue(x, y);//GetString()は文字
		}

	CsvReader csvFoodData;
	csvFoodData.Load("Food.csv");
	foodWidth_ = csvFoodData.GetWidth();
	foodHeight_ = csvFoodData.GetHeight();
	foodData_ = vector<vector<int>>(foodHeight_, vector<int>(foodWidth_, 0));
	for (int x = 0; x < foodWidth_;x++)
		for (int y = 0; y < foodHeight_;y++)
		{
			foodData_[y][x] = csvFoodData.GetValue(x, y);//GetString()は文字
		}
}

void Ground::Initialize()
{
	hModel_ = Model::Load("jimen3.fbx");
	model_t = Model::Load("Block_P.fbx");
	foodModel_ = Model::Load("Food.fbx");
	//pPlayer = Instantiate<Player>(this);

	/*for (int j = 0; j < mapHeight_; j++)
	{
		for (int i = 0; i < mapWidth_; i++)
		{
			if (mapData_[j][i] == 2)
			{
				if (pPlayer) {
					pPlayer->SetPosition({ -9.0f + i * 2.0f,0.0f,9.0f - j * 2.0f });
				}
			}
		}
	}*/
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
	for (int j = 0; j < mapHeight_; j++)
	{
		for (int i = 0; i < mapWidth_; i++)
		{
			if (mapData_[j][i] == 1)
			{
				Transform tr;
				tr.position_ = { -9.0f + i * 2.0f,0.0f,9.0f - j * 2.0f };
				Model::SetTransform(model_t, tr);
				Model::Draw(model_t);
			}
			if (foodData_[j][i] == 0)
			{
				Transform tr;
				tr.position_ = { -9.0f + i * 2.0f,0.0f,9.0f - j * 2.0f };
				Model::SetTransform(foodModel_, tr);
				Model::Draw(foodModel_);
			}
		}
	}
}

void Ground::Release()
{
}
