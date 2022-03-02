#pragma once
class IGameObject
{
public:
	virtual ~IGameObject() {}
	virtual void Update() {}
	virtual void Draw() {}
};

