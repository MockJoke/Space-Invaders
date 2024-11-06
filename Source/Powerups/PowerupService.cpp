#include "../../header/Powerup/PowerupService.h"
#include "../../header/Powerup/PowerupController.h"
#include "../../header/Powerup/PowerupConfig.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Powerup/Controllers/RapidFireController.h"
#include "../../header/Powerup/Controllers/ShieldController.h"
#include "../../header/Powerup/Controllers/TrippleLaserController.h"

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

		case PowerupType::TRIPPLE_LASER:
			return new Controller::TrippleLaserController(PowerupType::TRIPPLE_LASER);
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