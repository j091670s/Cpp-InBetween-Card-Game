//******************************************************************************
// File name:  Bank.h
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Card Games
// Purpose:    Interface for class Bank. A Bank works in whole dollars only.
//******************************************************************************

#pragma once

#include <ostream>
#include <stdexcept>

class Bank {
public:
  Bank ();
  Bank (int amount);
  Bank (const Bank& rcBank);
  virtual ~Bank ();
  int getBalance () const;
  void add (int amount);
  void subtract (int amount);
  void clear ();

  friend std::ostream& operator<< (std::ostream& rcOutStream,
    const Bank& rcBank);

private:
  int mBalance;
  void setBalance (int iAmount);
};