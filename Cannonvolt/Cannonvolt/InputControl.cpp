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
	if (KeyEventListener::keyMap[SDLK_a] == true){
		player->SetScale(glm::vec2(-0.1f, 0.1f));
		player->SetPosition(glm::vec2(player->GetPosition() + glm::vec2(-2.0f, 0.0f)));
	}
	if (KeyEventListener::keyMap[SDLK_s]) {

	}
	if (KeyEventListener::keyMap[SDLK_d]) {
		player->SetPosition(glm::vec2(player->GetPosition() + glm::vec2(2.0f, 0.0f)));
	}
	if (KeyEventListener::keyMap[SDLK_w]) {

	}
	if (KeyEventListener::keyMap[SDLK_SPACE]) {
		player->SetPosition(glm::vec2(player->GetPosition() + glm::vec2(0.0f, 2.0f)));
	}
}
/*Calls the KeyEventListener, grabs the keyMap and responds to pressing the spacebar [SDLK_SPACE]
when space is pressed, it will return an output that lets the character move 2.0f on the Y axis*/

//TO DO : LET THE CHARACTER FALL WHEN CHARACTER SPACE IS RELEASED

