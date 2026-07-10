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
	std::vector<std::vector<int>> mapData_;
};

