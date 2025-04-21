---
title: Phonebook Program Design
type: note
permalink: /sgoinfre/goinfre/perso/alramire/cpp/cpp-git/ex01/phonebook-program-design
tags:
- '#phonebook'
- '#design'
- '#cpp'
---

## Phonebook Program Design

### Overview
The Phonebook program is designed to manage contacts, allowing users to add and search for contacts. The program utilizes two classes: `contact` and `phonebook`.

### Class Definitions
1. **Contact Class**: This class represents an individual contact with attributes such as first name, last name, nickname, phone number, and a secret. It includes:
   - A default constructor to initialize the contact with default values.
   - A parameterized constructor to create a contact with specific details.
   - Getter methods to retrieve contact information.
   - A method to display the contact's details.

2. **Phonebook Class**: This class manages an array of `contact` objects. It includes:
   - An array to store up to 8 contacts.
   - A method to add a new contact, which checks if the phonebook is full and overwrites the oldest contact if necessary.
   - A method to search for contacts, displaying their details in a formatted table.

### User Input Handling
- The program prompts the user for commands (ADD, SEARCH, EXIT) and processes input accordingly.
- When adding a contact, the program collects user input for each attribute. It includes error handling for the phone number input to ensure it is numeric.

### Output Formatting
- The program uses `std::setw()` for formatting output in the search results, ensuring that each column is aligned properly. Text is aligned to the left using `std::left`.
- If any attribute exceeds 9 characters, it is truncated and appended with a dot to indicate continuation.

### Future Improvements
- Implement additional error handling for user inputs to enhance robustness.
- Consider adding features like editing or deleting contacts in the future.