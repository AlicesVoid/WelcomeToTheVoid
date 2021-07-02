#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main() 
{
using namespace std::chrono_literals;
using namespace std::this_thread;

string aa = "////////////////////////////////////////\n\n";
cout << aa;

char xy[] = "B i t c h b o y _ I n d u s t r i e s";
char *x=xy;
sleep_for(900ms);
while (*x != NULL)
{
    sleep_for(110ms);
    cout << *x;
    x++;
}
sleep_for(500ms);
string bb = "\n\n////////////////////////////////////////\n";
cout << bb;

sleep_for(1s);
for (int i = 0; i < 5; i++)
{
    sleep_for(1s);
    cout << "." << endl;
}
char ay[] = ".....guess what?\n";
char *a=ay;
sleep_for(900ms);
while (*a != NULL)
{
    sleep_for(110ms);
    cout << *a;
    a++;
}
sleep_for(3s);

sleep_for(1s);
for (int i = 0; i < 5; i++)
{
    sleep_for(1s);
    cout << "." << endl;
}
char by[] = ".....you're gay lol\n";
char *b=by;
sleep_for(900ms);
while (*b != NULL)
{
    sleep_for(110ms);
    cout << *b;
    b++;
}
sleep_for(3s);

return 0;
}