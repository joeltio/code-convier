#pragma once

#include <d3d9.h>
#include <string>
#include "Component.h"
#include "graphics.h"
#define LP_TEXTURE LPDIRECT3DTEXTURE9

namespace Component {

	struct Texture : public ECS::Component {
		public:
			bool visible = true;

			UINT totalWidth = 0;
			UINT totalHeight = 0;
			// Which layer to render on. Avoid large values as it will slow down the
			// render system
			char zIndex = 1;

			RECT viewableRect;

			std::string filePath;
			LP_TEXTURE texture = NULL;
			COLOR_ARGB filter = graphicsNS::WHITE;

			bool loadTexture(Graphics* graphics, const char* filePath);
	};

}
