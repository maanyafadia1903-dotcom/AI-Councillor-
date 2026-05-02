#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;

// Structure to hold career information
struct Career {
    string jobTitle;
    string description;
    vector<string> skills;
    int yearsRequired;
    vector<string> streams;
    vector<string> subjects;
};

// Structure to hold hobby information
struct Hobby {
    string name;
    string description;
    vector<string> relatedCareers;
    vector<string> howToLearn;
    int dailyHoursRequired;
};

// ========== INHERITANCE & POLYMORPHISM CLASSES ==========

// QuizScore class with operator overloading (Polymorphism)
class QuizScore {
private:
    int score;
public:
    QuizScore(int s = 0) : score(s) {}
    QuizScore operator+(int points) { return QuizScore(score + points); }
    QuizScore operator+=(int points) { score += points; return *this; }
    bool operator>(const QuizScore& other) const { return score > other.score; }
    bool operator==(const QuizScore& other) const { return score == other.score; }
    int getScore() const { return score; }
};

// ===== BASE CLASS - Quiz (defines interface) =====
class Quiz {
protected:
    string quizType;
public:
    virtual int conductQuiz() = 0;
    virtual void displayHeader() = 0;
    virtual ~Quiz() {}
};

// ===== SINGLE INHERITANCE - AgeBasedQuiz from Quiz =====
class AgeBasedQuiz : public Quiz {
protected:
    string ageGroup;
public:
    AgeBasedQuiz(string age) : ageGroup(age) { quizType = "Age-Based"; }
    void displayHeader() override {
        cout << "\n╔════════════════════════════════════════════════╗\n";
    }
};

// ===== MULTILEVEL INHERITANCE - QuizFor10th from AgeBasedQuiz =====
class QuizFor10th : public AgeBasedQuiz {
public:
    QuizFor10th() : AgeBasedQuiz("10th Grade") {}
    int conductQuiz() override;
    void displayHeader() override;
};

// ===== MULTILEVEL INHERITANCE - QuizFor12th from AgeBasedQuiz =====
class QuizFor12th : public AgeBasedQuiz {
public:
    QuizFor12th() : AgeBasedQuiz("12th Grade") {}
    int conductQuiz() override;
    void displayHeader() override;
};

// ===== HIERARCHICAL INHERITANCE - InterestBasedQuiz from Quiz =====
class InterestBasedQuiz : public Quiz {
protected:
    Hobby selectedHobby;
public:
    InterestBasedQuiz() { quizType = "Interest-Based"; }
    void displayHeader() override;
};

// ===== MIXIN CLASS for Formatting =====
class QuizFormatter {
public:
    void displayBoxedMessage(string title) {
        cout << "\n╔════════════════════════════════════════════════╗\n";
        cout << "║ " << title << "\n";
        cout << "╚════════════════════════════════════════════════╝\n\n";
    }
};

// ===== MULTIPLE INHERITANCE - HobbyQuiz from InterestBasedQuiz and QuizFormatter =====
class HobbyQuiz : public InterestBasedQuiz, public QuizFormatter {
public:
    HobbyQuiz() {}
    int conductQuiz() override;
    void displayHeader() override;
};

// Career database
map<string, Career> careerDatabase;
vector<Hobby> hobbyDatabase;

// Function to initialize career database
void initializeCareerDatabase() {
    careerDatabase["PCM"] = {
        "Engineering/Science Stream",
        "Physics, Chemistry, Mathematics focus",
        {"Physics", "Chemistry", "Mathematics", "Computer Science", "Electronics"},
        4,
        {"Engineering", "Science", "Technology"},
        {"Physics", "Chemistry", "Mathematics"}
    };

    careerDatabase["PCB"] = {
        "Medical/Biology Stream",
        "Physics, Chemistry, Biology focus",
        {"Biology", "Chemistry", "Physics", "Medical Knowledge", "Laboratory Skills"},
        5,
        {"Medical", "Biology", "Healthcare"},
        {"Physics", "Chemistry", "Biology"}
    };

    careerDatabase["Commerce"] = {
        "Business/Commerce Stream",
        "Mathematics, Accounting, Economics focus",
        {"Accounting", "Economics", "Business Management", "Finance", "Taxation"},
        3,
        {"Commerce", "Business", "Finance"},
        {"Accounting", "Economics", "Business Studies"}
    };

    careerDatabase["Humanities"] = {
        "Arts/Humanities Stream",
        "History, Geography, Literature focus",
        {"Writing", "Research", "Communication", "Critical Thinking", "History Knowledge"},
        3,
        {"Arts", "Social Sciences", "Humanities"},
        {"History", "Geography", "Literature"}
    };
}

