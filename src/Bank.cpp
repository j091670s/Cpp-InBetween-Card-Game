//******************************************************************************
// File name:   Bank.cpp
// Author:      Gio Adaya
// Date:        4/18/2025
// Class:       CS250
// Assignment:  05 CardGamePart C
// Purpose:     To implement the class responsible for handling the money that
//              is betted when playing a round.
// Hours:       1.0
//******************************************************************************
#include <iostream>
#include "../include/Card.h"
#include "../include/Bank.h"

#include <exception>
#include <string>

const int EMPTY_BALANCE = 0;

/*******************************************************************************
Function:     Bank

Description:  Default constructor which sets the private member mBalance to 0.

Parameter:    None

Returned:     None
*******************************************************************************/
Bank::Bank () {
  mBalance = EMPTY_BALANCE;
}

/*******************************************************************************
Function:     Bank parameterized constructor

Description:  Bank parameterized constructor which sets the mBalance private
              member to the argument passed in, which is int amount. If the
              argument is less than zero, the parameterized construcot will
              throw an invalid_argument exception.

Parameter:    amount - The amount that mBalance will be set to

Returned:     None
*******************************************************************************/
Bank::Bank (int amount) {
  setBalance (amount);
}

/*******************************************************************************
Function:     Bank copy constructor

Description:  Sets the value of mBalance to the reference Bank objects mBalance

Parameter:    rcBank -  a constant reference to the Bank object that mBalance
                        will be set to

Returned:     None
*******************************************************************************/
Bank::Bank (const Bank& rcBank) {
  setBalance (rcBank.mBalance);
}

/*******************************************************************************
Function:     Bank destructor

Description:  Does nothing for now

Parameter:    Now

Returned:     None
*******************************************************************************/
Bank::~Bank () {

}

/*******************************************************************************
Function:     getBalance

Description:  getBalance returns the balance (mBalance) of the Bank object

Parameter:    None

Returned:     The balanace (mBalance) of the Bank object, which is of type int
*******************************************************************************/
int Bank::getBalance () const {
  return mBalance;
}

/*******************************************************************************
Function:     add

Description:  Adds the amount passed in to the balance (mBalance) of the Bank
              object. The amount must be greater than zero, otherwise an
              invalid_argument exception is thrown

Parameter:    amount - the amount to be added to the Banks balance (mBalance)

Returned:     None (void)
*******************************************************************************/
void Bank::add (int amount) {
  if (amount < EMPTY_BALANCE) {
    throw std::invalid_argument
    ("Bank Exception::add: amount must be positive");
  }
  else {
    mBalance += amount;
  }
}

/*******************************************************************************
Function:     subtract

Description:  Subtracts the amount passed in to the Balance (mBalance) of the
              Bank object. The amount passed in must be greater than zero,
              otherwise an invalid_argument exception is thrown

Parameter:    amount - the amount to be subtracted from the Banks balance
                       (mBalance)

Returned:     None (void)
*******************************************************************************/
void Bank::subtract (int amount) {
  if (amount < EMPTY_BALANCE) {
    throw std::invalid_argument
    ("Bank Exception::subtract: amount must be positive");
  }
  else {
    mBalance -= amount;
  }
}

/*******************************************************************************
Function:     clear

Description:  Sets the mBalance private member back to a value of zero.

Parameter:    None

Returned:     None (void)
*******************************************************************************/
void Bank::clear () {
  mBalance = EMPTY_BALANCE;
}

/*******************************************************************************
Function:     operator<<

Description:  an overloaded friend function that overloads the insertion
              operator to output a Bank objects mBalance

Parameter:    rcOutStream - a reference to the output stream we are outputting
                            to
              rcBank      - a constant reference of the Bank object that we are
                            outputting it's mBalance

Returned:     A reference to the output stream we are writing to
*******************************************************************************/
std::ostream& operator << (std::ostream& rcOutStream, const Bank& rcBank) {
  rcOutStream << rcBank.mBalance;
  return rcOutStream;
}
/*******************************************************************************
Function:     setBalance

Description:  Sets the mBalance private member value to the amount passed in.
              The amount must be greater than zero, otherwise an
              invalid_argument exception is thrown

Parameter:    amount - The amount that mBalance will be set to

Returned:     None (void)
*******************************************************************************/
void Bank::setBalance (int iAmount) {
  if (iAmount < EMPTY_BALANCE) {
    throw std::invalid_argument
    ("Bank Exception::Bank: amount must be positive");
  }
  else {
    mBalance = iAmount;
  }
}