#pragma once

#include <vector>
#include <string>
#include <math.h>

namespace mlpp
{

template <class T>
using tensor = std::vector<std::vector<T>>;

double abs(double x)
{
    if (x < 0)
        return -x;
    return x;
}

std::vector<std::string> SeparateString(std::string raw, std::string delimiter = ",")
{
    std::vector<std::string> tokens;

    size_t pos = 0;
    while ((pos = raw.find(delimiter)) != std::string::npos)
    {
        tokens.push_back(raw.substr(0, pos));
        raw.erase(0, pos + delimiter.length());
    }
    tokens.push_back(raw);

    return tokens;
}

std::vector<double> StringVToDouble(std::vector<std::string> unconverted)
{
    std::vector<double> converted(unconverted.size());
    std::transform(unconverted.begin(), unconverted.end(), converted.begin(), [](const std::string &val) {
        return std::stod(val);
    });
    return converted;
}

} // namespace mlpp
