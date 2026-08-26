#pragma once
#include "Engine/GameObject.h"

class Ground;//前方宣言

//テストシーンを管理するクラス
class Slime : public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Slime(GameObject* parent);

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	void SetGround(Ground* ground) { ground_ = ground; }

private:
	int hModel_;
	Ground* ground_;
};