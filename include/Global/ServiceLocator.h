#pragma once
#include "../AnimationSystem/AnimationService.h"
#include "../Enemy/EnemyService.h"
#include "../Graphic/GraphicService.h"
#include "../Event/EventService.h"
#include "../Gameplay/GameplayService.h"
#include "../Player/PlayerService.h"
#include "../Time/TimeService.h"
#include "../UI/UIService.h"
#include "../Elements/ElementService.h"
#include "../Sound/SoundService.h"
#include "../Bullet/BulletService.h"
#include "../Collision/CollisionService.h"
#include "../Powerup/PowerupService.h"

namespace Global
{
    /* Class Summary
        This class manages access to various services in the application
    */
    class ServiceLocator
    {
    private:
        Graphic::GraphicService* graphic_service;
        Time::TimeService* time_service;
        Event::EventService* event_service;
        UI::UIService* ui_service;
        Gameplay::GameplayService* gameplay_service;
        Player::PlayerService* player_service;
        Enemy::EnemyService* enemy_service;
        Element::ElementService* element_service;
        Sound::SoundService* sound_service;
        Bullet::BulletService* bullet_service;
        Powerup::PowerupService* powerup_service;
        Collision::CollisionService* collision_service;
        Animation::AnimationService* animation_service;
        
        ServiceLocator(); 
        ~ServiceLocator(); 	

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize() const;
        void update() const;
        void render() const;

        Graphic::GraphicService* getGraphicService() const;
        Time::TimeService* getTimeService() const;
        Event::EventService* getEventService() const;
        UI::UIService* getUIService() const;
        Gameplay::GameplayService* getGameplayService() const;
        Player::PlayerService* getPlayerService() const;
        Enemy::EnemyService* getEnemyService() const;
        Element::ElementService* getElementService() const;
        Sound::SoundService* getSoundService() const;
        Bullet::BulletService* getBulletService() const;
        Powerup::PowerupService* getPowerupService() const;
        Collision::CollisionService* getCollisionService() const;
        Animation::AnimationService* getAnimationService() const;
    };
}
