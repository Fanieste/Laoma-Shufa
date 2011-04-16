#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Dict
{
public:
	bool Load(const char* file)
	{
		std::ifstream in(file);
		if(!in)
			return false;

		std::string line;
		int page = 1;
		while(getline(in, line))
		{
			size_t len = line.length();
			for(int i = 0; i < len/3; i++)
			{
				std::string word = line.substr(i * 3, 3);
				auto i = mWordPageMap.find(word);
				if(i == mWordPageMap.end())
				{
					mWordPageMap[word] = page;
				}
			}
			page++;
		}

		return true;
	}

	int LookUp(const std::string& word)
	{
		auto i = mWordPageMap.find(word);
		if(i != mWordPageMap.end())
		{
			return i->second;
		}
		else
			return 0;
	}

private:
	std::map<std::string, int> mWordPageMap;
};
/*
int main()
{
	Dict dict;
	dict.Load("/home/xiaoye/caoquanbei.dat");
	int p = 0;
	p = dict.LookUp("君");
	std::cout << p << std::endl;
	p = dict.LookUp("周");
	std::cout << p << std::endl;
	return 0;	
}
*/
