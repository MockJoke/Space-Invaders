#include<algorithm>
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Powerup/PowerupController.h"

namespace Player
{
	PlayerController::PlayerController()
	{
		player_view = new PlayerView();
		player_model = new PlayerModel();
	}

	PlayerController::~PlayerController()
	{
		delete (player_view);
		delete (player_model);
	}
	
	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize(this);
	}

	void PlayerController::update()
	{
		switch (player_model->getPlayerState())
		{
		case PlayerState::ALIVE:
			processPlayerInput();
			break;

		case PlayerState::FROZEN:
			updateFreezeDuration();
			break;
		}

		updatePowerupDuration();
		updateFireDuration();
		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}	

	void PlayerController::reset()
	{
		player_model->reset();
	}

	void PlayerController::processPlayerInput()
	{
		const Event::EventService* event_service = Global::ServiceLocator::getInstance()->getEventService();
		
		if (event_service->pressedLeftKey() || event_service->pressedAKey())
		{
			moveLeft();
		}
		if (event_service->pressedRightKey() || event_service->pressedDKey())
		{
			moveRight();
		}

		if (event_service->pressedLeftMouseButton())
			fireBullet();
	}

	void PlayerController::moveLeft()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x -= player_model->player_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::max(currentPosition.x, player_model->left_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::moveRight()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x += player_model->player_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::min(currentPosition.x, player_model->right_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}
	
	sf::Vector2f PlayerController::getPlayerPosition() const
	{
		return player_model->getPlayerPosition();
	}

	PlayerState PlayerController::getPlayerState() const
	{
		return player_model->getPlayerState();
	}

	const sf::Sprite& PlayerController::getColliderSprite()
	{
		return player_view->getPlayerSprite();
	}

	void PlayerController::onCollision(ICollider* other_collider)
	{
		if(processPowerupCollision(other_collider)) 
			return;

		if(processBulletCollision(other_collider)) 
			return;

		processEnemyCollision(other_collider);
	}

	bool PlayerController::processBulletCollision(ICollider* other_collider)
	{
		if (player_model->isShieldEnabled())
			return false;

		Bullet::BulletController* bullet_controller = dynamic_cast<Bullet::BulletController*>(other_collider);

		if (bullet_controller && bullet_controller->getEntityType() != Entity::EntityType::PLAYER)
		{
			if (bullet_controller->getBulletType() == Bullet::BulletType::FROST_BULLET)
			{
				freezePlayer();
			}
			else
			{
				decreasePlayerLive();
			}

			return true;
		}
		
		return false;
	}

	bool PlayerController::processEnemyCollision(ICollider* other_collider)
	{
		if (player_model->isShieldEnabled()) 
			return false;

		Enemy::EnemyController* enemy_controller = dynamic_cast<Enemy::EnemyController*>(other_collider);

		if (enemy_controller)
		{
			decreasePlayerLive();
			return true;
		}
		
		return false;
	}

	bool PlayerController::processPowerupCollision(ICollider* other_collider)
	{
		Powerup::PowerupController* powerup_controller = dynamic_cast<Powerup::PowerupController*>(other_collider);

		if (powerup_controller)
		{
			return true;
		}
		
		return false;
	}

	void PlayerController::updatePowerupDuration()
	{
		if (elapsed_shield_duration > 0)
		{
			elapsed_shield_duration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			
			if (elapsed_shield_duration <= 0) 
				disableShield();
		}

		if (elapsed_rapid_fire_duration > 0)
		{
			elapsed_rapid_fire_duration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			
			if (elapsed_rapid_fire_duration <= 0) 
				disableRapidFire();
		}

		if (elapsed_triple_laser_duration > 0)
		{
			elapsed_triple_laser_duration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			
			if (elapsed_triple_laser_duration <= 0) 
				disableTripleLaser();
		}
	}

	void PlayerController::freezePlayer()
	{
		player_model->setPlayerState(PlayerState::FROZEN);
		elapsed_freeze_duration = player_model->freeze_duration;
		player_view->setPlayerHighlight(true);
	}

	void PlayerController::enableShield()
	{
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::POWERUP_ENABLED);
		elapsed_shield_duration = player_model->shiled_powerup_duration;
		player_model->setShieldState(true);
		player_view->setPlayerHighlight(true);
	}

	void PlayerController::disableShield() const
	{
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::POWERUP_DISABLED);
		player_model->setShieldState(false);
		player_view->setPlayerHighlight(false);
	}

	void PlayerController::enableRapidFire()
	{
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::POWERUP_ENABLED);
		elapsed_rapid_fire_duration = player_model->rapid_fire_powerup_duration;
		player_model->setRapidFireState(true);
	}

	void PlayerController::disableRapidFire() const
	{
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::POWERUP_DISABLED);
		player_model->setRapidFireState(false);
	}

	void PlayerController::enableTripleLaser()
	{
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::POWERUP_ENABLED);
		elapsed_triple_laser_duration = player_model->triple_laser_powerup_duration;
		player_model->setTripleFireState(true);
	}

	void PlayerController::disableTripleLaser() const
	{
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::POWERUP_DISABLED);
		player_model->setTripleFireState(false);
	}

	void PlayerController::updateFireDuration()
	{
		if (elapsed_fire_duration >= 0)
		{
			elapsed_fire_duration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		}
	}

	void PlayerController::updateFreezeDuration()
	{
		if (elapsed_freeze_duration >= 0)
		{
			elapsed_freeze_duration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (elapsed_freeze_duration <= 0)
			{
				player_model->setPlayerState(PlayerState::ALIVE);
				player_view->setPlayerHighlight(false);
			}
		}
	}

	void PlayerController::processBulletFire()
	{
		if (elapsed_fire_duration > 0)
			return;
		
		if (player_model->isTripleLaserEnabled())
		{
			fireBullet(true);
		}
		else
		{
			fireBullet();
		}

		if (player_model->isRapidFireEnabled())
		{
			elapsed_fire_duration = player_model->rapid_fire_cooldown_duration;
		}
		else
		{
			elapsed_fire_duration = player_model->fire_cooldown_duration;
		}
	}

	void PlayerController::fireBullet(bool b_triple_laser)
	{
		sf::Vector2f bullet_position = player_model->getPlayerPosition() + player_model->barrel_position_offset;
		fireBullet(bullet_position);

		if (b_triple_laser)
		{
			fireBullet(bullet_position + player_model->second_weapon_position_offset);
			fireBullet(bullet_position + player_model->third_weapon_position_offset);
		}

		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BULLET_FIRE);
	}

	void PlayerController::fireBullet(sf::Vector2f position)
	{
		increaseBulletsFired(1);
		Global::ServiceLocator::getInstance()->getBulletService()->spawnBullet(Bullet::BulletType::PLAYER_BULLET,
		                                                                       player_model->getEntityType(), position, Bullet::MovementDirection::UP);
	}

	void PlayerController::decreasePlayerLive()
	{
		PlayerModel::player_lives -= 1;
		
		if (PlayerModel::player_lives <= 0)
		{
			reset();
		}
	}
}