// Function to initialize hobby database
void initializeHobbyDatabase() {
    hobbyDatabase.push_back({
        "Programming/Coding",
        "Writing code to solve problems and build applications",
        {"Software Engineer", "Web Developer", "Data Scientist", "Game Developer", "Cybersecurity Specialist"},
        {"Online courses (Udemy, Coursera)", "GitHub projects", "LeetCode problems", "Documentation reading", "Building projects"},
        2
    });

    hobbyDatabase.push_back({
        "Writing/Blogging",
        "Creating written content and stories",
        {"Content Writer", "Journalist", "Novelist", "Technical Writer", "Marketing Specialist"},
        {"Read widely", "Write daily", "Join writing communities", "Take writing courses", "Get feedback"},
        1
    });

    hobbyDatabase.push_back({
        "Photography/Videography",
        "Capturing moments and creating visual stories",
        {"Photographer", "Videographer", "Content Creator", "Cinematographer", "UI/UX Designer"},
        {"Photography courses", "Practice daily", "Study composition", "Build portfolio", "Networking"},
        2
    });

    hobbyDatabase.push_back({
        "Music/Production",
        "Creating music and audio content",
        {"Musician", "Music Producer", "Audio Engineer", "Sound Designer", "Composer"},
        {"Music theory courses", "Practice instrument", "Digital Audio Workstation", "Collaboration", "Performance"},
        3
    });

    hobbyDatabase.push_back({
        "Drawing/Painting",
        "Creating visual art through drawing or painting",
        {"Graphic Designer", "Illustrator", "Artist", "Animator", "Concept Artist"},
        {"Art courses", "Daily practice", "Study anatomy", "Color theory", "Online communities"},
        2
    });

    hobbyDatabase.push_back({
        "Gaming/Game Design",
        "Playing games and creating game content",
        {"Game Developer", "Game Designer", "Esports Manager", "Content Creator", "UI/UX Designer"},
        {"Game engines (Unity, Unreal)", "Game design courses", "Modding", "Prototyping", "Playtesting"},
        3
    });

    hobbyDatabase.push_back({
        "Science/Research",
        "Conducting experiments and discovering new things",
        {"Scientist", "Research Scientist", "Astronomer", "Biologist", "Data Scientist"},
        {"Online science courses", "Research papers", "Laboratory practice", "MOOC platforms", "Scientific forums"},
        2
    });

    hobbyDatabase.push_back({
        "Entrepreneurship",
        "Building and running business ventures",
        {"Entrepreneur", "Business Owner", "Startup Founder", "Consultant", "Product Manager"},
        {"Business courses", "Networking", "Market research", "Mentorship", "Financial planning"},
        2
    });

    hobbyDatabase.push_back({
        "Teaching/Mentoring",
        "Teaching others and sharing knowledge",
        {"Teacher", "Tutor", "Educator", "Trainer", "Coach"},
        {"Teaching certification", "Subject expertise", "Communication training", "Practice", "Feedback"},
        2
    });

    hobbyDatabase.push_back({
        "Data Analysis/Statistics",
        "Analyzing data and finding patterns",
        {"Data Analyst", "Data Scientist", "Business Analyst", "Statistician", "BI Developer"},
        {"Statistics courses", "SQL/Python/R", "Tableau/Power BI", "Excel mastery", "Real-world projects"},
        2
    });
}

// ===== IMPLEMENTATION: QuizFor10th (Multilevel Inheritance) =====
void QuizFor10th::displayHeader() {
    cout << "\n╔════════════════════════════════════════════════╗\n";
    cout << "║  PERSONALIZED STREAM SELECTION QUIZ            ║\n";
    cout << "║ (Questions adapt based on your answers)        ║\n";
    cout << "╚════════════════════════════════════════════════╝\n\n";
}

