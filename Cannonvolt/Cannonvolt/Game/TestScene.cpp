#include "TestScene.h"



TestScene::TestScene() : Scene() {

}

TestScene::~TestScene() {

}

bool TestScene::OnCreate()
{
	Debug::Info("Creating Game Scene", "GameScene.cpp", __LINE__);

	CoreEngine::GetInstance()->SetCamera(new Camera);
	CoreEngine::GetInstance()->GetCamera()->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));

	//CoreEngine::GetInstance()->GetCamera()->AddLightSource(new LightSource(glm::vec3(0.0f, 0.0f, 2.0f), 0.1f, 0.5f, glm::vec3(1.0f, 1.0f, 1.0f)));

	character.OnCreate();
	character.SetPosition(glm::vec2(200.0f, 200.0f));
	character.SetScale(glm::vec2(0.10f, 0.10f));

	grass.OnCreate();
	grass.SetPosition(glm::vec2(490.0f, 210.0f));
	grass.SetScale(glm::vec2(0.1f));
	
  controller.Init(&character);
  
	if (character.GetBoundingBox().Intersects(&grass.GetBoundingBox())) {
  }


	return true;
}

void TestScene::Update(const float deltaTime_)
{
	controller.Update(deltaTime_);
}

void TestScene::Draw()
{
	SceneGraph::GetInstance()->Draw(CoreEngine::GetInstance()->GetCamera());
}
