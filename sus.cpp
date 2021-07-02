#include <bits/stdc++.h>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono_literals;
using namespace std::this_thread;

//class designed to add suspense to text displays
//FIX FILE OPENERS TO ADD FILE CLOSERS AND NOT FUCK ITSELF OVER
class Suspense {
    private:
    public:
        //times out the printing of a file by it's Lines (20ms)
        void fileLineSuspense(string input)
        {
            ifstream in(input);
            if(!in)
            {
                cout<< "Cannot open input file!" << endl;
            }
            string line;
            while(getline(in, line)) 
            {
                cout << line << "\n";
                sleep_for(20ms);
            }
            cout << "\n";
        }

        //times out the printing of a file by it's text (100-200ms)
        void fileTextSuspense(string input)
        {
            ifstream in(input);
            if(!in)
            {
                cout<< "Cannot open input file!" << endl;
            }
            string line;
            while(getline(in, line)) 
            {
                char* hold = &line[0];
                char *output = hold;
                while (*output != false)
                {
                    sleep_for(100ms);
                    cout << *output;
                    output++;
                }
                cout << "\n";
                sleep_for(200ms);
            }
            cout << "\n";
        }

        //times out the printing of a string by it's text (250ms)
        void textSuspense(string input)
        {
            char* hold = &input[0];
            char *output = hold;
            while (*output != false)
            {
                sleep_for(250ms);
                cout << *output;
                output++;
            }
            cout << "\n";
        }

        //prints timed out footsteps to the console (200ms)
        void footsteps(int a)
        {
            for(int i; i<a; i++)
            {
                cout << "^\n";
                sleep_for(200ms);
                cout << " ^\n";
                sleep_for(200ms);
            }
            cout << "^\n\n";
        }

        //prints out timed out elipses designed to space out another console print
        void addSuspense()
        {

        }
};

int main ()
{
    Suspense sus;
    sus.fileLineSuspense("intro.txt");
    sleep_for(1000ms);
    sus.fileTextSuspense("synopsis.txt");
    sleep_for(1000ms);
    sus.footsteps(3);
    sus.textSuspense("...Welcome Home...");
    return 0;
}


