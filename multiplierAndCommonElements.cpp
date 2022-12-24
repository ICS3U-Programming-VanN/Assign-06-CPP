// Copyright (c) 2022 Van Nguyen All rights reserved.
//
// Created by: Van Nguyen
// Created on: December 20, 2022
// This program asks the user if they want to multiply / divide a
// list by a multiplier / divisor OR if the user wants to find the
// common / uncommon elements of two lists


#include <iostream>
#include <list>
#include <string>


// This function finds and returns the uncommon elements of two lists
std::list<std::string> UncommonElements(std::list<std::string> listOfElements,
                                    std::list<std::string> listOfElements2) {
    // Initializes List
    std::list<std::string> uncommonElements = {};

    // Initializes boolean variable
    bool elementFound = false;

    // Iterates through each index in the first list
    for (auto element : listOfElements) {
        // Sets the elementFound variable to false
        elementFound = false;
        // Iterates through each element in the second list
        for (auto secondElement : listOfElements2) {
            // IF the element in the first list is present in the second list
            if (element == secondElement) {
                // Sets elementFound to true
                elementFound = true;

                // Exits the loop as they are a common element
                break;
            }
        }
        // IF the element is not present in the second list
        if (!elementFound) {
            // Adds the element to the uncommon elements list
            uncommonElements.push_back(element);
        }
    }

    // Iterates through each element in the second list
    for (auto element : listOfElements2) {
        // Sets elementFound to false
        elementFound = false;

        // Iterates through each index the in the second list
        for (auto secondElement : listOfElements) {
            // IF the element from the second list is present in the first list
            if (element == secondElement) {
                // Sets elementFound to true
                elementFound = true;

                // Exits loop as they are a common element
                break;
            }
        }
        // IF the element is not common in both lists
        if (!elementFound) {
            // Adds the element to the uncommon elements list
            uncommonElements.push_back(element);
        }
    }

    // Returns the list of uncommon elements to function call
    return uncommonElements;
}


// This function finds and returns the common elements of two lists
std::list<std::string> CommonElements(std::list<std::string> listOfElements,
                                      std::list<std::string> listOfElements2) {
    // Initializes common elements list
    std::list<std::string> commonElements = {};

    // Iterates through each index of the first list
    for (auto firstElements : listOfElements) {
        // Iterates through each index of the second list
        for (auto secondElements : listOfElements2) {
            // IF the element from the first list is present in the second one
            if (firstElements == secondElements) {
                // Add the element to the common elements list
                commonElements.push_back(firstElements);
            }
        }
    }

    // Returns the common elements list to function call
    return commonElements;
}


// This function divides each integer in a list by a divisor and returns it
std::list<float> ListDivisor(std::list<int> listInts, float divisor) {
    // Initialized list
    std::list<float> listDivided = {};

    // Iterates through each value in the list of integers
    for (float index : listInts) {
        // Calculates the value of the index divided by the divisor
        index = static_cast<float>(index) / divisor;

        // Adds the new calculates value to the new list
        listDivided.push_back(index);
    }

    // Returns the list of newly divided integers to function call
    return listDivided;
}


// This function multiplies each integer
// in a list by a multiplier and returns it
std::list<float> ListMultiplier(std::list<int> listInts, float multiplier) {
    // Initializes new list
    std::list<float> listMultiplied = {};

    // Iterates through each value in the list of integers
    for (float index : listInts) {
        // Calculates the value of the index multiplied by the multiplier
        index = static_cast<float>(index) * multiplier;

        // Adds the multiplied value to the new list
        listMultiplied.push_back(index);
    }

    // Returns the new list of each element multiplied by the multiplier
    return listMultiplied;
}


