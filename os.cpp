/*
Demand paging

Concept of virtual memory, using secondary memory as a part of primary memory.
Storing pages of all the frames in secondary memory until they are required. Only a part of the process needs to be present 
in the main memory which means only a few pages will only be present in the main memory at any time. 

--------------------------------------------------------------------------------------------

Page fault

If the referred page is not present in the main memory then there will be a miss and the concept is called Page miss or page fault.
CPU has to access the page from secondary memory which will take a lot of time.

--------------------------------------------------------------------------------------------

Virtual memory

Using secondary memory such as hard disk as though it were a part of main memory. Concept of paging, demand paging.
Virtual memory is implemented using demand paging. 

--------------------------------------------------------------------------------------------

Semaphores

Integer variables used to solve the critical section problem by using two atomic operations,  
wait and signal are used for process synchronization. 

Two operations - wait and signal 

wait - decrements the value of argument S, if it is positive. If S is negative or 0 then no operation is performed. 
signal - increments the value of argument is S.  

Two types of Semaphores - binary and counting. 

-----------------------------------------------------------------------------------------

Producer consumer problem

synchronization problem - uses semaphore / mutex to solve critical section issue. 


void producer() {
	while(true) {
		wait(empty)
		wait(mutex)
		add_item()
		signal(mutex)
		signal(full)
	}
}


void consumer() {
	while(true) {
		wait(full)
		wait(mutex)
		consume_item()
		signal(mutex)
		signal(empty)
	}
}

wait(mutex) --> restricts another process from entering the critical section.  

------------------------------------------------------------------------------------------

Mutex vs semaphore

A mutex provides mutual exclusion, either producer or consumer can have the key (mutex) and 
proceed with their work. As long as the buffer is filled by the producer, the consumer 
needs to wait, and vice versa. 

A semaphore is a generalized mutex. In lieu of a single buffer, we can split the 4 KB buffer 
into four 1 KB buffers (identical resources). A semaphore can be associated with these 
four buffers. The consumer and producer can work on different buffers at the same time. 


-------------------------------------------------------------------------------------------------

Swap out and swap in 

Swap out --> Swap-out is a method of removing a process from RAM and adding it to the hard disk.
Swap in --> Swap-in is a method of removing a program from a hard disk and putting it back into the main memory or RAM. 

--------------------------------------------------------------------------------------------------


Starvation  == Starvation is the problem that occurs when high priority processes keep executing 
				and low priority processes get blocked for indefinite time.


Aging ==  It is a scheduling technique used to avoid starvation of lower priority processes. 

--------------------------------------------------------------------------------------------------

LRU - page replacement algorithm.  

Pages that have been highly used in the past are more likely to be used again in the future. 

In LRU, whenever page replacement happens, the page which has not been used for the longest
amount of time is replaced.


--------------------------------------------------------------------------------------------------

*/


#include <bits/stdc++.h>
using namespace std;

class A {
public:
	virtual void meth() {
		cout << "Function in A\n";
	}
};

class B : public A {
public:
	void meth() {
		cout << "Function in B\n";
	}
};


int main() {
	// using superclass reference to call subclass method.

	A *ob;
	B *ob2 = new B();

	ob = ob2;

	ob->meth();



}



















