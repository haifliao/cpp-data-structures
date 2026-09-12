// Braking-distance learning exercise.
#include <iostream>

int main()
{
    const double speed_kmh = 90.0;
    const double reaction_time_s = 1.2;
    const double deceleration_mps2 = 4.0; // raining road condition
    const double speed_mps = speed_kmh * 1000.0 / 3600.0;
    const double reaction_distance_m = speed_mps * reaction_time_s;
    const double braking_distance_m = (speed_mps * speed_mps) / (2.0 * deceleration_mps2);
    const double total_distance_m = reaction_distance_m + braking_distance_m;
    std::cout << "At " << speed_kmh << " km/h, the total stopping distance is " << total_distance_m << " meters." << std::endl;

    const double obstacle_distance_m = 80.0;
    //const bool aeb_required = obstacle_distance_m <= total_distance_m;
    std::cout << "Obstacle distance: " << obstacle_distance_m << " meters." << std::endl;
    //std::cout << "AEB required: " << (aeb_required ? "Yes" : "No") << std::endl;

    const double safety_margin = 5.0;
    std::cout << "Safety margin: " << safety_margin << " meters." << std::endl;
    const double aeb_trigger_distance = total_distance_m + safety_margin;
    const bool aeb_triggered = obstacle_distance_m <= aeb_trigger_distance;
    std::cout << "AEB trigger distance: " << aeb_trigger_distance << " meters." << std::endl;
    std::cout << "AEB triggered: " << (aeb_triggered ? "Yes" : "No") << std::endl;

    return 0;
}
