#include "Artists.hpp"
#include <string>
#include <fstream>
#include <iostream>

Artists::Artists() {}
Artists::~Artists() {
  for (auto i : *listOfArtists())
    delete i;
}

int Artists::numArtists() {
    return _listOfDataObjects->size();
}

void Artists::addArtist(Artist *artist) {
    //_listOfDataObjects->push_back(std::make_shared<Artist>(*artist));
    _listOfDataObjects->push_back(artist);
}


Artist* Artists::artistWithID(int aID) {
    for (auto i: *listOfArtists()) {
        if (i->valueForIntegerAttribute("artist_id") == aID)
            return i;
    }
    return nullptr;
}

void Artists::loadArtistsFromFile(std::string fileName) {
    std::fstream artStream;
    artStream.open(fileName.c_str(), std::fstream::in);
    parseJSONArray(artStream);
    artStream.close();
}

std::string Artists::htmlString() {
    std::cout << "htmlString in artists is being called " << std::endl;
}




void Artists::runAsserts() {
  std::cout << "Run asserts in artists is being called" << std::endl;
  for (auto i: *_listOfDataObjects) {
    std::cout << "Inside for loop" << std::endl;
    i->print();
  }
}
