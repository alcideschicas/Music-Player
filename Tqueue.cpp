/*  File:    Tqueue.cpp                                                                                                                                                         
    Project: CMSC 202 Project 5, Fall 2017                                                                                                                                          
    Author:  Alcides Chicas                                                                                                                                                         
    Date:    11/30/17                                                                                                                                                               
    Section: 03                                                                                                                                                                     
    E-mail:  al30@umbc.edu                                                                                                                                                          
    Description: Tqueue templated data structure */

#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, int N>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: enqueue
  //Precondition: Existing Tqueue
  //Postcondition: Adds item to back of queue
  void enqueue(T data); //Adds item to queue (to back)
  //Name: dequeue
  //Precondition: Existing Tqueue
  //Postcondition: Removes item from front of queue
  void dequeue(T &); //Removes item from queue (from front)
  //Name: queueFront
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve front (does not remove it)
  void queueFront(T &);    // Retrieve front (does not remove it)
  //Name: isEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int isEmpty(); //Returns 1 if queue is empty else 0
  //Name: isFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int isFull(); //Returns 1 if queue is full else 0
  //Name: size
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue
  int size(); //Returns size of queue
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue
  //Postcondition: Returns object from Tqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from queue
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
};

//**** Class definition below ****

template <class T, int N>
Tqueue<T,N>::Tqueue() {

  // Creates dymanically allocated array with nothing in it
  m_data = new T[N];
  m_front = 0;
  m_back = 0;
}

template <class T, int N>
Tqueue<T,N>::Tqueue( const Tqueue<T,N>& x ) {
  
  // Copies Tqueue x to out Tqueue
  m_data = new T[N];
  m_front = x.m_front;
  m_back = x.m_back;
  for (int i = 0; i < x.m_back; i++) {
    m_data[i] = x.m_data[i];
  }
}

template <class T, int N>
Tqueue<T,N>::~Tqueue() {
  
  // Deletes dynamically allocated array with *T data
  delete[] m_data;
}

template <class T, int N>
void Tqueue<T,N>::enqueue(T data) {
  
  // Adds data to the front if it has space
  if (!isFull()) {
    m_data[m_back] = data;
    m_back++;
  } else {
    m_back = 0;
    m_data[m_back] = data;
    m_back++;
  }
}

template <class T, int N>
void Tqueue<T,N>::dequeue(T & front) {
  
  // Copies data passed and copies it, then updates front position
  m_data[m_front] = front;
  m_front++;
}

template <class T, int N>
void Tqueue<T,N>::queueFront(T & front) {

  // Copies data in front of queue to data passed
  front = m_data[m_front];
}

template <class T, int N>
int Tqueue<T,N>::isEmpty() {

  // Checks if first position has nothing in it
  if ((m_front == 0) and (m_back == 0)) {
    return 1;
  }
  else {
    return 0;
  }
}

template <class T, int N>
int Tqueue<T,N>::isFull() {

  // If back position is maximum size, it is full
  if (m_back == N) {
    return 1;
  }
  else {
    return 0;
  }
}

template <class T, int N>
int Tqueue<T,N>::size() {
  
  // Return back position which is the size
  if (isEmpty()) {
    return 0;
  } else {
    return m_back; 
  }
}

template <class T, int N>
Tqueue<T,N>& Tqueue<T,N>::operator=( Tqueue<T,N> y) {
  
  // Assigns queue passed to our queue 
  T* temp = new T[N];
  temp = y.m_data;
  delete [] m_data;
  m_data = temp.m_data;
  return *this;
}


template <class T, int N>
T& Tqueue<T,N>::operator[] (int x) {
  
  // Returns data at index passed
  return m_data[x];
}

#endif
