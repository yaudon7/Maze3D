#pragma once
#include "Engine/GameObject.h"
#include <vector>

class Ground :
	public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Ground(GameObject* parent);
	void Initialize() override;
	std::vector<std::vector<int>> GetMapData() { return mapData_; }
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	int hModel_;
	int mapWidth_;
	int mapHeight_;
	int foodWidth_;
	int foodHeight_;
	int powerFoodWidth_;
	int powerFoodHeight_;
	std::vector<std::vector<int>> mapData_;
	std::vector<std::vector<int>> foodData_;
};

