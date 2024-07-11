#include "../../Header/Bullet/BulletController.h"

#include "../../Header/Bullet/BulletModel.h"
#include "../../Header/Bullet/BulletView.h"

namespace Bullet
{
    BulletController::BulletController(BulletType type)
    {
        bullet_view = new BulletView();
        bullet_model = new BulletModel(type);
    }

    BulletController::~BulletController()
    {
        delete(bullet_view);
        delete(bullet_model);
    }

    void BulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
    {
    }

    void BulletController::update()
    {
    }

    void BulletController::render()
    {
    }

    void BulletController::updateProjectilePosition()
    {
    }

    void BulletController::handleOutOfBounds()
    {
    }

    void BulletController::moveUp()
    {
    }

    void BulletController::moveDown()
    {
    }

    sf::Vector2f BulletController::getProjectilePosition()
    {
        return bullet_model->getBulletPosition();
    }

    BulletType BulletController::getBulletType() const
    {
        return bullet_model->getBulletType();
    }

}
