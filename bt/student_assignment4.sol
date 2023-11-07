// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

/*
Write a program in solidity to create Student data. Use the following constructs:
1.Structures 2. Arrays 3.Fallback
Deploy this as smart contract on Ethereum and Observe the transaction fee and Gas values*/



contract StudentData {
    struct Student {
        uint256 id;
        string name;
        uint256 age;
    }

    Student[] public students;

    fallback() external {
        revert("Fallback function called. This contract does not accept Ether.");
    }

    function addStudent(uint256 _id, string memory _name, uint256 _age) public {
        Student memory newStudent = Student(_id, _name, _age);
        students.push(newStudent);
    }

    function getStudent(uint256 _index) public view returns (uint256, string memory, uint256) {
        require(_index < students.length, "Index out of bounds");
        Student storage s = students[_index];
        return (s.id, s.name, s.age);
    }

    function getStudentsCount() public view returns (uint256) {
        return students.length;
    }
}
