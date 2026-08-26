#pragma once
#include "Engine/GameObject.h"


class Ground;//前方宣言

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
	void SetGround(Ground* ground) { ground_ = ground; }
	void OnCollision(GameObject* pTarget)override;
private:
	int hWalkModel_;//Playerのモデルのハンドル
	int hIdleModel_;
	float powerUPTime_;//パワーアップ時間
	Ground* ground_;//Groundのポインタ
};

