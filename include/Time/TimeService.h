#pragma once
#include <chrono>

namespace Time
{
    /* Class Summary
        This class helps keep track of time in game & calculate delta time
        Utilizes the <chrono> library to calculate delta time
    */
    class TimeService
    {
    private:
        // A point in time which indicates the starting time of previous frame
        std::chrono::time_point<std::chrono::steady_clock> previous_time;

        float delta_time;

        void updateDeltaTime();
        float calculateDeltaTime() const;
        void updatePreviousTime();

    public:
        void initialize();
        void update();

        float getDeltaTime() const; 
    };    
}