#include <thread>
#include <iostream>

void threadcallable(const int& x)
{
	int& y = const_cast<int&>(x);
	y++;
	cout << "Inside Thread x = " << y << endl;
}

int main()
{
	int x = 9;
	cout << "Inside Main Thread x = " << x << endl;
	std::thread threadObj(threadcallable, std::ref(x));
	threadObj.join();
	cout << "Inside Main Thread x = " << x << endl;

}
