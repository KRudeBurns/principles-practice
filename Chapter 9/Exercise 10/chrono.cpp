// -----------------------------------------------------------------------------
// chrono.cpp
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "chrono.h"

// -----------------------------------------------------------------------------

namespace Chrono
{
	//member function definitions
	Date::Date(int y, Month m, int d)
		: m_y(y), m_m(m), m_d(d)
	{
		if (!is_date(y, m, d)) 
			error("Date is not valid");
	}

	// -----------------------------------------------------------------------------

	const Date& default_date()
	{
		static Date dd{ 2001, Month::jan, 1 };
		return dd;
	}

	// -----------------------------------------------------------------------------

	Date::Date()
		: m_y{ default_date().year() }
		, m_m{ default_date().month() }
		, m_d{ default_date().day() }
	{}

	// -----------------------------------------------------------------------------

	void Date::add_day(int n)
	{
		// to do:
	}

	// -----------------------------------------------------------------------------

	void Date::add_month(int n)
	{
		//to do:
	}

	// -----------------------------------------------------------------------------

	void Date::add_year(int n)
	{
		if (m_m == Month::feb && m_d == 29 && !leapyear(m_y + n))
		{
			m_m = Month::mar;
			m_d = 1;
		}

		m_y += n;
	}

	// -----------------------------------------------------------------------------

	//helper functions
	bool is_date(int y, Month m, int d)
	{
		//assume that y is valid

		if (d <= 0)
			return false;
		if (m < Month::jan || Month::dec < m)
			return false;

		int days_in_month = 31;		//most months have 31 days

		switch (m)
		{
		case Month::feb:			//the length of February varies
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days_in_month = 30;		//the rest have 30 days
			break;
		}

		if (days_in_month < d)
			return false;

		return true;
	}

	// -----------------------------------------------------------------------------

	//checks for leapyear (Gregorian calender)
	bool leapyear(int y)
	{
		// this is a bit confusing. Leap years are as defined:
		// if the year is evenly divisible by 4 (example: 2000 / 4 == 500 remainder 0)
		// century years are evenly divisible by 4, however they must also be evenly divisible by 400
		// (example: 1800 / 4 == 450 remainder 0 but 1800 / 400 == 4.5 remainder 0.5, therefore it is not a leap year,
		// however 2000 / 400 == 5 remainder 0, therefore it is a leap year)

		//if century year, must be divisible by 400
		if (y % 400 == 0) //remainder is 0
			return true;

		//if normal year and divisible by 4
		if (y % 4 == 0) //remainder is 0
			return true;

		//else not leap year
		return false;
	}

	// -----------------------------------------------------------------------------

	bool operator==(const Date& d1, const Date& d2)
	{
		return d1.year() == d2.year()
			&& d1.month() == d2.month()
			&& d1.day() == d2.day();
	}

	// -----------------------------------------------------------------------------

	bool operator!=(const Date& d1, const Date& d2)
	{
		return d1.year() != d2.year()
			&& d1.month() != d2.month()
			&& d1.day() != d2.day();
	}

	// -----------------------------------------------------------------------------

	ostream& operator<<(ostream& os, const Date& d)
	{
		return os << '(' << d.year()
			<< ',' << d.month()
			<< ',' << d.day() << ')';
	}

	// -----------------------------------------------------------------------------

	ostream& operator<<(ostream& os, const Month& m)
	{
		switch (m)
		{
		case Month::jan:
			return os << "January";
		case Month::feb:
			return os << "February";
		case Month::mar:
			return os << "March";
		case Month::apr:
			return os << "April";
		case Month::may:
			return os << "May";
		case Month::jun:
			return os << "June";
		case Month::jul:
			return os << "July";
		case Month::aug:
			return os << "August";
		case Month::sep:
			return os << "September";
		case Month::oct:
			return os << "October";
		case Month::nov:
			return os << "November";
		case Month::dec:
			return os << "December";
		default:
			return os << "Something weird happened.";
		}
	}

	// -----------------------------------------------------------------------------

	istream& operator>>(istream& is, Date& dd)
	{
		int y, m, d;
		char c1, c2, c3, c4;
		is >> c1 >> y >> c2 >> m >> c3 >> d >> c4;
		if (!is)
			return is;
		if (c1 != '(' || c2 != ',' || c3 != ',' || c4 != ')')
		{
			is.clear(ios_base::failbit);		//format error: set the fail bit
			return is;
		}

		dd = Date(y, Month(m), d);				//update dd
		return is;
	}

	// -----------------------------------------------------------------------------

	Day day_of_the_week(const Date& d)
	{
		//to do:
		Day day = Day::monday;
		return day;
	}

	// -----------------------------------------------------------------------------

	Date next_Sunday(const Date& d)
	{
		//to do:
		return d;
	}

	// -----------------------------------------------------------------------------

	Date next_weekday(const Date& d)
	{
		//to do:
		return d;
	}

	// -----------------------------------------------------------------------------
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
