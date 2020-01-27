#pragma once

#include "../contracts/idataset.h"
#include "../utils.h"

class Dataset : public virtual IDataset
{
public:
    virtual std::string GetTitle()
    {
        return title_;
    }
    virtual mlpp::tensor<double> GetX() = 0;
    virtual mlpp::tensor<double> GetY() = 0;

protected:
    std::string title_;
    virtual void FetchData() = 0;
};
