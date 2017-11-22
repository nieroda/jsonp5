#include "Albums.hpp"

Albums::Albums() {}
Albums::~Albums() { std::cout << "Destructor was called" << std::endl; }

int Albums::numAlbums() {
    return _listOfDataObjects->size();
}

void Albums::addAlbum(Album *album) {
    _listOfDataObjects->push_back(std::make_shared<Album>(*album));
}

void Albums::loadAlbumsFromFile(std::string fileName) {
    std::fstream albumStream;
    albumStream.open(fileName.c_str(), std::fstream::in);
    parseJSONArray(albumStream);
    albumStream.close();
}

std::string Albums::htmlString() {
    std::cout << "Foo : Bar : Baz " << std::endl;
}

void Albums::runAsserts() {
  std::cout << "RunAssers in albums is being called" << std::endl;
    for ( auto i: *_listOfDataObjects )
        i->print();
}
