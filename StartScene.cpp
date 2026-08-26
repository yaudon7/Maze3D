#include "StartScene.h"
#include "Engine/Text.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"


StartScene::StartScene(GameObject* parent)
	:GameObject(parent,"StartScene"),pText_(nullptr)
{
}

void StartScene::Initialize()
{
	pText_ = new Text;
	pText_->Initialize();
}

void StartScene::Update()
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	//Enter
	if (Input::IsKeyDown(DIK_RETURN))
	{
		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

void StartScene::Draw()
{
	pText_->Draw(500, 200, "START TO ENTER");
}

void StartScene::Release()
{
}
