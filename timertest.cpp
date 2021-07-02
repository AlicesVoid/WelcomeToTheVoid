#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main() 
{
using namespace std::chrono_literals;
using namespace std::this_thread;

int n = 3;
//sets a value n to 3

char dm[] = "...Deathmatch!";
char *p=dm;
//creates a character dm with the contents of deathmatch, and a pointer for it

while (n>0)
    {
        sleep_for(1500ms);
        cout << "." << endl;
        n--;
    }
//runs a function to display a period every second for n seconds

sleep_for(900ms);
while (*p != NULL)
{
    sleep_for(110ms);
    cout << *p;
    p++;
}
//prints DEATHMATCH!

return 0;
//returns 0 to the Operating System
}
