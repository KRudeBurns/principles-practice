// -----------------------------------------------------------------------------
//
// C9 - Exercise 14
//
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "MoneyClass.h"

// -----------------------------------------------------------------------------

int main()
{
	Money m1(3.45);
	Money m2(3.45);
	cout << m1;
	cout << m2;

	m1 + m2;
	m1 - m2;
	m1 / m2;
	m1 * m2;

	char ch;
	cin >> ch;
	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------