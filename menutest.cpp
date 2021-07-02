#include <bits/stdc++.h>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono_literals;
using namespace std::this_thread;

class Menu
{
private:

//arrays for Menu Actions
    string bedroomActions[6] = {"1. Examine Room",
                            "2. Do Homework",
                            "3. Sleep",
                            "4. Go to Hallway",
                            " ",
                            "Bedroom"};
    string hallwayActions[6] = {"1. Examine Room",
                            "2. Go to Kitchen",
                            "3. Go to Bathroom",
                            "4. Go to Living Room",
                            "5. Go to Bedroom",
                            "Hallway"};
    string kitchenActions[6] = {"1. Examine Room",
                            "2. Make Food",
                            "3. Go to Hallway",
                            "4. Go to Living Room",
                            " ",
                            "Kitchen"};
    string livingRoomActions[6] = {"1. Examine Room",
                               "2. Play Video Games",
                               "3. Socialize with Friends",
                               "4. Go to Kitchen",
                               "5. Go to Hallway",
                               "Living Room"};
    string bathroomActions[6] = {"1. Examine Room",
                             "2. Take a Shower",
                             "3. Use the Toilet",
                             "4. Go to Hallway",
                             " ",
                             "Bathroom"};

//array for Tasks
string tasks[7] = {"I'm sleepy... I should go to bed", 
                  "I'm hungry... I should get something to eat",
                  "I'm lonely... I should talk to someone",
                  "I have homework to do... I should start that",
                  "...I really need to use the restroom",
                  "I smell horrible... I should take a shower",
                  "I'm bored... video games sound fun right now"};

//arrays for Menu Initialization
string intro[10]         {"||||||||||||||||||||||||||||||||||||||||", 
                          "|                                      |",
                          "|            Going Nowhere:            |",
                          "|        A Text-Based Horror Game      |",
                          "|                                      |",
                          "|                                      |",
                          "|          By: Amelia Rotondo          |",
                          "|                                      |",
                          "|                                      |",
                          "||||||||||||||||||||||||||||||||||||||||"};
string synopsis[6]       {"You are a College Student who has been working from home for the past year.", 
                          "Despite the freedoms granted by working at home, you begin to realize that ",
                          "sometimes you can grow too comfortable to your environment.",
                          "In your comfort, you will fail to realize that your environment has been ",
                          "altered beyond your control.",
                          "What do you do now?",};
string rules[6]          {"Welcome! this is a text-based horror game played by entering values into the terminal.", 
                          "You will be presented with a menu containing several values, including: ",
                          "a list of tasks for the day, a room type, and actions you can do within that room. ",
                          "To complete tasks for the day, enter the number listed next to actions within a room; ",
                          "For some tasks, you may have to go to different rooms to access new actions.",
                          "I hope you enjoy Going Nowhere.",};
string menu[33]          {"||||||||||||||||||||||||||||||||||||||||||||||||||\n", 
                          "| Day:                                           |\n",
                          "| ","|\n", //Day Value
                          "|------------------------------------------------|\n",
                          "| Tasks:                                         |\n",
                          "| ","|\n", //Task 1
                          "| ","|\n", //Task 2
                          "| ","|\n", //Task 3
                          "|                                                |\n",
                          "|------------------------------------------------|\n",
                          "| Room:                                          |\n",
                          "| ","|\n", //Room Name
                          "|                                                |\n",
                          "|------------------------------------------------|\n",
                          "| Actions Available:                             |\n",
                          "| ","|\n", //Room Action 1
                          "| ","|\n", //Room Action 2
                          "| ","|\n", //Room Action 3
                          "| ","|\n", //Room Action 4
                          "| ","|\n", //Room Action 5
                          "|                                                |\n",
                          "|                                                |\n",
                          "||||||||||||||||||||||||||||||||||||||||||||||||||\n"};

public:

    
};

int main()
{
    return 0;
}


