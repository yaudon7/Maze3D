#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"
#include "Player.h"
#include "Food.h"
#include "PowerFood.h"
#include "Slime.h"

namespace
{
	using std::vector;
	int model_t = -1;
	int foodModel_ = -1;
	int powerFoodModel_ = -1;
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
			if (mapData_[y][x] == 2) {
				Player* pPlayer = Instantiate<Player>(this);
				pPlayer->SetGround(this);
				pPlayer->SetPosition(-9.0f + x * 2.0f, 0.0f, 9.0f - y * 2.0f);
			}
			else if (mapData_[y][x] == 3)
			{
				Slime* pSlime = Instantiate<Slime>(this);
				pSlime->SetGround(this);
				pSlime->SetPosition(-9.0f + x * 2.0f, 0.0f, 9.0f - y * 2.0f);
			}
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
			if (foodData_[y][x] != 1) {
				Food* food = Instantiate<Food>(this);
				PowerFood* pFood = Instantiate<PowerFood>(this);
				food->SetPosition(-9.0f + x * 2.0f, 0.0f, 9.0f - y * 2.0f);
				pFood->SetPosition(-9.0f + x * 2.0f, 0.0f, 9.0f - y * 2.0f);
				if (foodData_[y][x] == 0)
				{
					food->SetFood();
				}
				else if (foodData_[y][x] == 3)
				{
					pFood->SetPowerFood();
				}
			}
		}
}

void Ground::Initialize()
{
	hModel_ = Model::Load("jimen3.fbx");
	model_t = Model::Load("Block_P.fbx");
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
		}
	}
}

void Ground::Release()
{
}
