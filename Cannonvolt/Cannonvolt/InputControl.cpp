#include "InputControl.h"
#include "Engine/Events/KeyEventListener.h"


InputControl::InputControl(){

}

InputControl::~InputControl(){
	player = nullptr;
}

void InputControl::Init(GameObject* player_){
	player = player_;
}

void InputControl::Update(float deltaTime_){
	if (KeyEventListener::keyMap[SDLK_a]){
		player->SetPosition(glm::vec2(player->GetPosition() + glm::vec2(-2.0f, 0.0f)));
	}
	if (KeyEventListener::keyMap[SDLK_s]) {

	}
	if (KeyEventListener::keyMap[SDLK_d]) {
		player->SetPosition(glm::vec2(player->GetPosition() + glm::vec2(2.0f, 0.0f)));
	}
	if (KeyEventListener::keyMap[SDLK_w]) {
		
	}
	if (KeyEventListener::keyMap[SDLK_LSHIFT]) {
	player->SetPosition(glm::vec2(player->GetPosition() + glm::vec2( /* player direction * */20.0f, 0.0f)));
}