int main() {
    // Declared Variables
    std::string multiplierOrCommon, multiplyOrDivide, commonOrUncommon;
    std::string userListString, numberString, yesOrNo;
    std::string userMultiplierString, userDivisorString;
    std::string secondUserListString, elementString, secondElementString;
    float userMultiplier, elementFloat;
    int elementInt;

    // Declared Lists
    std::list<std::string> userList, secondUserList;
    std::list<std::string> userCommonElements, userUncommonElements;
    std::list<int> userListInt;
    std::list<float> listMultiplied, listDivided;

    // Initialized Variables
    float userDivisor = 1;
    bool invalidList = false;
    bool invalidDivisor = false;
    bool userRepeat = false;

    // Repeats program until user states otherwise
    while (!userRepeat) {
        // Resets lists and boolean variables when program repeats
        userList = {};
        secondUserList = {};
        invalidDivisor = false;
        invalidList = false;
        userListInt = {};

        // Displays user how to input a list
        std::cout << "Example on how to input a list:\nInput a list: 2 5 3 5\n"
                  << std::endl;

        // Repeats until the user enters valid input (1 or 2)
        while (multiplierOrCommon != "1" || multiplierOrCommon != "2") {
            // Asks user if they want to multiply/divide a list of integers
            // or find the common/uncommon elements of two lists
            std::cout << "Do you want to multiply/divide "
                      << "a list of integers (Option 1)?"
                      << "\nOR\nDo you want to find the "
                      << "common/uncommon elements of two lists"
                      << "(Option 2)?\n\nEnter '1' for the first option "
                      << "or '2' for the second option: ";
            std::getline(std::cin, multiplierOrCommon);

            // IF the user enters valid input for the question (1 or 2)
            if (multiplierOrCommon == "1" || multiplierOrCommon == "2") {
                // Exits loop as the user entered valid input
                break;
            }
        }

        // IF the user wants to multiply or divide the elements in a list
        if (multiplierOrCommon == "1") {
            // Ensures that the user inputs valid input (1 or 2)
            while (multiplyOrDivide != "1" || multiplyOrDivide != "2") {
                // Asks user if they want to multiply
                // or divide the integers of a list
                std::cout << "Do you want to multiply or divide the "
                          << "integers of a list? "
                          << "(Enter '1' to multiply or '2' to divide): ";
                std::getline(std::cin, multiplyOrDivide);

                // IF the user input is valid
                if (multiplyOrDivide == "1" || multiplyOrDivide == "2") {
                    // Does not repeat the question and exits loop
                    break;
                }
            }

            // Asks user for their list of integers
            std::cout << "Enter a list of integers separated by spaces: ";
            std::getline(std::cin, userListString);

            // Initialize Variable
            numberString = "";

            // Iterates through each character in the user's string
            for (auto iterator : userListString) {
                // Checks for spaces in the input to determine each element
                if (iterator == ' ') {
                    // Adds the integer to list
                    userList.push_back(numberString);

                    // Resets placeholder variable
                    numberString = "";

                // IF there was not a space in the string yet
                } else {
                    // Adds the character to placeholder variable
                    numberString = numberString + iterator;
                }
            }
            // Adds last element to the list as there is not a space after it
            userList.push_back(numberString);

            // Checks for exceptions
            try {
                // Iterates through each index in the list
                for (auto index : userList) {
                    // Casts the index of the list to an integer
                    elementInt = stoi(index);

                    // Casts the index of the list to a float
                    elementFloat = stof(index);

                    // Checks if the element is not an integer
                    if (elementFloat != elementInt) {
                        // Displays invalid input message
                        std::cout << "You must enter a list of integers "
                                  << "separated by single spaces!" << std::endl;

                        // Sets invalidList variable to true so
                        // that the program does not continue
                        invalidList = true;

                        // Breaks out of loop and user will be asked
                        // if they want to run the program again
                        break;

                    // IF element is a valid integer
                    } else {
                        userListInt.push_back(elementInt);
                    }
                }

                // IF the user's list of integers is valid
                if (!invalidList) {
                    // Checks for exceptions
                    try {
                        // IF the user wants to multiply
                        // every element in the list
                        if (multiplyOrDivide == "1") {
                            // Asks user for their multiplier
                            std::cout << "Enter a multiplier: ";
                            std::getline(std::cin, userMultiplierString);

                            // Casts multiplier to a float
                            userMultiplier = stof(userMultiplierString);

                        // IF the user wants to divide each element in the list
                        } else {
                            // Ensures that the program will
                            // not continue if the divisor is 0
                            while (userDivisor != 0) {
                                // Asks the user for their divisor
                                std::cout << "Enter a divisor: ";
                                std::getline(std::cin, userDivisorString);

                                // Casts the divisor to a float
                                userDivisor = stof(userDivisorString);

                                // IF the user inputted 0 as the divisor
                                if (userDivisor == 0) {
                                    // Displays to user error message
                                    std::cout << "You cannot have 0 as your "
                                              << "divisor!" << std::endl;

                                    // Sets invalidDivisor to true
                                    invalidDivisor = true;

                                    // Returns to the beginning
                                    // of the loop/resets program
                                    continue;

                                // IF the divisor is valid
                                } else {
                                    // Exits the loop
                                    break;
                                }
                            }
                        }

                        // IF the user wants to multiply
                        // the elements in the list
                        if (multiplyOrDivide == "1") {
                            // Calls function multiply each integer in the list
                            listMultiplied = ListMultiplier(userListInt,
                                                            userMultiplier);

                            // Displays the list with all elements multiplied
                            std::cout << "The product of each element "
                                      <<"with the multiplier is: ";
                            // Iterates and displays each index to console
                            for (float number : listMultiplied) {
                                std::cout << number << " ";
                            }
                            std::cout << std::endl;
                        // IF the user wants to divides each element in the list
                        } else {
                            // IF the user's divisor is not 0/valid
                            if (!invalidDivisor) {
                                // Calls function to divide
                                // each element in the list
                                listDivided = ListDivisor(userListInt,
                                                            userDivisor);

                                // Displays the list with all elements divided
                                std::cout << "The quotient of each element"
                                          << "with the divisor is: ";
                                // Iterates and displays each index of the list
                                for (float number : listDivided) {
                                    std::cout << number << " ";
                                }
                                std::cout << std::endl;
                            }
                        }
                    // In the event of an exception
                    // occurring with the multiplier or divisor
                    } catch (std::invalid_argument) {
                        std::cout << "You must enter a number for the "
                        << "multiplier/divisor!"
                        << "(0 is not allowed for the divisor)"
                        << std::endl;
                    }
                }
            // In the event of an exception occurring with the list of integers
            } catch (std::exception) {
                std::cout << "You must enter a list of integers separated"
                << "by single spaces!"<< std::endl;
            }
        // IF the user wants to find the common/uncommon elements of 2 lists
        } else if (multiplierOrCommon == "2") {
            // Repeats user input until user enters 1 or 2
            while (commonOrUncommon != "1" || commonOrUncommon != "2") {
                // Asks user if they want to find the common
                // or uncommon elements of two lists
                std::cout << "\nDo you want to find the common"
                << "or uncommon elements of two lists?"
                << "\n(Enter '1' for the common elements or"
                << "enter '2' for the uncommon elements): ";
                std::getline(std::cin, commonOrUncommon);

                // IF the user enters valid input
                if (commonOrUncommon == "1" || commonOrUncommon == "2") {
                    break;
                }
            }

            // Asks user for their first list of elements
            std::cout << "Enter a list of elements separated by spaces: ";
            std::getline(std::cin, userListString);

            // Initialize placeholder variable
            elementString = "";

            // Iterates through each character in the
            // user's string to make it a list
            for (auto iterator : userListString) {
                // Checks for spaces to determine each index
                if (iterator == ' ') {
                    // Adds the element to the user's first list
                    userList.push_back(elementString);

                    // Resets placeholder variable
                    elementString = "";

                // IF there are no spaces in the character
                } else {
                    // Adds the character to the placeholder variable
                    elementString = elementString + iterator;
                }
            }
            // Adds last element to the first list
            userList.push_back(elementString);

            // Asks user for their second list of elements
            std::cout << "Enter another list of elements separated by spaces: ";
            std::getline(std::cin, secondUserListString);

            // Initialize placeholder variable
            secondElementString = "";
            // Iterates through each character in the
            // user's string to make it a list
            for (auto secondIterator : secondUserListString) {
                // Checks for spaces to determine each index
                if (secondIterator == ' ') {
                    // Adds the element to the user's first list
                    secondUserList.push_back(secondElementString);

                    // Resets second placeholder variable
                    secondElementString = "";
                // IF the character is not a space
                } else {
                    // Adds the character to the placeholder variable
                    secondElementString = secondElementString + secondIterator;
                }
            }
            // Adds last element to the user's second list
            secondUserList.push_back(secondElementString);

            // IF the user wanted to find the common elements
            if (commonOrUncommon == "1") {
                // Calls function to find the common elements
                userCommonElements = CommonElements(userList, secondUserList);

                // Checks if the list is empty/there were no common elements
                if (userCommonElements.size() == 0) {
                    // Displays to user that there were no common elements
                    std::cout << "These two lists have no common elements!"
                    << std::endl;
                // If there were common elements in the list
                } else {
                    // Displays to user the common elements
                    std::cout << "The common elements of the two lists are: ";
                    // Iterates and displays each common element
                    for (std::string element : userCommonElements) {
                        std::cout << element << " ";
                    }
                    std::cout << std::endl;
                }
            // IF the user wanted to find the uncommon elements
            } else {
                // Calls function to find the uncommon elements
                userUncommonElements = UncommonElements(userList,
                                                        secondUserList);

                // Checks if the list is empty/there were no uncommon elements
                if (userUncommonElements.size() == 0) {
                    // Displays to user that
                    // there were no uncommon elements
                    std::cout << "These two lists have no uncommon elements!"
                    << std::endl;
                // IF there were uncommon elements
                } else {
                    // Displays to user the uncommon elements of the two lists
                    std::cout << "The uncommon elements of the two lists are: ";

                    // Iterates and displays each
                    // uncommon element on the same line
                    for (std::string element : userUncommonElements) {
                        std::cout << element << " ";
                    }
                    std::cout << std::endl;
                }
            }
        }

        // Asks user if they want the program to repeat
        std::cout << "\nDo you want to repeat the program?"
        << "(Enter '1' to repeat the program or '2' to end it): ";
        std::getline(std::cin, yesOrNo);
        std::cout << std::endl;

        // IF the user wants to end the program
        if (yesOrNo == "2") {
            // Ends loop
            userRepeat = true;

            // Exits loop, ending program
            break;
        }
    }
}
