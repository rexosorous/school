#ifndef STACKPAC
#define STACKPAC

#include <iostream>
using namespace std;

template <class T, int n>
class STACK
{
private:
	T contents[n];
	int counter = 0;
public:
	void clear();
	bool isEmpty();
	bool isFull();
	void push(T x);
	T pop();
};

template <class T, int n>
void STACK<T, n>::clear() { counter = 0; }

template <class T, int n>
bool STACK<T, n>::isEmpty() { return (counter == 0) ? true: false; }

template <class T, int n>
bool STACK<T, n>::isFull() { return (counter == 100) ? true: false; }

template <class T, int n>
void STACK<T, n>::push(T x) { contents[counter++] = x; }

template <class T, int n>
T STACK<T, n>::pop() { return contents[--counter]; }

#endif