#pragma once

#include <string>

#include "pnc_map.h"

class process
{
public:
    process();
    explicit process(pnc_map map);

    void configure(pnc_map map);
    bool run();
    const std::string &last_report() const;

private:
    pnc_map map_{};
    bool has_map_{false};
    std::string report_{};
};
