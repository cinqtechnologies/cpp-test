#include <iostream>

using namespace std;

class Sky
{
public:
	Sky(int stars = 0)
		: m_stars(stars)
	{
	    cout << "Sky constructor\n";
	}

	int stars() const
	{
	    cout << "Sky stars const\n";
		return m_stars;
	}

	void stars(int n)
	{
	    cout << "Sky stars n\n";
		m_stars = n;
	}

private:
	int m_stars;
};

class NightSky : public Sky
{
public:
	NightSky(int stars = 0)
		: Sky(stars)
	{
	    cout << "NightSky constructor\n";
	}
};

class BlueSky : public NightSky //public Sky
{
public:
	BlueSky(int stars = 0)
		: NightSky(stars) // Sky(stars)
	{
	    cout << "BlueSky constructor\n";
	}
};

class BlueNightSky : public BlueSky //, public NightSky
{
public:
	BlueNightSky()
	{
	    cout << "BlueNightSky constructor\n";
	}
};

void readInput(NightSky& nightSky)
{
	int n = 0;
	std::cin >> n;

	nightSky.stars(n);
}

int getAmountOfStars(const BlueSky& blueSky)
{
	return blueSky.stars();
}

int main(int argc, char** argv)
{
	BlueNightSky blueNightSky;

	readInput(blueNightSky);

	std::cout << getAmountOfStars(blueNightSky) << std::endl;

	return 0;
}
