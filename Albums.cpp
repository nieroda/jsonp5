#include "Albums.hpp"

Albums::Albums() {}
Albums::~Albums() {
    for (auto i : *listofAlbums())
      delete i;
}

int Albums::numAlbums() {
    return _listOfDataObjects->size();
}

void Albums::addAlbum(Album *album) {
    //_listOfDataObjects->push_back(std::make_shared<Album>(*album));
    _listOfDataObjects->push_back(album);
}

void Albums::loadAlbumsFromFile(std::string fileName) {
    std::fstream albumStream;
    albumStream.open(fileName.c_str(), std::fstream::in);
    parseJSONArray(albumStream);
    albumStream.close();
}

std::string Albums::htmlString() {
    std::string html;
    for (auto i : *listofAlbums())
      html += i->htmlString();

    return html;
}

void Albums::runAsserts() {
  std::cout << "RunAsserts in albums is being called" << std::endl;
    for ( auto i: *listofAlbums() ) {
      std::cout << "printing i " << std::endl;
        i->print();
      }
}

Albums* Albums::albumswithArtistID(int aID) {
  //std::cout << "Called albumsiwthartistid" << std::endl;
  Albums *newAlbum = new Albums();
  for (auto i : *listofAlbums()) {
    if (i->valueForIntegerAttribute("artist_id") == aID)
      newAlbum->addAlbum(i);
    //i->print();
  }
  return newAlbum;
}

void Albums::printIndividualAlbums() {
  for (auto i : *listofAlbums())
    i->createFile();
}
