#include "JSONDataItem.hpp"

JSONDataItem::JSONDataItem() {
}

JSONDataItem::~JSONDataItem() {
    //std::cout << "Deleting JSONDataItem" << std::endl;
}

void JSONDataItem::parseJSONItem(std::fstream &stream) {
    //std::cout << "CAlled JSONDataItem" << std::endl;
    char c;

    if(!(stream >> c) || c != '"')
        std::exit(1);

    _attribute = readQuotedString(stream);

    if(!(stream >> c) || c != ':')
        std::exit(1);

    stream >> c;
    if ( isdigit(c) ) {
        _isNumber = true;
        stream.unget();
        stream >> _ivalue;
    } else {
        _svalue = readQuotedString(stream);
    }

    hasReadAnItem = true;



}

std::string JSONDataItem::readQuotedString(std::fstream &stream) {
    char c, d;
    std::string temp;

    stream >> c; // not "

    while (c != '"') {
        if (c == '\\') {
            stream.get(d);
            temp += d;
            stream.get(c);
        } else {
            temp += c;
            stream.get(c);
        }
    }

    return temp;
}

void JSONDataItem::print() {
  std::cout << "Print in JSONDataItem is being called " << std::endl;
    std::cout << "Key: " << attribute() << std::endl;
    std::cout << "Value: ";
    if (isNumber())
        std::cout << integerValue() << std::endl;
    else
        std::cout << stringValue() << std::endl;
}
