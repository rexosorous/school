#ifndef STACK_CLASS
#define STACK_CLASS

template <class T, int n>
class STACK
{
private:
	T contents[n];
	int counter;
public:
	void clear() { counter = 0; }
	bool isEmpty() { return (counter == 0) ? true : false; }
	bool isFull() { return (counter == n) ? true : false; }
	void push(T element) { contents[counter++] = element; }
	T pop() { return contents[--counter]; }
};

#endif