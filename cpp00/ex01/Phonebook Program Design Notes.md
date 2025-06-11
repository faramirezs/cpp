---
title: Phonebook Program Design Notes
type: note
permalink: /home/alramire/sgoinfre/cpp/cpp-git/ex01/phonebook-program-design-notes-1
tags:
- '#C++'
- '#OOP'
- '#Phonebook'
- '#Class Design'
---

### Phonebook Program Design Notes

#### Class Design Principles
- **Classes vs. Structs**: In C++, classes are similar to structs in C, but classes have private members by default, while structs have public members. This encapsulation allows us to group data and methods while restricting direct access to some members.

#### Contact Class
- **Data Members**: The `contactClass` includes the following private data members:
  - `int id;`
  - `std::string fname;`
  - `std::string lname;`
  - `std::string secret;`
  - `std::string nname;`
  - `int phone;`

- **Constructor**: The constructor initializes the contact's data members. It takes parameters for each member:
  ```cpp
  contactClass(std::string fnm, std::string lnm, std::string scrt, int ide, std::string nnm, int phn) {
      id = ide;
      fname = fnm;
      lname = lnm;
      secret = scrt;
      nname = nnm;
      phone = phn;
  }
  ```

#### Main Function
- **Creating a Contact Object**: In the `main()` function, I create a contact object:
  ```cpp
  contactClass contactObj1("Alejo", "Ram", "NA", 1, "alejiri", 123456);
  ```

- **Accessing Private Members**: I attempted to access private members directly:
  ```cpp
  cout << contactObj1.id << " " << contactObj1.fname << " " << contactObj1.phone << "\n";
  ```
  This is not allowed since `id`, `fname`, and `phone` are private. I need to create public methods to access this information.

#### Next Steps
- **Public Methods**: I need to add methods to the `contactClass` to:
  - Retrieve individual fields (like first name, phone number).
  - Display contact information in a formatted way.

- **Include Necessary Headers**: Ensure to include `<iostream>` and `<string>` for proper functionality.

### Reflection
This process has helped me understand the importance of encapsulation in OOP and how to structure my classes effectively. I need to focus on creating a proper interface for my classes to allow controlled access to their data.