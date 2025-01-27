#pragma once

#include <Onyx/Onyx.h>

using namespace Onyx;

class Sandbox2D : public Layer
{
public:

	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Timestep timestep) override;

private:
	Texture2D* m_Texture1;
	Texture2D* m_Texture2;

	Sound* m_Sound;

};