#pragma once

#include "../utils.h"

class IDataset
{
public:
    virtual std::string GetTitle() = 0;
    virtual mlpp::tensor<double> GetX() = 0;
    virtual mlpp::tensor<double> GetY() = 0;

protected:
    virtual void FetchData() = 0;
};
