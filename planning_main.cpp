#include <iostream>
#include <utility>
#include <vector>

#include "pnc_map.h"
#include "process.h"

int main()
{
    std::vector<pnc_map::Waypoint> waypoints{
        {0.0, 0.0, "Start"},
        {12.0, 3.0, "Checkpoint"},
        {20.0, 10.0, "Merge"}
    };

    pnc_map map(std::move(waypoints));
    map.add_waypoint({30.0, 18.0, "Goal"});

    process planner(std::move(map));
    if (!planner.run())
    {
        std::cerr << "Planner failed: " << planner.last_report() << std::endl;
        return 1;
    }

    std::cout << planner.last_report() << std::endl;
    return 0;
}
