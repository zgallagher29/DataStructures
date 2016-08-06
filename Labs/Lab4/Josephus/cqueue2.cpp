#include <iostream>
#include "cqueue2.h"

using namespace std;

Cqueue2::Cqueue2(int n)
{
    Size=0;
    Rear=Front=-1;
    Max=n;
    Queue = new string [n];        //the Queue array is dynamically allocated
}

Cqueue2::~Cqueue2()
{
	if (Queue != NULL){
		delete[] Queue;
	}             //have to delete dynamically allocated memory
}

int Cqueue2::Is_Empty()
{
    if(Size==0) return true;
    else return false;
}

int Cqueue2::Is_Full()
{
    if(Size==Max) return true;
    else return false;
}

void Cqueue2::Add(string Element)
{
	if (Is_Full()){
		cout << "The queue is full." << endl;

	}
	else{
		Rear = (Rear + 1) % Max;
		Queue[Rear] = Element;
		Size++;
	}
}

string Cqueue2::Delete()
{
    if(Is_Empty())
    {
        cout << "The Cqueue is empty." << endl;
        return "";
    }
    else
    {
        Front=(Front+1)%Max;
        Size--;
        return Queue[Front];
    }
}

string Cqueue2::getFront()
{
    int Temp;
    if(Is_Empty())
    {
        return "";
    }
    else
    {
        Temp=(Front+1)%Max;
        return Queue[Temp];
    }
}

void Cqueue2::write_Cqueue_to_Console()         //write all of the class variables to the console
{
    int i;
    int Temp;
	if (Is_Empty()){
		cout << "Queue is empty.\n";
	}
    else
    {
		for (int i = 1; i <= Size; i++)
		{
			Temp = (Front + i) % Max; //help iterate in circular manner 
			cout << Queue[Temp] << endl;


		}
    }
}

int Cqueue2::get_size()                         //this function is added to Cqueue2 so can tell when have 1 member in the queue
{
    return Size;
}

string Cqueue2::remove_nth_member(int n)             //for Josephus problem to remove a member
{
    string name;
    int i;
    int index;
    int start;
	name = Queue[(n-1)%Size];
	start = n%Size;  //the next person in line 
	string * TempQ = new string[Size - 1];
	for (int i = 0; i < (Size - 1); i++){
		index = (start + i) % Max;
		TempQ[i] = Queue[index]; 
	}
	Size--; 
	delete[] Queue;
	Queue = new string[Size];
	for (int i = 0; i < Size; i++){
		Queue[i] = TempQ[i];
	}
	Max--;
	delete[] TempQ; 
	return name;
    //we'll be deleteing the soldier at index n%Size
    //subtract 1 to account for the fact that indexing starts at 0
    //refresh Queue with the member who is kicked out gone
  
}
