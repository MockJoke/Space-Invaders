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

	PowerupService::~PowerupService()
	{
		destroy();
	}

	void PowerupService::initialize() { }

	void PowerupService::update() const
	{
		for (int i = 0; i < powerup_list.size(); i++)
			powerup_list[i]->update();
	}

	void PowerupService::render() const
	{
		for (int i = 0; i < powerup_list.size(); i++)
			powerup_list[i]->render();
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
		powerup_list.push_back(powerup_controller);
		
		return powerup_controller;
	}

	void PowerupService::destroyPowerup(PowerupController* powerup_controller)
	{
		powerup_list.erase(std::remove(powerup_list.begin(), powerup_list.end(), powerup_controller), powerup_list.end());
		delete(powerup_controller);
	}

	void PowerupService::destroy() const
	{
		for (int i = 0; i < powerup_list.size(); i++)
			delete (powerup_list[i]);
	}
}