int QuizFor10th::conductQuiz() {
    displayHeader();

    QuizScore scienceScore(0), biologyScore(0), commerceScore(0), artScore(0);
    string primaryPath = "";
    char choice;

    // QUESTION 1 - Initial interest determines all future questions
    cout << "Q1. What excites you the most?\n";
    cout << "   a) Technology, Engineering, Building solutions\n";
    cout << "   b) Healthcare, Medicine, Helping patients\n";
    cout << "   c) Business, Money, Economics\n";
    cout << "   d) Society, Culture, History, Writing\n\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 'a') {
        scienceScore += 5;
        primaryPath = "science";
    } else if (choice == 'b') {
        biologyScore += 5;
        primaryPath = "biology";
    } else if (choice == 'c') {
        commerceScore += 5;
        primaryPath = "commerce";
    } else if (choice == 'd') {
        artScore += 5;
        primaryPath = "arts";
    }

    // ADAPTIVE QUESTIONS 2-3 (ONLY RELEVANT QUESTIONS ASKED)
    if (primaryPath == "science") {
        cout << "\nQ2. In tech/engineering, your focus?\n";
        cout << "   a) Software and applications\n";
        cout << "   b) Machines and infrastructure\n";
        cout << "   c) Both interest me\n\n";
        cout << "Your choice: ";
        cin >> choice;
        scienceScore += 2;

        cout << "\nQ3. Your Math comfort level?\n";
        cout << "   a) Excellent - I love it\n";
        cout << "   b) Good - can handle it\n";
        cout << "   c) Average - it's challenging\n\n";
        cout << "Your choice: ";
        cin >> choice;
        if (choice == 'a') scienceScore += 3;
        else if (choice == 'b') scienceScore += 2;

    } else if (primaryPath == "biology") {
        cout << "\nQ2. What aspect interests you?\n";
        cout << "   a) Human body and health\n";
        cout << "   b) Living organisms and nature\n";
        cout << "   c) Both\n\n";
        cout << "Your choice: ";
        cin >> choice;
        biologyScore += 2;

        cout << "\nQ3. Comfortable with lab experiments?\n";
        cout << "   a) Yes, enjoy practical work\n";
        cout << "   b) Prefer theory\n";
        cout << "   c) Either is fine\n\n";
        cout << "Your choice: ";
        cin >> choice;
        if (choice == 'a' || choice == 'c') biologyScore += 2;

    } else if (primaryPath == "commerce") {
        cout << "\nQ2. Your business interest?\n";
        cout << "   a) Accounting and Finance\n";
        cout << "   b) Running a business\n";
        cout << "   c) Economics\n\n";
        cout << "Your choice: ";
        cin >> choice;

        cout << "\nQ3. Want to be entrepreneur?\n";
        cout << "   a) Yes, definitely\n";
        cout << "   b) Maybe later\n";
        cout << "   c) Prefer job security\n\n";
        cout << "Your choice: ";
        cin >> choice;
        if (choice == 'a') commerceScore += 3;
        else if (choice == 'b') commerceScore += 2;

    } else if (primaryPath == "arts") {
        cout << "\nQ2. Which humanities subject?\n";
        cout << "   a) Writing and Literature\n";
        cout << "   b) History and Geography\n";
        cout << "   c) Social issues\n\n";
        cout << "Your choice: ";
        cin >> choice;
        artScore += 2;

        cout << "\nQ3. Professional courses later?\n";
        cout << "   a) Yes - Law or Civil Services\n";
        cout << "   b) Maybe\n";
        cout << "   c) Just enjoy humanities\n\n";
        cout << "Your choice: ";
        cin >> choice;
        if (choice == 'a') artScore += 3;
        else if (choice == 'b') artScore += 2;
    }

    // FINAL COMMON QUESTION
    cout << "\nQ4. Preferred work environment?\n";
    cout << "   a) Hands-on practical\n";
    cout << "   b) Office analytical\n";
    cout << "   c) With people\n\n";
    cout << "Your choice: ";
    cin >> choice;

    if (primaryPath == "science" && (choice == 'a' || choice == 'b')) scienceScore += 2;
    else if (primaryPath == "biology" && choice == 'a') biologyScore += 2;
    else if (primaryPath == "commerce" && choice == 'b') commerceScore += 2;
    else if (primaryPath == "arts" && choice == 'c') artScore += 2;

    // SHOW RESULTS
    int maxScore = max({scienceScore.getScore(), biologyScore.getScore(), commerceScore.getScore(), artScore.getScore()});

    cout << "\n╔════════════════════════════════════════════════╗\n";
    cout << "║       ✓ YOUR STREAM RECOMMENDATION             ║\n";
    cout << "╚════════════════════════════════════════════════╝\n\n";

    if (scienceScore == maxScore) {
        cout << "RECOMMENDED: PCM (Physics, Chemistry, Mathematics)\n\n";
        cout << "Best for: Engineering, Technology, Science\n";
        cout << "Careers: Software Engineer, Data Scientist, Civil Engineer, Aerospace Engineer\n";
        cout << "Salary: 8-15 LPA (Entry) to 25-50+ LPA (Senior)\n";
        cout << "Roadmap: 11th-12th PCM -> JEE Exam -> B.Tech (4 years) -> Industry\n";
        cout << "Time: 4-6 years degree + 2-3 years to expertise\n";
        return 0;
    } else if (biologyScore == maxScore) {
        cout << "RECOMMENDED: PCB (Physics, Chemistry, Biology)\n\n";
        cout << "Best for: Medical, Healthcare, Life Sciences\n";
        cout << "Careers: Doctor, Dentist, Pharmacist, Biomedical Engineer\n";
        cout << "Salary: 8-20 LPA (Doctor) with potential for 50-100+ LPA\n";
        cout << "Roadmap: 11th-12th PCB -> NEET Exam -> MBBS (5.5 years) -> Specialization\n";
        cout << "Time: 5-6 years MBBS + 2-3 years specialization\n";
        return 0;
    } else if (commerceScore == maxScore) {
        cout << "RECOMMENDED: Commerce\n\n";
        cout << "Best for: Business, Finance, Accounting\n";
        cout << "Careers: CA, Business Analyst, Finance Manager, Entrepreneur\n";
        cout << "Salary: 8-20 LPA (CA) to 15-25+ LPA (Investment Banking)\n";
        cout << "Roadmap: 11th-12th Commerce -> B.Com/BBA (3-4 years) -> CA/CFA\n";
        cout << "Time: 3-5 years degree + variable specialization\n";
        return 0;
    } else {
        cout << "RECOMMENDED: Humanities/Arts\n\n";
        cout << "Best for: Law, Journalism, Education, Civil Services\n";
        cout << "Careers: Lawyer, Journalist, Teacher, IAS Officer\n";
        cout << "Salary: 6-20 LPA (Lawyer) to 15-56 LPA (IAS Officer)\n";
        cout << "Roadmap: 11th-12th Arts -> B.A (3 years) -> LLB or UPSC\n";
        cout << "Time: 3-5 years degree + variable career development\n";
        return 0;
    }
}

