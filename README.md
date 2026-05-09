# Career Guidance System

A terminal-based career counselling application built in C++ that guides students through personalized, adaptive quizzes to recommend streams, degrees, and career paths based on their interests and goals.

## Overview

This project demonstrates core Object-Oriented Programming concepts in C++ through a practical, real-world application. Students at different stages — after 10th, after 12th, or anyone exploring their passions — receive tailored career recommendations via branching quiz logic.

## Features

- Adaptive/branching quiz — answers determine the next question, not a fixed linear flow
- Three distinct quiz modes for different user situations
- Personalized career roadmaps with salary ranges, timelines, and top companies
- Hobby-to-career conversion with monetization strategies and learning plans
- 10 hobby categories and 4 stream categories with detailed career data
- Activity logging via `journal.log`

## OOP Concepts Demonstrated

| Concept | Where Used |
|---|---|
| Abstract base class with pure virtual functions | `Quiz` class |
| Single Inheritance | `AgeBasedQuiz` from `Quiz` |
| Multilevel Inheritance | `QuizFor10th` and `QuizFor12th` from `AgeBasedQuiz` |
| Hierarchical Inheritance | `InterestBasedQuiz` from `Quiz` |
| Multiple Inheritance | `HobbyQuiz` from `InterestBasedQuiz` and `QuizFormatter` |
| Operator Overloading | `QuizScore` (`+`, `+=`, `>`, `==`) |
| Polymorphism (runtime) | Base class pointer `Quiz*` calls overridden `conductQuiz()` |
| Encapsulation | Private members with public getters across all classes |
| Structs for data modeling | `Career`, `Hobby` |
| STL containers | `map`, `vector` for career and hobby databases |

## Project Structure

```
CareerGuidanceSystem/
├── main.cpp          # All classes, logic, and entry point
└── README.md
```

## Quiz Modes

**Mode 1 — Stream Selection (After 10th)**
Recommends one of four streams based on adaptive questions:
- PCM — Engineering, Technology, Science
- PCB — Medical, Healthcare, Life Sciences
- Commerce — Business, Finance, Accounting
- Humanities/Arts — Law, Journalism, Civil Services

**Mode 2 — Career Selection (After 12th)**
Recommends a career path based on interest and goals:
- Software Engineer / Data Scientist
- Civil / Mechanical / Electrical Engineer
- Medical Doctor (MBBS/MD)
- Entrepreneur / Business Manager
- Creative Professional

**Mode 3 — Passion to Profession (Interest-Based)**
Selects from 10 hobby categories and provides a fully personalized profile including skill level, daily schedule, milestones, monetization strategies, and learning resources.

Available hobbies: Programming, Writing, Photography, Music Production, Drawing, Game Design, Science/Research, Entrepreneurship, Teaching, Data Analysis.

## How to Compile and Run

**Requirements:** Any C++11 or later compiler (g++, MSVC, clang++)

**Using g++ (Linux / Mac / Windows with MinGW):**
```bash
g++ -std=c++11 -o career_guidance main.cpp
./career_guidance
```

**Using MSVC (Windows):**
```bash
cl /EHsc main.cpp
career_guidance.exe
```

**Using an IDE:** Open `main.cpp` in Code::Blocks, Dev-C++, or Visual Studio and build/run directly.

## Sample Interaction

```
╔════════════════════════════════════════════════╗
║    PERSONALIZED CAREER GUIDANCE SYSTEM         ║
║        Your Future, Your Questions!            ║
╚════════════════════════════════════════════════╝

Choose your situation:

1. I'm in 10th class - Help choose stream
2. I'm after 12th class - Help choose career
3. Help explore my interests & passions
4. Exit

Enter choice (1/2/3/4): 1

Q1. What excites you the most?
   a) Technology, Engineering, Building solutions
   b) Healthcare, Medicine, Helping patients
   ...
```

## Inheritance Hierarchy

```
Quiz  (Abstract Base)
│
├── AgeBasedQuiz  (Single Inheritance)
│   ├── QuizFor10th  (Multilevel Inheritance)
│   └── QuizFor12th  (Multilevel Inheritance)
│
└── InterestBasedQuiz  (Hierarchical Inheritance)
    └── HobbyQuiz  (Multiple Inheritance — also inherits QuizFormatter)

QuizFormatter  (Mixin)
└── HobbyQuiz
```

## Notes

- `system("pause")` and `system("cls")` are Windows-specific. On Linux/Mac, replace with `cin.get()` and `system("clear")` respectively.
- The project is intentionally single-file for ease of submission and review. In production, each class would be split into its own `.h` and `.cpp` files.

## Authors

Built as a college project to demonstrate C++ OOP principles through a practical career counselling application.
