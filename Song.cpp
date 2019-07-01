/*  File:    Song.cpp                                                                                                                                                           
    Project: CMSC 202 Project 5, Fall 2017                                                                                                                                          
    Author:  Alcides Chicas                                                                                                                                                         
    Date:    11/30/17                                                                                                                                                                                                                                                                                                                                   
    E-mail:  al30@umbc.edu                                                                                                                                                          
    Description: Mutators and accessors for song */

#include "Song.h"

Song::Song() {}

Song::Song(string title, string artist, int year, int rank) {
  m_title = title;
  m_artist = artist;
  m_year = year;
  m_rank = rank;
}

string Song::getTitle()const {
  return m_title;
} 

string Song::getArtist()const {
  return m_artist;
}

int Song::getYear()const {
  return m_year;
}

int Song::getRank()const {
  return m_rank;
} 

void Song::setTitle(string title) {
  m_title = title;
}

void Song::setArtist(string artist) {
  m_artist = artist;
}

void Song::setYear(int year) {
  m_year = year;
}

void Song::setRank(int rank) {
  m_rank = rank;
}