// ===== IMPLEMENTATION: QuizFor12th (Multilevel Inheritance) =====
void QuizFor12th::displayHeader() {
    cout << "\n╔════════════════════════════════════════════════╗\n";
    cout << "║   PERSONALIZED CAREER GUIDANCE QUIZ            ║\n";
    cout << "║  (Smart questions based on your answers)       ║\n";
    cout << "╚════════════════════════════════════════════════╝\n\n";
}

int QuizFor12th::conductQuiz() {
    displayHeader();

    char choice;
    string careerPath = "";

    // QUESTION 1 - Determines entire quiz path
    cout << "Q1. What excites you MOST?\n";
    cout << "   a) Building & designing solutions\n";
    cout << "   b) Helping people and healthcare\n";
    cout << "   c) Problem-solving with technology\n";
    cout << "   d) Business and entrepreneurship\n";
    cout << "   e) Creative work (art, design, writing)\n\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 'a') careerPath = "engineer";
    else if (choice == 'b') careerPath = "doctor";
    else if (choice == 'c') careerPath = "it";
    else if (choice == 'd') careerPath = "business";
    else if (choice == 'e') careerPath = "creative";

    // ADAPTIVE QUESTIONS 2-3 (ONLY FOR SELECTED PATH)
    if (careerPath == "engineer") {
        cout << "\nQ2. Which engineering field?\n";
        cout << "   a) Software/Computer\n";
        cout << "   b) Civil/Infrastructure\n";
        cout << "   c) Mechanical\n";
        cout << "   d) Electronics\n\n";
        cout << "Your choice: ";
        cin >> choice;

        cout << "\nQ3. Salary importance?\n";
        cout << "   a) Very important (8+ LPA)\n";
        cout << "   b) Moderate\n";
        cout << "   c) Growth matters more\n\n";
        cout << "Your choice: ";
        cin >> choice;

    } else if (careerPath == "doctor") {
        cout << "\nQ2. What draws you to medicine?\n";
        cout << "   a) Helping patients\n";
        cout << "   b) Human body interest\n";
        cout << "   c) Prestige\n\n";
        cout << "Your choice: ";
        cin >> choice;

        cout << "\nQ3. Ready for 5+ years MBBS?\n";
        cout << "   a) Absolutely committed\n";
        cout << "   b) If salary is good\n";
        cout << "   c) Want something quicker\n\n";
        cout << "Your choice: ";
        cin >> choice;

    } else if (careerPath == "it") {
        cout << "\nQ2. IT specialty interest?\n";
        cout << "   a) Web Development\n";
        cout << "   b) Data Science/AI\n";
        cout << "   c) App Development\n";
        cout << "   d) Cybersecurity\n\n";
        cout << "Your choice: ";
        cin >> choice;

        cout << "\nQ3. Mathematics strength?\n";
        cout << "   a) Excellent\n";
        cout << "   b) Good\n";
        cout << "   c) Weak\n\n";
        cout << "Your choice: ";
        cin >> choice;

    } else if (careerPath == "business") {
        cout << "\nQ2. Business interest?\n";
        cout << "   a) Start own venture\n";
        cout << "   b) Corporate management\n";
        cout << "   c) Finance/Investment\n\n";
        cout << "Your choice: ";
        cin >> choice;

        cout << "\nQ3. Risk tolerance?\n";
        cout << "   a) High - willing to risk\n";
        cout << "   b) Medium - balanced\n";
        cout << "   c) Low - prefer stability\n\n";
        cout << "Your choice: ";
        cin >> choice;

    } else if (careerPath == "creative") {
        cout << "\nQ2. Creative field?\n";
        cout << "   a) Graphic Design/UI\n";
        cout << "   b) Writing\n";
        cout << "   c) Photography\n";
        cout << "   d) Animation/Game Art\n\n";
        cout << "Your choice: ";
        cin >> choice;

        cout << "\nQ3. Existing portfolio?\n";
        cout << "   a) Yes, creating already\n";
        cout << "   b) Just starting\n";
        cout << "   c) Planning to start\n\n";
        cout << "Your choice: ";
        cin >> choice;
    }

    // SHOW PERSONALIZED RECOMMENDATION
    cout << "\n╔════════════════════════════════════════════════╗\n";
    cout << "║    ✓ PERSONALIZED CAREER RECOMMENDATION      ║\n";
    cout << "╚════════════════════════════════════════════════╝\n\n";

    if (careerPath == "it") {
        cout << "RECOMMENDED: Software Engineer / Data Scientist\n\n";
        cout << "Description: Develop software, analyze data, solve problems\n";
        cout << "Salary: 6-8 LPA (Entry) to 25-50+ LPA (Senior)\n";
        cout << "Skills: C++, Python, Java, Data Structures, SQL, Git\n";
        cout << "Roadmap: B.Tech CS (4yr) -> Internships -> Coding contests -> Job\n";
        cout << "Time: 4 years degree + 1-2 years skill development\n";
        cout << "Top Companies: Google, Microsoft, Amazon, TCS, Infosys\n";
        return 0;

    } else if (careerPath == "engineer") {
        cout << "RECOMMENDED: Civil/Mechanical/Electrical Engineer\n\n";
        cout << "Description: Design and build infrastructure/machines\n";
        cout << "Salary: 4-6 LPA (Entry) to 18-35 LPA (Senior)\n";
        cout << "Skills: Math, Physics, CAD, Project Management\n";
        cout << "Roadmap: 12th PCM -> JEE -> B.Tech (4yr) -> Industry\n";
        cout << "Time: 4 years degree + 8-10 years to senior position\n";
        cout << "Top Companies: L&T, Reliance, Balfour Beatty\n";
        return 0;

    } else if (careerPath == "doctor") {
        cout << "RECOMMENDED: Medical Doctor (MBBS/MD)\n\n";
        cout << "Description: Healthcare, diagnosis, treatment\n";
        cout << "Salary: 8-15 LPA (Resident) to 50-100+ LPA (Specialist)\n";
        cout << "Skills: Biology, Chemistry, Anatomy, Empathy\n";
        cout << "Roadmap: 12th PCB -> NEET -> MBBS (5.5yr) -> Specialization\n";
        cout << "Time: 5.5 years MBBS + 3 years specialization = 8.5-9 years\n";
        cout << "Note: Competitive NEET exam required\n";
        return 0;

    } else if (careerPath == "business") {
        cout << "RECOMMENDED: Entrepreneur / Business Manager\n\n";
        cout << "Description: Start business, manage companies, lead teams\n";
        cout << "Income: Variable (0 to 25-100+ LPA at profit)\n";
        cout << "Skills: Strategy, Finance, Marketing, Leadership\n";
        cout << "Roadmap: Bachelor's -> Work experience -> Start business\n";
        cout << "Time: 5-10 years to successful business\n";
        cout << "Funding: Angel investors, VC, Government schemes\n";
        return 0;

    } else if (careerPath == "creative") {
        cout << "RECOMMENDED: Creative Professional\n\n";
        cout << "Description: Design, content creation, photography\n";
        cout << "Salary: 20K-50K/project (Freelance) to 8-20 LPA (Employee)\n";
        cout << "Skills: Adobe Suite, Design, Creativity, Portfolio\n";
        cout << "Roadmap: Learn design -> Build portfolio -> Freelance/Agency\n";
        cout << "Time: 6-12 months to start earning\n";
        cout << "Platforms: Fiverr, Upwork, Behance, 99designs\n";
        return 0;
    }
    
    return 0;
}

