#include <iostream>

void log() { }

template<typename T, typename ... Args>
void log(T first, Args ... args)
{
	std::cout << first << std::endl;
	log(args ...);
}

int main()
{
	log(1, 1.0, 'a', "sahib");
}
