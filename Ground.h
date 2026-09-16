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
	int hModel_;//モデルのハンドル
	int mapWidth_;//マップの幅
	int mapHeight_;//マップの高さ
	int foodWidth_;//フードの幅	
	int foodHeight_;//フードの高さ
	int powerFoodWidth_;//パワーフードの幅
	int powerFoodHeight_;//パワーフードの高さ
	std::vector<std::vector<int>> mapData_;//マップデータ
	std::vector<std::vector<int>> foodData_;//フードデータ
};

