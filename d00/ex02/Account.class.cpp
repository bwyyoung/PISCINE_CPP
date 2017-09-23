/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>
#include <string>
#include "Account.class.hpp"

#ifndef __DEBUG__
# define __DEBUG__ 0
#endif

//initialise static variables here. they are private,
// but can be initialised once.
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//Bonus
//PUT this INSIDE Account.class.hpp: mutable unsigned int call_count;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	//static variables are updated GLOBALLY to reflect upon other classes
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts += 1;

	//display timestamp, and STATE that based on the current index
	//which is _nbAccounts, we created an account
	Account::_displayTimestamp();
	//BONUS:
	//this->call_count = 0;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	return;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	return;
}

void Account::displayAccountsInfos(void)
{
	//display basic account info, including
	// total number of accounts
	// total value of combined accounts (MONEY IN BANK)
	// how much have we deposited
	// how much have we withdrawn
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << Account::_nbAccounts << ";total:"
				<< Account::_totalAmount << ";deposits:"
				<< Account::_totalNbDeposits << ";withdrawals:"
				<< Account::_totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	if (__DEBUG__)
	{
		//match time stamp shown in original log
		std::cout << "[20150406_153629] ";
		return ;
	}
	std::time_t t = std::time(0);
	struct tm * now = std::localtime( & t );
	std::cout	<< '[' << (now->tm_year + 1900)
				<< std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
				<< std::setw(2) << std::setfill('0') << now->tm_mday
				<< '_'
				<< std::setw(2) << std::setfill('0') << now->tm_hour
				<< std::setw(2) << std::setfill('0') << now->tm_min
				<< std::setw(2) << std::setfill('0') << now->tm_sec << "] ";
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();

	//show current amount data (p_amount), then update with deposit
	std::cout << "index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount
	<< ";deposit:" << deposit
	<< ";amount:" << ( this->_amount + deposit)
	<< ";nb_deposits:" << (this->_nbDeposits + 1) << std::endl;
	//update data
	this->_amount += deposit;
	this->_nbDeposits += 1;
	//also update global deposit data and total bank amount
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();

	std::cout << "index:"
	<< this->_accountIndex << ";p_amount:" << this->_amount;

	//if my bank account has not enough money to make a withdrawal, REFUSE
	if ((this->_amount - withdrawal) < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	//otherwise, perform the withdrawal
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	std::cout	<< ";withdrawal:" << withdrawal
				<< ";amount:" << ( this->_amount)
				<< ";nb_withdrawals:" << (this->_nbWithdrawals)
				<< std::endl;
	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	return true;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

Account::Account(void)
{
	return;
}

int		Account::checkAmount( void ) const
{
	//Bonus
	//this->call_count++;
	return this->_amount;
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}