#pragma once

#include "../utils.h"

class ILoss
{
public:
    virtual double GetLoss() = 0;
    virtual void SetData(std::vector<double> y_hat, std::vector<double> y) = 0;
    virtual void SetCategoricalData(mlpp::tensor<double> y_hat, mlpp::tensor<double> y) = 0;
protected:
    virtual void Calculate() = 0;
};
