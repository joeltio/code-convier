#include "GameAugmentationState.h"

void GameAugmentationState::enter(Component::State state) {
	// Create temporary augmentation background
	Entity::TemporaryAugmentation::create(this->manager, this->graphics);

	// Create temporary augmentation cards
	float xOffset = CARD_SIDE_MARGIN;
	ECS::EntityIdType increasedDamageCardId = Entity::Button::create(
		this->manager, this->graphics, INCREASED_DAMAGE_IMAGE, "Increased Damage", xOffset, 0, false, true);
	Component::Texture increasedDamageCardTexture = this->manager->getEntityComponent<Component::Texture>(increasedDamageCardId);
	xOffset += increasedDamageCardTexture.totalWidth + CARD_MARGIN;

	ECS::EntityIdType energyEfficientCardId = Entity::Button::create(
		this->manager, this->graphics, ENERGY_EFFICIENT_IMAGE, "Energy Efficient", xOffset, 0, false, true);
	Component::Texture energyEfficientCardTexture = this->manager->getEntityComponent<Component::Texture>(energyEfficientCardId);
	xOffset += energyEfficientCardTexture.totalWidth + CARD_MARGIN;

	ECS::EntityIdType multiHitCardId = Entity::Button::create(
		this->manager, this->graphics, MULTIHIT_IMAGE, "MultiHit", xOffset, 0, false, true);
}

FSM::Action GameAugmentationState::update(float frameTime, Component::State state) {
	return FSM::NoAction();
}

void GameAugmentationState::exit(Component::State state) {
	// Destroy temporary augmentation background
	std::unordered_set<ECS::EntityIdType> temporaryAugmentationEntityIds = *this->manager->getEntities<Entity::TemporaryAugmentation>();
	for (ECS::EntityIdType temporaryAugmentationEntityId : temporaryAugmentationEntityIds)
	{
		this->manager->removeEntity<Entity::TemporaryAugmentation>(temporaryAugmentationEntityId);
	}

	// Destroy temporary augmentation cards
	std::unordered_set<ECS::EntityIdType> butttonEntityIds = *this->manager->getEntities<Entity::Button>();
	for (ECS::EntityIdType butttonEntityId : butttonEntityIds)
	{
		this->manager->removeEntity<Entity::Button>(butttonEntityId);
	}
}