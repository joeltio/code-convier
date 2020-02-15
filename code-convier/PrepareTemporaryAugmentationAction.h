#pragma once

#include <string>
#include "Action.h"

const std::string PREPARE_TEMPORARY_AUGMENTATION_ACTION = "PREPARE_TEMPORARY_AUGMENTATION_ACTION";

struct PrepareTemporaryAugmentationAction : public FSM::Action {
	PrepareTemporaryAugmentationAction() : FSM::Action(PREPARE_TEMPORARY_AUGMENTATION_ACTION) {}
};
