#pragma once
#include <vector>
#include "../factories/loss.h"
#include "../utils.h"

class MAE : public virtual Loss
{
public:
    MAE() {}

protected:
    virtual void Calculate()
    {
        for (unsigned long i = 0; i < y_hat_.size(); i++)
            result_ += mlpp::abs(y_hat_[i] - y_[i]);
    }
};
