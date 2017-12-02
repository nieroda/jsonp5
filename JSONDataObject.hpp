#ifndef __JSONDataObject__
#define __JSONDataObject__

#include "JSONDataObject.hpp"
#include "JSONDataItem.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <memory>

class JSONDataObject {
public:
    JSONDataObject();
    virtual ~JSONDataObject();
    //std::vector<JSONDataItem *> *listOfDataItems() const { return _listOfDataItems; }
    //std::shared_ptr<std::vector<std::shared_ptr<JSONDataItem>>> listofDataItems() { return _listOfDataItems; }
    std::vector<JSONDataItem *>* listofDataItems() { return _listOfDataItems; }
    void parseFromJSONstream(std::fstream &stream);
    virtual void print();
    std::string valueForStringAttribute(std::string s);
    int valueForIntegerAttribute(std::string s);

private:
    //std::vector<JSONDataItem *> *_listOfDataItems;
    std::vector<JSONDataItem *> *_listOfDataItems;
    //std::shared_ptr<std::vector<std::shared_ptr<JSONDataItem>>> _listOfDataItems;

};

#endif
