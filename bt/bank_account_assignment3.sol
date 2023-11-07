// SPDX-License-Identifier: Unlicensed
pragma solidity ^0.8.0;

//Write a smart contract on a test network, for Bank account of a customer for following 
//operations: 1. Deposit money 2.Withdraw Money 3. Show balance 

contract MyBank {
    mapping(address => uint) private _balances;

    event LogDepositMade(address accountHolder, uint amount);

    constructor() {
        _balances[msg.sender] = 1000;
        emit LogDepositMade(msg.sender, 1000);
    }

    function deposit() public payable returns (uint) {
        require(msg.value > 0, "Deposit amount must be greater than zero");
        _balances[msg.sender] += msg.value;
        emit LogDepositMade(msg.sender, msg.value);
        return _balances[msg.sender];
    }

    function withdraw(uint withdrawAmount) public returns (uint) {
        require(_balances[msg.sender] >= withdrawAmount, "Insufficient balance");
        _balances[msg.sender] -= withdrawAmount;
        payable(msg.sender).transfer(withdrawAmount);
        emit LogDepositMade(msg.sender, withdrawAmount);
        return _balances[msg.sender];
    }

    function viewBalance() public view returns (uint) {
        return _balances[msg.sender];
    }
}
