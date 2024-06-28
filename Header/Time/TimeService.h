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

        float delta_time;   // To store the delta time

        void updateDeltaTime();
        float calculateDeltaTime() const;     // Calculate time by subtracting the previous time from the current time
        void updatePreviousTime();      // Finally update the current time to be previous time

    public:
        //lifecycle methods
        void initialize();
        void update();

        float getDeltaTime() const; 
    };    
}