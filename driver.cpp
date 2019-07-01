/*  File:    driver.cpp                                                                                                                                                            
    Project: CMSC 202 Project 5, Fall 2017                                                                                                                                          
    Author:  Alcides Chicas                                                                                                                                                         
    Date:    11/30/17                                                                                                                                                                                                                                                                                                                                    
    E-mail:  al30@umbc.edu                                                                                                                                                          
    Description: Driver that creates a Music player and calls its main menu to run it */

#include <iostream>
#include "MusicPlayer.h"
#include "Song.h"
#include "Tqueue.cpp"

int main (int argc, char* argv[]) {
  string musicFile;
  cout << "Welcome to UMBC Music Player" << endl;
  if(argc > 1){
    musicFile = argv[1];
  } else{
    cout << "One music file required - try again" << endl;
    cout << "./proj5 p5_music1.txt" << endl;
    return 0;
  }
  MusicPlayer* myMusic = new MusicPlayer(musicFile);
  myMusic->MainMenu();
  delete myMusic;
  return 0;
}
