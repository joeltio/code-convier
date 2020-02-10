#include "TextureComponent.h"

namespace Component {

	bool Texture::loadTexture(Graphics* graphics, const char* filePath) {
		this->filePath = filePath;

		try
		{
			HRESULT hr = graphics->loadTexture(
				filePath,
				TRANSCOLOR,
				this->totalWidth,
				this->totalHeight,
				this->texture
			);

			if (FAILED(hr))
			{
				SAFE_RELEASE(this->texture);
				return false;
			}

			// Set the viewable rectangle to the whole image
			this->viewableRect.left = 0;
			this->viewableRect.right = this->totalWidth;
			this->viewableRect.top = 0;
			this->viewableRect.bottom = this->totalHeight;

			return true;
		}
		catch (...)
		{
			return false;
		}
	}

}