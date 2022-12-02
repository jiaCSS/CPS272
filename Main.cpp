#include"Queue.h"
#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<cstdlib>

using namespace std;



int main() {

	    Queue checkoutLine;
	    //srand(time(NULL));
	    srand(500);
	
	
		int serviceTimer = 0;
		int nextArrivalTimer = (rand() % 4) + 1;
		int maxlinesize = 0;
		int maxwaitTime = 0;
		int customersServed = -1;

		for(int minutes = 0; minutes < 120; minutes++) {

			if(nextArrivalTimer-- <= 0) {

				checkoutLine.enqueue(minutes);//customer arrive
				nextArrivalTimer = (rand() % 4) + 1;//random arrival time
				cout << "\nArrival time at the : " << minutes <<" minutes" << "\n";

				if (checkoutLine.size() > maxlinesize) {

					maxlinesize = checkoutLine.size();						
				}
			}
			if(checkoutLine.isEmpty() == false) {

				if(serviceTimer-- == 0) {
					int waitTime = minutes -checkoutLine.peek();

					if (waitTime > maxwaitTime) {
						maxwaitTime = waitTime;
					}
					checkoutLine.dequeue();//customer left

					serviceTimer= (rand() % 4) + 1;//random service, and new customer coming in 

					cout << "serviced time: " << serviceTimer << " minutes" << endl;
					cout << "customer served "<<endl;
					cout << "Number of customers in line: " << checkoutLine.size() << endl;
					customersServed++;
				}
				
			}
		}

		cout << "\nAfter 2 hours: \n";
		cout << "Number of customers in line: " << checkoutLine.size() << endl;
		cout << "Customers served: " << customersServed << endl;
		cout << "Maximum number of customers in the queue at any time : " << maxlinesize << endl;
		cout << "Max wait time : " << maxwaitTime <<" minutes"<< endl;					
	
	
	
	return 0;
}

