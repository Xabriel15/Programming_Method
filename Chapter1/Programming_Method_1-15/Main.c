#include <stdio.h>

int toFahrenheit(int);
int toCelsius(int);

main()
{
	int temp;
	temp = 0;
	printf("temp: %d", toCelsius(temp));

}

int toFahrenheit(int _celsius)
{
	return (_celsius * 9) / 5 + 32;
}

int toCelsius(int _fahrenheit)
{
	return (_fahrenheit - 32) * 5 / 9;
}