#pragma once

#include "Component.h"

namespace Component {

	struct Animatable : ECS::Component {
		unsigned int columns;
		unsigned int rows;

		// The frame to start animating from. Frame counting starts from 1.
		unsigned int startFrame;
		// The frame to stop animating at. Frame counting starts from 1.
		unsigned int endFrame;
		// The current frame is absolute, meaning, if the startFrame is 3 and
		// endFrame is 5, currentFrame is in the interval [3, 5]
		unsigned int currentFrame;

		// How long to show each frame for
		float frameDelay;
		// Time left for the current frame. When 0 or negative, you should
		// switch to the next frame
		float frameTimeLeft;
		// Whether to loop from the start once one cycle of animation
		// completes
		bool loopForever = true;
		// Whether the animation has completed
		bool isComplete = false;
	};

}
