#include <iostream>
#include <string>
#include <memory>


//g++ -std=c++11  main.cpp Tracks.cpp Track.cpp JSONArray.cpp JSONDataItem.cpp JSONDataObject.cpp -o outs.x


//#include "Album.hpp"
#include "Tracks.hpp"
//#include "Artist.hpp"
//#include "ArtistImage.hpp"
#include "Albums.hpp"

//void loadTracks();

int main() {

    std::shared_ptr<Tracks> track = std::make_shared<Tracks>();
    track->loadTracksFromFile("tracks.json");
    //std::cout << "Right before" << std::endl;
    //auto result = track->trackswithAlbumID(237541);
    //result->runAsserts();


    std::shared_ptr<Albums> album = std::make_shared<Albums>();
    album->loadAlbumsFromFile("albums.json");
    auto listOfAlbums = album->listofAlbums();
    for ( auto iter : *listOfAlbums ) {
      auto casted = reinterpret_cast<Album *>(iter.get());
      casted->setTracks(track->trackswithAlbumID(casted->albumID()).get());
      casted->print();
    }
    std::cout << "Finished" << std::endl;

/*
    for (auto newiter : *listOfAlbums ) {
      auto casted = reinterpret_cast<Album *>(newiter.get());
      casted->print();
    }
*/
/*8
    std::shared_ptr<Track> t = std::make_shared<Track>();
    auto value = t->getA();
    if (value) { std::cout << "Value is true" << std::endl; }
    else { std::cout << "Value is false" << std::endl; }
     */


    //std::fstream fs;
    //fs.open("artists.json");
    //t->parseFromJSONstream(fs);



    //Album *a = new Album();
    //delete a;
    /*
    Albums *album = new Albums();
    album->loadAlbumsFromFile("albums.json");
    album->runAsserts();
    delete album;
     */

    //Tracks *track = new Tracks();
    //track->loadTracksFromFile("tracks.json");
    //track->runAsserts();

    /*
    Artist *art = new Artist();

    std::fstream fs;
    fs.open("artists.json");
    art->parseFromJSONstream(fs);
    art->print();
    delete art;
    */

    //ArtistImage *a = new ArtistImage();
    //std::fstream fs;
    //fs.open("artistimage.json");
    //a->parseFromJSONstream(fs);
    //a->print();
    //delete a;


    return 0;
}


void loadTracks() {
    std::shared_ptr<Tracks> track = std::make_shared<Tracks>();
    track->loadTracksFromFile("tracks.json");
    std::cout << track->trackwithAlbumID(237541) << std::endl;
    //std::weak_ptr<Tracks> track;
    //if (!track.expired())
    //    track.lock()->loadTracksFromFile("tracks.json");
    //track->runAsserts();
}
