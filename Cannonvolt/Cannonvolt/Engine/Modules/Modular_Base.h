#ifndef MODULAR_BASE_H
#define MODULAR_BASE_H


class Modular_Base{

public:	
	Modular_Base() {};
	virtual ~Modular_Base() {};

	virtual bool Initilize() { return true; };
	virtual void Update(const float deltaTime_) {};

};

#endif // !MODULAR_BASE_H