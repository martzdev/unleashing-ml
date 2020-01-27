#pragma once

#include <vector>
#include "../factories/loss.h"
#include "../utils.h"

class MSE : public Loss
{
public:
    MSE() {}

protected:
    virtual void Calculate()
    {
        for (unsigned long i = 0; i < y_hat_.size(); i++)
            result_ += (y_hat_[i] - y_[i]) * (y_hat_[i] - y_[i]);

        result_ /= y_hat_.size();
    }
};
