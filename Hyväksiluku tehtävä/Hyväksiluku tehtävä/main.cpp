#include "Simulaatio.h"

int main()
{
	Simulaatio simulaatio;
	int kierroksia;

	std::cout << "Kuinka monta asiakasta tulee jonoon?" << std::endl;
	std::cin >> kierroksia;

	simulaatio.Start(kierroksia);

	return 0;
}