1. Some of my de-constructors are empty even though pointers were used due to the fact that I initialized them as null pointers so once
I delete the actual whats its pointing to I believe I am fine. {Will check office hours}

Files to include

Artist.hpp and Artist.cpp                 ✓
Album.hpp and Album.cpp                   ✓
Track.hpp and Track.cpp                   ✓
ArtistImage.hpp and ArtistImage.cpp       ✓
AlbumImage.hpp and AlbumImage.cpp         ✓
Artists.hpp and Artists.cpp               ✓
Albums.hpp and Albums.cpp                 ✓
Tracks.hpp and Tracks.cpp                 ✓
JSONDataItem.hpp and JSONDataItem.cpp     ✓
JSONDataObject.hpp and JSONDataObject.cpp ✓
JSONArray.hpp and JSONArray.cpp           ✓
main.cpp                                  ✓
Makefile                                  ✓
an empty sub-directory called html_albums ✖

I included a sub directory called html albums. HTML albums has a template html file called album.html. It reads and copies each line
from album.html into a new file and when it reaches {%%} it adds the string created by the code to the file. After all of this
it renames the file back to album.html rewriting it.

When this program is also ran it creates a file for each album. This file is named by the albumid and is stored inside of html_album.

/* File Names Expected */

ArtistImages -> "artistimage1.json";
Artists      -> "artists.json";
AlbumImages  -> "albumimages.json";
Tracks       -> "tracks.json";
Albums       -> "albums.json";
