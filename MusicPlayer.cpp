/*  File:    MusicPlayer.cpp                                                                                                                                                      
    Project: CMSC 202 Project 5, Fall 2017                                                                                                                                          
    Author:  Alcides Chicas                                                                                                                                                         
    Date:    11/30/17                                                                                                                                                                                                                                                                                                                                    
    E-mail:  al30@umbc.edu                                                                                                                                                          
    Description: Music Player that adds user-chosen songs to a playlist */

#include "MusicPlayer.h"

// Constants for menu and year boundaries
const int MIN = 1;
const int ADD = 2;
const int PLAYLIST = 3;
const int MAX = 4;
const int MIN_YEAR = 1983;
const int MAX_YEAR = 2013;

MusicPlayer::MusicPlayer() {}

MusicPlayer::MusicPlayer(string filename) {  
  LoadCatalog(filename);
}

MusicPlayer::~MusicPlayer() {
  
  // Deletes each dynamically allocated song in catalog
  for (unsigned int i = 0; i < m_songCatalog.size(); i++) {
    delete m_songCatalog.at(i);
  }
}

void MusicPlayer::LoadCatalog(string filename) {
  
  ifstream inputFile (filename.c_str());
  
  if (inputFile.is_open()) {
    string rank;
    string artist;
    string title;
    string year;
    
    // Inputs songs
    while (getline(inputFile, rank, ',')) {
      
      if (inputFile.peek() == ',') {
        inputFile.ignore();
      }
      
      getline(inputFile, title, ',');            
      getline(inputFile, artist, ',');
      
      inputFile >> year;
      
      // Converts string to int
      int intRank = atoi(rank.c_str());
      int intYear = atoi(year.c_str());
      
      Song* song = new Song(title, artist, intYear, intRank);
      m_songCatalog.push_back(song);
    }
  }
  cout << "Music Catalog Loaded" << endl;
  inputFile.close();
}

void MusicPlayer::MainMenu() {

  cout << "Welcome to UMBC Music Player" << endl;
  cout << "What would you like to do?" << endl;
  cout << "1. Display Songs by Year" << endl;
  cout << "2. Add Song" << endl;
  cout << "3. Display Playlist" << endl;
  cout << "4. Quit" << endl;

  int choice;
  cin >> choice;

  // Validates input
  while ((choice > MAX) or (choice < MIN)) {
    cout << "\n";
    cout << "What would you like to do?" << endl;
    cout << "1. Display Songs by Year" << endl;
    cout << "2. Add Song" << endl;
    cout << "3. Display Playlist" << endl;
    cout << "4. Quit" << endl;
  }
  
  // Program continues until user quits
  while (choice != MAX) {
    
    switch (choice) {
    case MIN:
      DisplaySongs();
      break;
    case ADD:
      AddSong();
      break;
    case PLAYLIST:
      DisplayPlaylist();
      break;
    }
    
    cout << "\nWhat would you like to do?" << endl;
    cout << "1. Display Songs by Year" << endl;
    cout << "2. Add Song" << endl;
    cout << "3. Display Playlist" << endl;
    cout << "4. Quit" << endl;
    cin >> choice;
    
    // Validates input
    while ((choice > MAX) or (choice < MIN)) {
      cout << "What would you like to do?" << endl;
      cout << "1. Display Songs by Year" << endl;
      cout << "2. Add Song" << endl;
      cout << "3. Display Playlist" << endl;
      cout << "4. Quit" << endl;
      cin >> choice;
    }
  }  
  cout << "Thank you for using the UMBC Music Player" << endl;
}

void MusicPlayer::DisplaySongs() {
  
  int year;
  cout << "Which year would you like to display? (1983-2013)" << endl;
  cin >> year;
  
  // Validates input
  while ((year < MIN_YEAR) or (year > MAX_YEAR)) {
    cout << "Which year would you like to display? (1983-2013)" << endl;
    cin >> year;
  }
  
  cout << "******" << year << "*****" << endl;
  
  // Prints songs for year chosen
  for (unsigned int i = 0; i < (m_songCatalog.size() - 1); i++) {
    if (m_songCatalog.at(i)->getYear() == year) {
      cout << (i + 1) << ". " << m_songCatalog.at(i)->getTitle() << " by " << m_songCatalog.at(i)->getArtist() << endl;
    }
  }
}

void MusicPlayer::AddSong() {
  
  int song;
  
  if (m_playList.isEmpty()) {
    cout << "***Current Playlist is Empty***" << endl;
  }
  
  cout << "Choose the songs you would like to add to the playlist." << endl;
  DisplaySongs();
  cout << "Enter the number of the song you would like to add: " << endl;
  cin >> song;
  
  // Adds user chosen song to playlist with index from catalog
  m_playList.enqueue(*m_songCatalog.at(song - 1));
}

void MusicPlayer::DisplayPlaylist() {
  
  // Checks to see if playlist is empty and then prints out songs from playlist that user has chosen
  if (m_playList.isEmpty()) {
    cout << "***Current Playlist is Empty***" << endl;
  } else {
    
    cout << "\nYour Playlist:" << endl;
    for (int i = 0; i < m_playList.size(); i++) {
      cout << (i+1) << ". " << m_playList[i].getTitle() << " by " <<  m_playList[i].getArtist() << " from " <<  m_playList[i].getYear() << endl;
    }
  }
}