// ===== IMPLEMENTATION: InterestBasedQuiz and HobbyQuiz (Hierarchical & Multiple Inheritance) =====
void InterestBasedQuiz::displayHeader() {
    cout << "\n╔════════════════════════════════════════════════╗\n";
    cout << "║    PASSION TO PROFESSION DISCOVERY QUIZ       ║\n";
    cout << "║        (Personalized hobby guidance)          ║\n";
    cout << "╚════════════════════════════════════════════════╝\n\n";
}

void HobbyQuiz::displayHeader() {
    displayBoxedMessage("  PASSION TO PROFESSION DISCOVERY QUIZ            ");
}

int HobbyQuiz::conductQuiz() {
    displayHeader();
    cout << "Which hobby interests you the most?\n\n";

    for (int i = 0; i < hobbyDatabase.size(); i++) {
        cout << (i + 1) << ". " << hobbyDatabase[i].name << "\n";
    }

    cout << "\nEnter choice (1-" << hobbyDatabase.size() << "): ";
    int choice;
    cin >> choice;

    if (choice < 1 || choice > (int)hobbyDatabase.size()) {
        cout << "\nInvalid choice!\n";
        return 0;
    }

    selectedHobby = hobbyDatabase[choice - 1];

    // PERSONALIZATION QUESTIONS
    cout << "\n╔════════════════════════════════════════════════╗\n";
    cout << "║      UNDERSTANDING YOUR PASSION BETTER        ║\n";
    cout << "╚════════════════════════════════════════════════╝\n\n";

    char q1, q2, q3, q4;
    int dailyHours = 0;
    string skillLevel = "", goal = "", learningStyle = "";

    // Q1: How long interested?
    cout << "Q1. How long have you been interested in " << selectedHobby.name << "?\n";
    cout << "   a) Just started (0-3 months)\n";
    cout << "   b) Few months (3-6 months)\n";
    cout << "   c) A year or two\n";
    cout << "   d) Many years (2+ years)\n";
    cout << "Your choice: ";
    cin >> q1;

    if (q1 == 'a') skillLevel = "Beginner";
    else if (q1 == 'b') skillLevel = "Beginner-Intermediate";
    else if (q1 == 'c') skillLevel = "Intermediate";
    else skillLevel = "Advanced";

    // Q2: Daily time commitment
    cout << "\nQ2. How many hours daily can you dedicate?\n";
    cout << "   a) 1-2 hours\n";
    cout << "   b) 2-3 hours\n";
    cout << "   c) 3-4 hours\n";
    cout << "   d) 4+ hours\n";
    cout << "Your choice: ";
    cin >> q2;

    if (q2 == 'a') dailyHours = 2;
    else if (q2 == 'b') dailyHours = 3;
    else if (q2 == 'c') dailyHours = 4;
    else dailyHours = 5;

    // Q3: Career goal
    cout << "\nQ3. Your main goal?\n";
    cout << "   a) Just hobby for fun\n";
    cout << "   b) Side income/freelancing\n";
    cout << "   c) Full-time career\n";
    cout << "   d) Master it completely\n";
    cout << "Your choice: ";
    cin >> q3;

    if (q3 == 'a') goal = "Hobby";
    else if (q3 == 'b') goal = "Side Income";
    else if (q3 == 'c') goal = "Full-time Career";
    else goal = "Expertise";

    // Q4: Preferred learning style
    cout << "\nQ4. How do you prefer to learn?\n";
    cout << "   a) Online courses & tutorials\n";
    cout << "   b) Hands-on practice & experimentation\n";
    cout << "   c) Mix of theory and practice\n";
    cout << "   d) Professional mentorship\n";
    cout << "Your choice: ";
    cin >> q4;

    if (q4 == 'a') learningStyle = "Online Courses";
    else if (q4 == 'b') learningStyle = "Hands-on Learning";
    else if (q4 == 'c') learningStyle = "Balanced Approach";
    else learningStyle = "Mentorship";

    // PERSONALIZED RESULTS
    cout << "\n╔════════════════════════════════════════════════╗\n";
    cout << "║   PERSONALIZED HOBBY TO CAREER ROADMAP       ║\n";
    cout << "╚════════════════════════════════════════════════╝\n\n";

    cout << "YOUR PROFILE:\n";
    cout << "  • Hobby: " << selectedHobby.name << "\n";
    cout << "  • Current Level: " << skillLevel << "\n";
    cout << "  • Daily Commitment: " << dailyHours << " hours\n";
    cout << "  • Goal: " << goal << "\n";
    cout << "  • Learning Style: " << learningStyle << "\n\n";

    cout << "HOBBY DESCRIPTION: " << selectedHobby.description << "\n\n";

    cout << "CAREER OPPORTUNITIES:\n";
    for (int i = 0; i < selectedHobby.relatedCareers.size(); i++) {
        cout << "  " << (i + 1) << ". " << selectedHobby.relatedCareers[i] << "\n";
    }

    cout << "\nRECOMMENDED LEARNING PATHS:\n";
    for (int i = 0; i < selectedHobby.howToLearn.size(); i++) {
        cout << "  • " << selectedHobby.howToLearn[i] << "\n";
    }

    cout << "\nPERSONALIZED TIMELINE (" << goal << "):\n";
    if (goal == "Hobby") {
        cout << "  • Month 1-2: Learn basics at your pace\n";
        cout << "  • Month 3-6: Build your first project\n";
        cout << "  • Ongoing: Enjoy and improve gradually\n";
    } else if (goal == "Side Income") {
        cout << "  • Month 1-3: Build foundational skills\n";
        cout << "  • Month 4-6: Create portfolio pieces\n";
        cout << "  • Month 6-12: Start freelancing\n";
        cout << "  • Year 1+: Earn 10,000-50,000/month\n";
    } else if (goal == "Full-time Career") {
        cout << "  • Month 1-6: Master fundamentals\n";
        cout << "  • Month 6-12: Build professional portfolio\n";
        cout << "  • Month 12-18: Apply for jobs/internships\n";
        cout << "  • Year 2+: Establish career (20,000-100,000+/month)\n";
    } else {
        cout << "  • Year 1: Learn deeply, build 5+ projects\n";
        cout << "  • Year 2: Specialize in niche area\n";
        cout << "  • Year 3-5: Become expert, mentor others\n";
        cout << "  • Year 5+: Industry leader status\n";
    }

    cout << "\nDAILY ROUTINE SUGGESTION (" << dailyHours << " hours):\n";
    cout << "  • 30 mins: Learn new concepts\n";
    cout << "  • " << (dailyHours - 1) << " hours: Hands-on practice\n";
    cout << "  • 30 mins: Review & community engagement\n";

    cout << "\nMILESTONES TO ACHIEVE:\n";
    if (skillLevel == "Beginner" || skillLevel == "Beginner-Intermediate") {
        cout << "  ✓ Month 1-2: Complete foundational course\n";
        cout << "  ✓ Month 3: Create your first project\n";
        cout << "  ✓ Month 6: Develop 2-3 showcase pieces\n";
        cout << "  ✓ Month 12: Reach intermediate level\n";
    } else if (skillLevel == "Intermediate") {
        cout << "  ✓ Month 1: Specialize in specific area\n";
        cout << "  ✓ Month 2-3: Build advanced projects\n";
        cout << "  ✓ Month 6: Complete professional portfolio\n";
        cout << "  ✓ Month 12: Reach professional level\n";
    } else {
        cout << "  ✓ Month 1: Explore advanced techniques\n";
        cout << "  ✓ Month 3: Teach others/create content\n";
        cout << "  ✓ Month 6: Establish thought leadership\n";
        cout << "  ✓ Year 1: Become recognized expert\n";
    }

    cout << "\nMONETIZATION STRATEGIES:\n";
    if (goal == "Hobby") {
        cout << "  • Keep it personal and enjoyable\n";
        cout << "  • Share with community if desired\n";
        cout << "  • Future monetization option: anytime\n";
    } else if (goal == "Side Income") {
        cout << "  • Fiverr, Upwork, 99designs\n";
        cout << "  • Freelance platforms\n";
        cout << "  • Personal website/portfolio\n";
        cout << "  • Sell digital products\n";
    } else if (goal == "Full-time Career") {
        cout << "  • Full-time employment\n";
        cout << "  • Freelance + salary hybrid\n";
        cout << "  • Start small agency\n";
        cout << "  • Apply to top companies\n";
    } else {
        cout << "  • Consulting & advising\n";
        cout << "  • Premium services\n";
        cout << "  • Teaching & mentoring\n";
        cout << "  • Content creation\n";
        cout << "  • Build industry recognition\n";
    }

    cout << "\nRESOURCES FOR YOUR JOURNEY:\n";
    cout << "  Online Platforms: Udemy, Coursera, skillshare, edX\n";
    cout << "  Communities: Reddit, Discord, Facebook Groups\n";
    cout << "  Practice: GitHub, CodePen, Dribbble, Behance\n";
    cout << "  Monetization: Fiverr, Upwork, Patreon, Etsy\n";

    cout << "\n═════════════════════════════════════════════════\n";
    cout << "SUCCESS FORMULA:\n";
    cout << "  Consistency (" << dailyHours << "h/day) + Quality Learning (" << learningStyle << ")\n";
    cout << "  + Clear Goal (" << goal << ") = Your Dream Career! 🚀\n";
    cout << "═════════════════════════════════════════════════\n\n";

    return 0;
}

