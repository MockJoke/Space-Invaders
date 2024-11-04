#pragma once
#include "../../Header/Projectile/IProjectile.h"
#include "../../header/Entity/EntityConfig.h"

namespace Bullet
{
    class BulletView;
    class BulletModel;
    enum class BulletType;
 
    class BulletController : public Projectile::IProjectile
    {
    protected:
        BulletView* bullet_view;
        BulletModel* bullet_model;  
        
        void updateProjectilePosition() override;

        void moveUp();
        void moveDown();
        void handleOutOfBounds();

    public:
        BulletController(BulletType bullet_type, Entity::EntityType entity_type);
        virtual ~BulletController() override;
        
        void initialize(sf::Vector2f position, MovementDirection direction) override;
        void update() override;
        void render() override;

        sf::Vector2f getProjectilePosition() override;
        BulletType getBulletType() const;
        Entity::EntityType getEntityType() const;
    };
}