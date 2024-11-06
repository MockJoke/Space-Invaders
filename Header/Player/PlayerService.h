#pragma once

namespace Player
{
    class PlayerController;

    class PlayerService
    {
    private:
        PlayerController* player_controller;

    public:
        PlayerService();
        ~PlayerService();

        void initialize();
        void update();
        void render();
        void reset();

        void increaseScore(int val);
        void decreaseScore(int val);
        void increaseEnemiesKilled(int val) const;
		
        void enableShield() const;
        void enableRapidFire() const;
        void enableTripleLaser() const;
    };    
}