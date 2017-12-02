#include <iostream>
#include <string>
#include <algorithm>


#include "Albums.hpp"
#include "AlbumImages.hpp"
#include "Artists.hpp"
#include "ArtistImages.hpp"
#include "Tracks.hpp"

void writeToFile(std::string &html);

int main() {


    ArtistImages *artistImage = new ArtistImages();
    artistImage->loadArtistImagesFromFile("artistimage1.json");

    Artists *artist = new Artists();
    artist->loadArtistsFromFile("artists.json");

    AlbumImages *ai = new AlbumImages();
    ai->loadAlbumImagesFromFile("albumimages.json");

    Tracks *track = new Tracks();
    track->loadTracksFromFile("tracks.json");

    Albums *album = new Albums();
    album->loadAlbumsFromFile("albums.json");

    for (auto i : *album->listofAlbums())  {
      i->setTracks(track->trackswithAlbumID(i->albumID()));
      i->setAlbumImages(ai);
    }

    album->printIndividualAlbums();

    std::string html;
    for (auto i : *artist->listOfArtists()) {
      i->setArtistImages(artistImage->imageswithID(i->artistID()));
      i->setAlbums(album->albumswithArtistID(i->artistID()));
      html += i->htmlString();
    }
    writeToFile(html);

    delete artistImage;
    delete artist;
    delete ai;
    delete track;
    delete album;


    return 0;
}

void writeToFile(std::string &html) {
  std::string identifier = "{%artists%}";
  std::fstream infile("./html_albums/artists.html");
  std::ofstream filetest;
  filetest.open("./html_albums/artistmain.html");
  std::string line, holder;
  while (std::getline(infile, line)) {
    holder = line;
    holder.erase(std::remove(holder.begin(), holder.end(), ' '), holder.end());
    if (holder == identifier)
      filetest << html;
    else
      filetest << line;
  }
  filetest.close();
  std::rename("./html_albums/artistmain.html", "./html_albums/artists.html");
}
