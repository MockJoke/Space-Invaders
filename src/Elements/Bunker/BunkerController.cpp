#include "../../../include/Elements/Bunker/BunkerController.h"
#include "../../../include/Elements/Bunker/BunkerView.h"
#include "../../../include/Bullet/BulletController.h"
#include "../../../include/Bullet/BulletConfig.h"
#include "../../../include/Global/ServiceLocator.h"

namespace Bullet
{
    class BulletController;
}

namespace Element
{
    namespace Bunker
    {
        BunkerController::BunkerController() { bunker_view = new BunkerView(); }

        BunkerController::~BunkerController() { delete(bunker_view); }

        void BunkerController::initialize(BunkerData data)
        {
            bunker_data = data;
            bunker_view->initialize(this); 
        }

        void BunkerController::update() { bunker_view->update(); }

        void BunkerController::render() { bunker_view->render(); }

        const sf::Sprite& BunkerController::getColliderSprite() { return bunker_view->getBunkerSprite(); }

        void BunkerController::onCollision(ICollider* other_collider)
        {
            Bullet::BulletController* bullet_controller = dynamic_cast<Bullet::BulletController*>(other_collider);

            if (bullet_controller && bullet_controller->getBulletType() == Bullet::BulletType::TORPEDO)
            {
                Global::ServiceLocator::getInstance()->getElementService()->destroyBunker(this);
            }
        }

        sf::Vector2f BunkerController::getBunkerPosition() const { return bunker_data.position; }
    }
}
