#pragma once
#include "../contracts/idataset.h";
#include <string>

class IrisData : IDataset
{
public:
    IrisData(bool local = false, std::string path = "") {
        if(local) {
            // TODO: implement local logic
        } else {
            // TODO: implement request logic
        }
    }
    std::string GetTitle()
    {
        return title_;
    }

protected:
    std::string title_ = "Iris Flower Dataset";
};