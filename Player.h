#pragma once
#include "Engine/GameObject.h"

class Player :
    public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	int hModel_;//Playerのモデルのハンドル
	float speed_;//Playerのスピード
};

