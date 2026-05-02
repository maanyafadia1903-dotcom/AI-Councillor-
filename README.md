# Career Guider: Adaptive Career Guidance System

A multi-platform personalized career counseling suite designed to help students navigate critical academic transitions and transform personal interests into professional roadmaps[cite: 6, 7]. The project features a robust **C++ backend** utilizing advanced Object-Oriented Programming (OOP) and a modern **web-based frontend** powered by Claude AI for deep analysis[cite: 6, 7].

---

## 🌟 Key Features

### 1. Adaptive Questioning Engine
*   **Dynamic Pathfinding**: Questions evolve based on previous answers. For example, selecting a "Science" interest in the 10th-grade quiz triggers specific inquiries about Math comfort and lab preferences[cite: 6, 7].
*   **Weighted Scoring**: Uses custom operator overloading in C++ to compute stream recommendations (PCM, PCB, Commerce, Arts) based on cumulative interest scores[cite: 7].

### 2. Specialized Guidance Modes
*   **10th Grade Stream Selection**: Analyzes primary interests and technical comfort to recommend the ideal 11th-grade stream[cite: 6, 7].
*   **Post-12th Career Navigator**: Provides detailed industry roadmaps for Engineering, Medicine, IT, Business, and Creative fields, including entry-level salary expectations in India[cite: 6, 7].
*   **Passion-to-Profession (Hobby) Roadmap**: Converts hobbies like Coding, Gaming, or Photography into actionable 5-year career timelines with specific monetization strategies[cite: 6, 7].

### 3. AI-Powered Personalization
*   **Claude AI Integration**: (Frontend) Generates real-time, deep-analysis reports including identified strengths, unique market advantages, and "Watch Out" pitfalls tailored to the user's quiz profile[cite: 6].
*   **Success Formulas**: Generates personalized daily routines and success equations based on the user's available daily hours and ultimate career goals[cite: 6, 7].

---

## 🛠️ Technical Architecture

### C++ Backend Implementation
The backend leverages a sophisticated class hierarchy to manage complex quiz logic[cite: 7]:
*   **Polymorphism**: Uses virtual functions and base class pointers (`Quiz*`) to execute different quiz types at runtime[cite: 7].
*   **Inheritance Models**:
    *   **Multilevel**: `Quiz` → `AgeBasedQuiz` → `QuizFor10th`[cite: 7].
    *   **Multiple**: `HobbyQuiz` inherits from both `InterestBasedQuiz` and `QuizFormatter` (Mixin)[cite: 7].
    *   **Hierarchical**: Multiple specialized quizzes branching from a single `InterestBasedQuiz` base[cite: 7].

### Web Frontend Implementation
*   **Responsive UI**: Built with a "Mobile-First" approach using CSS glassmorphism, adaptive orbs, and fluid animations[cite: 6].
*   **State Management**: Tracks user history to allow "Back" navigation through dynamically injected adaptive question flows[cite: 6].

---

## 📂 Project Structure

```text
├── career_guider.cpp      # C++ Source: OOP-driven quiz engine and database
├── index.html             # Web UI: Interactive adaptive quiz interface
└── performance_assets/    # Visual assets and design tokens
```

---

## 🚀 Getting Started

### Running the C++ Application
1.  Compile the source code:
    ```bash
    g++ career_guider.cpp -o CareerGuider
    ```
2.  Launch the terminal-based interactive system:
    ```bash
    ./CareerGuider
    ```

### Using the Web Interface
1.  Open `index.html` in any modern web browser[cite: 6].
2.  Select your current academic status to begin the adaptive session[cite: 6].
3.  (Optional) Connect to the internet to enable the **Claude AI Deep Analysis** feature[cite: 6].

---

## 📊 Sample Output: Passion Roadmap
For a student interested in **Programming**, the system provides[cite: 6, 7]:
*   **Top Careers**: Software Engineer, Data Scientist, Cybersecurity Specialist[cite: 6, 7].
*   **Daily Routine**: 30m concept learning, 1h+ hands-on practice, 30m review[cite: 6, 7].
*   **Success Formula**: Consistency + Quality Learning + Clear Goal = Dream Career[cite: 6, 7].
```
