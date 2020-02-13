#pragma once

#include <vector>
#include <forward_list>

#include "renderConstants.h"

#include "System.h"
#include "Manager.h"
#include "GameDataComponent.h"
#include "TextureComponent.h"
#include "TransformComponent.h"

namespace System {

class Render : public ECS::System {
	public:
		void renderTexture(LP_SPRITE sprite, Component::Texture& textureComponent, RECT offset);

		void render();

		void releaseAll();

		void resetAll();
};

}
