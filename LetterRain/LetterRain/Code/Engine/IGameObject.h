#pragma once
class IGameObject
{
public:
	virtual ~IGameObject() {}
	virtual void DrawnUpdate() {}
	virtual void Update() {}
	virtual void Draw() {}
};

