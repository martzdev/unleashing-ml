#pragma once

#include "../utils.h"

class IrisData
{
public:
    IrisData(bool local = false, std::string path = "")
    {
        if (local)
        {
            // TODO: implement local logic
        }
        else
        {
            // TODO: implement request logic
        }
    }

    // virtual mlpp::tensor<double> GetX() {}
    // virtual mlpp::tensor<double> GetY() {}

protected:
    std::string title_ = "Iris Flower Dataset";
    virtual void FetchData() {
        // TODO: implement data fetching
    }
};