// MAIN MENU
void displayMainMenu() {
    cout << "\n╔════════════════════════════════════════════════╗\n";
    cout << "║    PERSONALIZED CAREER GUIDANCE SYSTEM         ║\n";
    cout << "║        Your Future, Your Questions!            ║\n";
    cout << "╚════════════════════════════════════════════════╝\n\n";

    cout << "Choose your situation:\n\n";
    cout << "1. I'm in 10th class - Help choose stream\n\n";
    cout << "2. I'm after 12th class - Help choose career\n\n";
    cout << "3. Help explore my interests & passions\n\n";
    cout << "4. Exit\n\n";

    cout << "Enter choice (1/2/3/4): ";
}

int main() {
    initializeCareerDatabase();
    initializeHobbyDatabase();

    int choice = 0;
    while (true) {
        displayMainMenu();
        cin >> choice;

        if (choice == 1) {
            // Polymorphic behavior - using base class pointer
            Quiz* quiz = new QuizFor10th();
            quiz->conductQuiz();
            delete quiz;
        } else if (choice == 2) {
            // Polymorphic behavior - using base class pointer
            Quiz* quiz = new QuizFor12th();
            quiz->conductQuiz();
            delete quiz;
        } else if (choice == 3) {
            // Multiple inheritance: HobbyQuiz inherits from InterestBasedQuiz and QuizFormatter
            HobbyQuiz hobbyQuiz;
            hobbyQuiz.conductQuiz();
        } else if (choice == 4) {
            cout << "\n╔════════════════════════════════════════════════╗\n";
            cout << "║  Thank you for using Career Guidance System!   ║\n";
            cout << "║    Best wishes for your career journey! 🌟    ║\n";
            cout << "╚════════════════════════════════════════════════╝\n\n";
            break;
        } else {
            cout << "\nInvalid choice! Try again.\n";
        }

        cout << "\nContinuing to main menu...\n";
        system("pause");
        system("cls");
    }

    return 0;
}
