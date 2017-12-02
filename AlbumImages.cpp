#include "AlbumImages.hpp"

AlbumImages::AlbumImages() {}

AlbumImages::~AlbumImages() {
  for (auto i : *listOfAlbumImages())
    delete i;
}

int AlbumImages::numAlbumImage() {
  return _listOfDataObjects->size();
}

void AlbumImages::addAlbumImage(AlbumImage *aimage) {
  _listOfDataObjects->push_back(aimage);
}

//i->album_id() == aID
AlbumImages* AlbumImages::albumImagewithID(int aID) {
  AlbumImages *album = new AlbumImages();
  for (auto i : *listOfAlbumImages()) {
    if (i->valueForIntegerAttribute("album_id") == aID)
      album->addAlbumImage(i);
  }
  return album;
}

void AlbumImages::loadAlbumImagesFromFile(std::string fileName) {
  std::fstream aiStream;
  aiStream.open(fileName.c_str(), std::fstream::in);
  parseJSONArray(aiStream);
  aiStream.close();
}

std::string AlbumImages::htmlString() {
  std::cout << "Not Used" << std::endl;
}

void AlbumImages::runAsserts() {
  std::cout << "asserts called AlbumImages" << std::endl;
  for (auto i: *_listOfDataObjects) {
    std::cout << "Inside for loop" << std::endl;
    i->print();
  }
}



/*
{"height": 505, "type": "primary",
"uri": "http://cWolf.cs.sonoma.edu/~cs315/projects/project5/images/R-1789539-1356465446-1930.jpeg",
"width": 500, "album_id": 45574}
*/
