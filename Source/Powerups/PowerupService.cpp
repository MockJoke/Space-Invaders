#include "../../Header/Powerup/PowerupService.h"
#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Powerup/Controllers/RapidFireController.h"
#include "../../Header/Powerup/Controllers/ShieldController.h"
#include "../../Header/Powerup/Controllers/TripleLaserController.h"

namespace Powerup
{
	PowerupService::PowerupService() { }

	PowerupService::~PowerupService() { destroy(); }

	void PowerupService::initialize() { }

	void PowerupService::update()
	{
		for (Collectible::ICollectible* powerup : powerup_list)
		{
			powerup->update();
		}

		destroyFlaggedPowerup();
	}

	void PowerupService::render() const
	{
		for (Collectible::ICollectible* powerup : powerup_list)
		{
			powerup->render();
		}
	}

	PowerupController* PowerupService::createPowerup(PowerupType powerup_type)
	{
		switch (powerup_type)
		{
		case PowerupType::SHIELD:
			return new Controller::ShieldController(PowerupType::SHIELD);

		case PowerupType::RAPID_FIRE:
			return new Controller::RapidFireController(PowerupType::RAPID_FIRE);

		case PowerupType::TRIPLE_LASER:
			return new Controller::TripleLaserController(PowerupType::TRIPLE_LASER);
		}
	}

	PowerupController* PowerupService::spawnPowerup(PowerupType powerup_type, sf::Vector2f position)
	{
		PowerupController* powerup_controller = createPowerup(powerup_type);

		powerup_controller->initialize(position);

		Global::ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<Collision::ICollider*>(powerup_controller));
		powerup_list.push_back(powerup_controller);
		
		return powerup_controller;
	}

	void PowerupService::destroyFlaggedPowerup()
	{
		for (Collectible::ICollectible* powerup : flagged_powerup_list)
		{
			delete (powerup);
		}

		flagged_powerup_list.clear();
	}
	
	void PowerupService::destroyPowerup(PowerupController* powerup_controller)
	{
		powerup_controller->disableCollision();
		Global::ServiceLocator::getInstance()->getCollisionService()->removeCollider(powerup_controller);
		powerup_list.erase(std::remove(powerup_list.begin(), powerup_list.end(), powerup_controller), powerup_list.end());
		delete (powerup_controller);
	}

	void PowerupService::destroy() const
	{
		for (Collectible::ICollectible* powerup : powerup_list)
		{
			delete (powerup);
		}
	}
}