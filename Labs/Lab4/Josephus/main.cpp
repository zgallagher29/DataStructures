#include <iostream>
#include <cstring>
#include "cqueue2.h"

using namespace std;

int main()
{
    int i;
    string Temp;
    int n;                  //number we'll count.
    int num_members;      //number of members

    cout << "*********************** The Josephus Problem ***********************" << endl;
    cout << "A group of soldiers is surrounded. There is no hope for victory." << endl;
    cout << "There is but a single horse available for escape and many soldiers." << endl;
    cout << "Who will survive??" << endl;
	cout << "How many soldiers are there?" << endl;
	cin >> num_members;
	Cqueue2 Q(num_members);
	for (int i = 0; i < num_members ; i++)
	{
		cout << "What is the soldier #" << i + 1 << endl;
		cin >> Temp;
		Q.Add(Temp);

	}
	cout << "We'll be counting around a circle. What is n: " << endl;
	cin >> n;

	string Name;
	while (Q.get_size() > 1){
		Name = Q.remove_nth_member(n);
		cout << Name << " has been removed from the circle." << endl;
		cout << " Now the queue contains: " << endl;
		Q.write_Cqueue_to_Console();
	}
	cout << "\n" << Q.getFront() << " gets to ride to safety \n" << endl;
	

	system("pause");
    //1. Let n be the number of members
    //2. Get the first member.
    //3. Add all of the members to the queue
    //IMPORTANT, HAVE TO ASK WHAT THE NUMBER IS n THAT WE'LL COUNT AROUND THE CIRCLE
    //4. while (there is more than one member in the queue):
    //      count through n-1 members in the queue
    //      print the name of the nth member
    //      remove the nth member from the queue
    //5. Print the name of the only member in the list
    return 0;
}
