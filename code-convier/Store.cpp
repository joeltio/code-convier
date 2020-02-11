#include "Store.h"

namespace FSM {

Store::~Store() {
	// Deallocate the reducers
	for (Reducer* reducer : this->reducers)
	{
		SAFE_DELETE(reducer);
	}
}

Store::Store(ECS::Manager* manager, std::unordered_map<Types::TypeId, State*> states) {
	this->states = states;
	this->manager = manager;
}

void Store::registerReducer(Reducer* reducer) {
	this->reducers.push_front(reducer);
}

void Store::dispatchAction(Action &action) {
	// Search for a reducer which handles this action
	for (Reducer* reducer : this->reducers)
	{
		if (reducer->acceptsAction(action))
		{
			reducer->reduce(this->manager, this->states, action);
			break;
		}
	}
}

}
