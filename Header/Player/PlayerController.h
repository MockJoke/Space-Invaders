#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerModel.h"
#include "../Collision/ICollider.h"

namespace Player
{
    class PlayerView;
    class PlayerModel;
    
    enum class PlayerState;

    class PlayerController : public Collision::ICollider
    {
    private:
        float elapsed_shield_duration;
        float elapsed_rapid_fire_duration;
        float elapsed_triple_laser_duration;

        float elapsed_fire_duration;
        float elapsed_freeze_duration;
        
        PlayerView* player_view;
        PlayerModel* player_model;

        void processPlayerInput();
        void moveLeft();
        void moveRight();

        bool processBulletCollision(ICollider* other_collider);
        bool processPowerupCollision(ICollider* other_collider);
        bool processEnemyCollision(ICollider* other_collider);
        void updateFreezeDuration();
        void freezePlayer();

        void updateFireDuration();
        void processBulletFire();
        void fireBullet(bool b_triple_laser = false);
        void fireBullet(sf::Vector2f position);

        void updatePowerupDuration();
       
        void disableShield() const;   
        void disableRapidFire() const;    
        void disableTripleLaser() const;

    public:
        PlayerController();
        ~PlayerController();

        void initialize();
        void update();
        void render();

        void reset();

        void decreasePlayerLive();
        inline void increaseEnemiesKilled(int val) { PlayerModel::enemies_killed += val; }
        inline void increaseBulletsFired(int val) { PlayerModel::bullets_fired += val; }

        void enableShield();
        void enableRapidFire();
        void enableTripleLaser();

        sf::Vector2f getPlayerPosition() const;
        PlayerState getPlayerState() const;

        void onCollision(ICollider* other_collider) override;
        const sf::Sprite& getColliderSprite() override;
    };    
}