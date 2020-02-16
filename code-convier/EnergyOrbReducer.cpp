#include "EnergyOrbReducer.h"

bool EnergyOrbReducer::acceptsAction(FSM::Action& action) {
	for (std::string acceptedAction : ACCEPTED_ACTIONS)
	{
		if (action.type == acceptedAction)
		{
			return true;
		}
	}

	return false;
}

void EnergyOrbReducer::reduce(
	ECS::Manager* manager,
	std::unordered_map<Types::TypeId, FSM::State*> states,
	FSM::Action action
) {
	if (action.type == ORB_DETECT_PLAYER_ACTION)
	{
		// Change the state of the energy orb entity
		Component::EnergyOrbState& orbState = manager->getEntityComponent<Component::EnergyOrbState>(action.dispatcherEntityId);

		FSM::Reducer::changeState<EnergyOrbHomingState>(states, orbState);
	}
}
