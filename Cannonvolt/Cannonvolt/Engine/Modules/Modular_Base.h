#ifndef MODULAR_BASE_H
#define MODULAR_BASE_H


class Modular_Base{

public:	
	virtual bool Initilize() = 0;
	virtual void Update(const float deltaTime_) = 0;

};

#endif // !MODULAR_BASE_H