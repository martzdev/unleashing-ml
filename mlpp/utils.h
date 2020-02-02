#pragma once

#include <vector>
#include <string>
#include <math.h>

namespace mlpp
{

template <size_t dim, typename T>
struct tensor
{
    typedef std::vector<typename tensor<dim - 1, T>::type> type;
};

template <typename T>
struct tensor<0, T>
{
    typedef T type;
};

double abs(double x)
{
    if (x < 0)
        return -x;
    return x;
}

tensor<1, std::string>::type SeparateString(std::string raw, std::string delimiter = ",")
{
    tensor<1, std::string>::type tokens;

    size_t pos = 0;
    while ((pos = raw.find(delimiter)) != std::string::npos)
    {
        tokens.push_back(raw.substr(0, pos));
        raw.erase(0, pos + delimiter.length());
    }
    tokens.push_back(raw);

    return tokens;
}

tensor<1, double>::type StringVToDouble(std::vector<std::string> unconverted)
{
    tensor<1,double>::type converted(unconverted.size());
    std::transform(unconverted.begin(), unconverted.end(), converted.begin(), [](const std::string &val) {
        return std::stod(val);
    });
    return converted;
}

} // namespace mlpp
