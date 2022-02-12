#pragma once
#include <GUI/IGUIPainter.h>

class Spatial;
class ObserverComponent;
class IRenderer;

/// <summary>
/// Simple world gui painter window
/// <para>Contains performance metrics,background options,renderer draw mode and truck options</para>
/// </summary>
class WorldGUIPainter : public IGUIPainter
{
public:
	WorldGUIPainter(IRenderer* renderer,ObserverComponent* observer,Spatial* cargo) ;
	~WorldGUIPainter() = default;


	virtual String GetWindowName() const override;

	// Inherited via IGUIPainter
	virtual void OnGUIEnable() override;

	virtual void OnGUIPaint(float deltaTime) override;

	virtual void OnGUIFinalize() override;

private:
	IRenderer* m_Renderer;
	ObserverComponent* m_Observer;
	Spatial* m_Cargo;

};

