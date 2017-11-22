#include "JSONDataObject.hpp"
#include <typeinfo>

JSONDataObject::JSONDataObject() {
    _listOfDataItems = std::make_shared<std::vector<std::shared_ptr<JSONDataItem>>>();
    //_listOfDataItems = new std::vector<JSONDataItem *>;
}

JSONDataObject::~JSONDataObject() {
    //std::cout << "Called JSONDataObject DELETE" << std::endl;
    //std::cout << _listOfDataItems.use_count() << std::endl;
    //for (auto i : *_listOfDataItems) {
        //i.reset(); // deletes managed object
        //std::cout << "Deleting JSONDataObject" << std::endl;
    //}
    //_listOfDataItems->clear();
}

void JSONDataObject::parseFromJSONstream(std::fstream &stream) {
    char c;
    if (!(stream >> c) || c != '{') {
        std::exit(1);
    }

    do {
        auto jsitem = std::make_shared<JSONDataItem>();
        //JSONDataItem *jsitem = new JSONDataItem();
        //std::make_shared<Album>(*album)

        jsitem->parseJSONItem(stream);
        _listOfDataItems->push_back(jsitem);
        stream >> c;
    } while (c != '}');
}

void JSONDataObject::print() {
  std::cout << "Print in JSONDataObject is being called " << std::endl;
    for (auto i : *_listOfDataItems) {
        i->print();
    }
}

std::string JSONDataObject::valueForStringAttribute(std::string s) {
    for (auto i : *_listOfDataItems) {
        if (i->attribute() == s) {
            return i->stringValue();
        }
    }
    return "";
}

int JSONDataObject::valueForIntegerAttribute(std::string s) {
    for (auto i : *_listOfDataItems) {
        if (i->attribute() == s) {
            return i->integerValue();
        }
    }
    return 0;
}
