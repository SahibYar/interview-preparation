//Write a program where functions take some arguments, and return result using threads
#include <thread>
#include <iostream>

void f(std::vector<double>& v, double* result);
struct F
{
	double* res;
	std::vector<double>& vv;
	
	F(vector<double>& _vv, double* _res) : vv{_vv}, res{_res} { }
	operator()();
}

int main()
{
	double res1;
	double res2;
	
	std::thread t1{std::bind(f,some_vec, &res1)};		//f(some_vec, &res1) will be executed in separate thread
	std::thread t2{F(some_vec, &res2)};					//F(some_vec, &res2)() will be executed in separate thread
	
	std::cout << res1 << ' ' << res2 << '\n';
	
	return 0;
}
