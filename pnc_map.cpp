#include "pnc_map.h"

#include <cmath>
#include <utility>

pnc_map::pnc_map() = default;

pnc_map::pnc_map(std::vector<Waypoint> points)
    : waypoints_(std::move(points))
{
    recompute_length();
}

void pnc_map::add_waypoint(const Waypoint &point)
{
    if (!waypoints_.empty())
    {
        const auto &last = waypoints_.back();
        total_length_ += std::hypot(point.x - last.x, point.y - last.y);
    }
    waypoints_.push_back(point);
}

const std::vector<pnc_map::Waypoint> &pnc_map::waypoints() const
{
    return waypoints_;
}

double pnc_map::total_length() const
{
    return total_length_;
}

void pnc_map::recompute_length()
{
    total_length_ = 0.0;
    if (waypoints_.size() < 2)
    {
        return;
    }

    for (std::size_t i = 1; i < waypoints_.size(); ++i)
    {
        const auto &a = waypoints_[i - 1];
        const auto &b = waypoints_[i];
        total_length_ += std::hypot(b.x - a.x, b.y - a.y);
    }
}