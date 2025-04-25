---
title: Notes on Account.cpp Implementation
type: note
permalink: /home/alramire/sgoinfre/cpp/cpp-git/ex02/notes-on-account-cpp-implementation
tags:
- '#C++'
- '#Account'
- '#Implementation'
- '#Learning'
---

In our discussion about implementing the Account.cpp file, I learned that static methods in C++ can only access static variables, not instance members. This realization helped me understand how to correctly implement the displayAccountsInfos() method to reflect the correct output based on the static class members. 

We also talked about the constructor for the Account class, which should initialize the instance variables based on the initial deposit provided. I recognized that I need to properly define the constructor with the class name and parameter type, and initialize the relevant member variables. Additionally, I noted that the timestamp output in the log file is likely handled by a separate method, _displayTimestamp(). 

Overall, I feel more confident in distinguishing between static and instance members and how to implement class methods correctly in C++.