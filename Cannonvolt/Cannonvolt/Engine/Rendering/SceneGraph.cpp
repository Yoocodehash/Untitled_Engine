#include "SceneGraph.h"

std::unique_ptr<SceneGraph> SceneGraph::sceneGraphInstance = nullptr;

std::map<GLuint, std::vector<Model*>> SceneGraph::sceneModels = std::map<GLuint, std::vector<Model*>>();
std::map<std::string, GameObject*> SceneGraph::sceneGameObjects = std::map<std::string, GameObject*>();

SceneGraph * SceneGraph::GetInstance()
{
	if (sceneGraphInstance.get() == nullptr) {
		sceneGraphInstance.reset(new SceneGraph);
	}
	return sceneGraphInstance.get();
}

void SceneGraph::AddModel(Model * model_)
{
	if (sceneModels.find(model_->GetShaderProgram()) == sceneModels.end()) {
		std::vector<Model*> tmp = std::vector<Model*>();
		tmp.reserve(10);
		tmp.push_back(model_);
		sceneModels.insert(std::pair < GLuint, std::vector<Model*>>(model_->GetShaderProgram(), tmp));
	}
	else {
		sceneModels[model_->GetShaderProgram()].push_back(model_);
	}
}

void SceneGraph::AddGameObject(GameObject * go_, std::string tag_)
{
	if (sceneGameObjects.find(tag_) == sceneGameObjects.end()) {
		go_->SetTag(tag_);
		sceneGameObjects[tag_] = go_;
	}
	else {
		Debug::Warning("Trying to add a GameObject with a tag " + tag_ +
			" that already exist.", "SceneGraph.cpp", __LINE__);

		bool check = false;
		int loop = 1;
		std::string newTag = tag_ + std::to_string(loop);
		while(!check){
			if (sceneGameObjects.find(tag_) == sceneGameObjects.end()) {
				check = true;
			}
			else {
				loop++;
				newTag = tag_ + std::to_string(loop);
			}
		}
		go_->SetTag(newTag);
		sceneGameObjects[newTag] = go_;
	}
	CollisionHandler::GetInstance()->AddObject(go_);

}

GameObject * SceneGraph::GetGameObject(std::string tag_)
{
	if (sceneGameObjects.find(tag_) != sceneGameObjects.end()) {
		return sceneGameObjects[tag_];
	}
	return nullptr;
}

void SceneGraph::Update(const float deltaTime_)
{
	for (auto go : sceneGameObjects) {
		go.second->Update(deltaTime_);
	}
}

void SceneGraph::Render(Camera * camera_)
{
	//TODO: Frustum culling
	//World space culling (should this be the type i use? only version i found any explantation about)

	std::vector<glm::vec4> frustum;
	frustum.reserve(6);

	frustum = camera_->GetFrustumPlanes();

	for (auto entry : sceneModels) {

		glUseProgram(entry.first);

		for (auto m : entry.second) {
			
			if (!camera_->FrustumCull(frustum, &m->GetBoundingBox())) {
				m->Render(camera_);
			}
		}
	}
}

void SceneGraph::OnDestroy()
{
	if (sceneGameObjects.size() > 0) {
		for (auto go : sceneGameObjects) {
			delete go.second;
			go.second = nullptr;
		}
		sceneGameObjects.clear();
	}

	if (sceneModels.size() > 0) {
		for (auto entry : sceneModels) {
			if (entry.second.size() > 0) {
				for (auto m : entry.second) {
					delete m;
					m = nullptr;
				}
				entry.second.clear();
			}
		}
		sceneModels.clear();
	}
}

SceneGraph::SceneGraph()
{
}

SceneGraph::~SceneGraph()
{
	OnDestroy();
}
