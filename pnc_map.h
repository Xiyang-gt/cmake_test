#pragma once

#include <string>
#include <vector>

class pnc_map
{
public:
    struct Waypoint
    {
        double x;
        double y;
        std::string label;
    };

    pnc_map();
    explicit pnc_map(std::vector<Waypoint> points);

    void add_waypoint(const Waypoint &point);
    const std::vector<Waypoint> &waypoints() const;
    double total_length() const;

private:
    std::vector<Waypoint> waypoints_;
    double total_length_{};

    void recompute_length();
};
