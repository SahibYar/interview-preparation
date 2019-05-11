class Wallet
{
	int mMoney;
	std::mutex _mutex;
public:
	Wallet() : mMoney(0) { }
	int getMoney() { return mMoney; }
	void addMoney(int _money)
	{
		_mutex.lock();
		for (int i = 0; i < _money; i++)
		{
			mMoney++;
		}
		_mutex.unlock();
	}
};

int testMultiThreadingWallet()
{
	Wallet wallet;
	std::vector<std::thread> threads;

	for (int i = 0; i < 5; i++)
	{
		threads.push_back(std::thread(&Wallet::addMoney, &wallet, 1000));
	}

	for (int i = 0; i < threads.size(); i++)
	{
		threads.at(i).join();
	}
	return wallet.getMoney();
}

int main()
{
	int val = 0;
	for (int i = 0; i < 1000; i++)
	{
		if ((val = testMultiThreadingWallet()) != 5000)
			std::cout << "Error at count " << i << " Money in wallet is " << val << std::endl;
	}
	return 0;
}
