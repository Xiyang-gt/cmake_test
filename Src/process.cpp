#include "process.h"

#include <sstream>
#include <utility>

process::process() = default;

process::process(pnc_map map)
{
    configure(std::move(map));
}

void process::configure(pnc_map map)
{
    map_ = std::move(map);
    has_map_ = true;
    report_.clear();
}

bool process::run()
{
    if (!has_map_)
    {
        report_ = "process not configured";
        return false;
    }

    const auto &points = map_.waypoints();
    if (points.empty())
    {
        report_ = "map has no waypoints";
        return false;
    }

    std::ostringstream stream;
    stream << "Route with " << points.size() << " waypoints";
    for (const auto &point : points)
    {
        stream << " | " << point.label << "(" << point.x << "," << point.y << ")";
    }
    stream << " | total_length=" << map_.total_length();

    report_ = stream.str();
    return true;
}

const std::string &process::last_report() const
{
    return report_;
}
