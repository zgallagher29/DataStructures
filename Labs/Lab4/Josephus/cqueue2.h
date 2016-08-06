/*********************************************
This is a modification of the Cqueue class
for the Josephus Problem. The class variable
Queue is an array of strings (for names).
*********************************************/
#include <cstring>
#include <string>
using namespace std;

class Cqueue2
{
    private:
        int Rear, Front;
        string * Queue;
        int Max;
        int Size;
    public:
        Cqueue2(int n);
        ~Cqueue2();
        int Is_Empty();
        int Is_Full();
        void Add(string Element);
        string Delete();
        string getFront();
        void write_Cqueue_to_Console();         //write all of the class variables to the console
        int get_size();                         //this function is added to Cqueue2 so can tell when have 1 member in the queue
        string remove_nth_member(int n);        //for Josephus problem to remove a member
};
