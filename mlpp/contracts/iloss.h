#pragma once

#include "../utils.h"

class ILoss
{
public:
    virtual double GetLoss() = 0;
    virtual void SetData(mlpp::tensor<1,double>::type y_hat, mlpp::tensor<1,double>::type y) = 0;
    virtual void SetCategoricalData(mlpp::tensor<2,double>::type y_hat, mlpp::tensor<2,double>::type y) = 0;
protected:
    virtual void Calculate() = 0;
};
