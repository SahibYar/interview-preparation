/*
Suppose we are building a network based application.This application does following tasks,
	1.	Perform some handshaking with server
	2.	Load Data from XML files.
	3.	Do processing on data loaded from XML.

As we can see that Task 1 is not dependent on any other Tasks but Task 3 is dependent on 
Task 2. So, it means Task 1 and Task 2 can be run in parallel by different Threads to 
improve the performance of application.So, let’s break this into a multi threaded application,

Responsibilities of Thread 1 are,
	*	Perform some handshaking with server.
	*	Wait for data to be loaded from XML by Thread 2
	*	Do processing on data loaded from XML.

Responsibilities of Thread 2 are,
	*	Load data from XML
	*	Notify another Thread i.e.waiting for the message.
*/

#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

class Application
{
	std::mutex _mutex;
	std::condition_variable _condition;
	bool dataLoaded;
public:
	Application() :dataLoaded(false) {}
	bool isLoaded() { return dataLoaded; }

	void loadingData()
	{
		std::cout << "Started loading data from XML file\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));

		std::lock_guard<std::mutex> lockguard(_mutex);
		dataLoaded = true;
		
		std::cout << "Loading data from XML file completed\n";
		_condition.notify_one();
	}

	void mainTask()
	{
		std::cout << "Doing handshaking with server.\n";
		std::unique_lock<std::mutex> mLock(_mutex);
		_condition.wait(mLock, std::bind(&Application::isLoaded, this));
		std::cout << "Doing processing on loaded data.\n";
	}
};

int main()
{
	Application app;
	std::thread t1(&Application::loadingData, &app);
	std::thread t2(&Application::mainTask, &app);

	if (t1.joinable() && t2.joinable())
	{
		t1.join();
		t2.join();
	}
	return 0;
}
