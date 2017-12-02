#include "Album.hpp"


Album::Album() {
  //std::cout << "Album created.." << std::endl;
}

Album::~Album() {
}

void Album::setTracks(Tracks *tracks) {

    _tracks = tracks;
}

void Album::setArtist(Artist *artist) {
  _artist = artist;
}


std::string Album::title() {
    if ( cachedtitle )
        return _title;
    cachedtitle = true;
    return _title = valueForStringAttribute("title");
}

std::string Album::genres() {
    if ( cachedgenre )
        return _genres;
    cachedgenre = true;
    return _genres = valueForStringAttribute("genres");
}

std::string Album::year() {
  if ( cachedyear )
    return _year;
    cachedyear = true;
    return _year = valueForStringAttribute("year");
}

int Album::albumID() {
    if ( cachedalbumid )
        return _albumID;
    cachedalbumid = true;
    return _albumID = valueForIntegerAttribute("album_id");
}

int Album::artistID() {
    if ( cachedartistid )
        return _artistID;
    cachedartistid = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}

int Album::numImages() {
    if ( cachednumimages )
        return _numImages;
    cachednumimages = true;
    return _numImages = valueForIntegerAttribute("num_images");
}

int Album::numTracks() {
    if ( cachednumtracks )
        return _numTracks;
    cachednumtracks = true;
    return _numTracks = valueForIntegerAttribute("num_tracks");
}

void Album::print() {
    std::cout << "Print in album is being called" << std::endl;
    std::cout << "Title: " << title() << std::endl;
    std::cout << "Genres: " << genres() << std::endl;
    std::cout << "albumID: " << albumID() << std::endl;
    std::cout << "artistID: " << artistID() << std::endl;
    std::cout << "numImage: " << numImages() << std::endl;
    std::cout << "numTracks: " << numTracks() << std::endl;
    std::cout << "year: " << year() << std::endl;

    if (_tracks) {
      std::cout << "Tracks is running asserts " << std::endl;
      std::cout << "\n\n\n\n ###ASSERTS### \n\n\n";
      _tracks->print();
      std::cout << "\n\n ASSERTS ENDED \n\n" << std::endl;
    }

    if (_primaryAlbumImage) {
      std::cout << "\nTracks is printing album image \n\n" << std::endl;
      _primaryAlbumImage->print();
    } else {
      std::cout << "No primary album image" << std::endl;
    }

    if (_secondaryAlbumImage) {
      std::cout << "\nTracks is printing album image #2 \n\n" << std::endl;
      _secondaryAlbumImage->print();
    } else {
      std::cout << "No secondary album image" << std::endl;
    }
}

std::string Album::htmlString() {
    std::string html;
    html += "<li>";
    if (_primaryAlbumImage)
      html += _primaryAlbumImage->htmlString();
    else if (_secondaryAlbumImage)
      html += _secondaryAlbumImage->htmlString();

    html += "<table class='albumInfo'>\n";
    html += "\t<tr>\n";
    html += "\t\t<td class='aTitle' colspan='2'>" + title() + "</td>\n";
    html += "\t</tr>\n";
    html += "\t<tr>\n";
    html += "\t\t<td class='tdNarrow'>Artist:</td>\n";
    html += "\t\t<td class='value'>" + _tracks->listOfTracks()->at(0)->artistName() + "</td>\n";
    html += "\t</tr>\n";
    html += "\t<tr>\n";
    html += "\t\t<td class='tdNarrow'>Genres:</td>\n";
    html += "\t\t<td class='value'>" + genres() + "</td>\n";
    html += "\t</tr>\n";
    html += "\t<tr>\n";
    html += "\t\t<td>Year:</td>\n";
    html += "\t\t<td class='value'>" + year() + "</td>\n";
    html += "\t</tr>\n";
    html += "</table>\n";
    /*clearfix*/
    html += "<div class='clear'>\n \t &nbsp; \n </div>\n";

    if (_tracks)
      html += _tracks->htmlString();
    html += "</li>";
    /* DO Tracklist now :D */
    return html;

}

void Album::setAlbumImages(AlbumImages *ai) {
  auto images = ai->albumImagewithID(albumID());
  for (auto i : *images->listOfAlbumImages()) {
    if (i->type() == "primary")
      _primaryAlbumImage = i;
    else if (i->type() == "secondary")
      _secondaryAlbumImage = i;
  }
  //possible memory leak?
}

void Album::createFile() {
  std::string identifier = "{%album%}";
  std::fstream infile("./html_albums/album.html");
  std::ofstream filetest;
  std::string filename = "./html_albums/" + std::to_string(albumID()) + ".html";
  filetest.open(filename);
  std::string line, holder;
  while (std::getline(infile, line)) {
    holder = line;
    holder.erase(std::remove(holder.begin(), holder.end(), ' '), holder.end());
    if (holder == identifier)
      filetest << htmlString();
    else
      filetest << line;
  }
  infile.close();
  filetest.close();
}
