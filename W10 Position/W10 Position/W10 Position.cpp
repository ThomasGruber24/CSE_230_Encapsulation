/*************************************************************
 * 1. Name:
 *      Thomas Gruber
 * 2. Assignment Name:
 *      Practice 10: Exceptions
 * 3. Assignment Description:
 *      Throwing and catching exceptions
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 **************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/**************************************
 * GET POSITION
 * Turn a chess position like "d4" into a number
 **************************************/
int getPosition(const char* position)
{
    int row = -1;
    int col = -1;

    if (nullptr == position)
    {
        cout << "\tERROR: Please provide a valid string\n"; // Error 1: There was no string
        return -1;

    }

    for (const char* p = position; *p; p++)
    {
        if (isalpha(*p))
        {
            if (col != -1)
            {
				cout << "\tERROR: More than one column specifier\n"; // Error 3
                return -1;
            }
            else if (isupper(*p))
            {
                cout << "\tERROR: Columns must be lowercase\n"; // Error 2
                return -1;
            }
            else if ('a' <= *p && *p <= 'h')
                col = *p - 'a';
            else
            {
				cout << "\tERROR: Columns must be between a and h\n"; // Error 7
                return -1;
            }
        }
        else if (isdigit(*p))
        {
            if (row != -1)
            {
				cout << "\tERROR: More than one row specifier\n"; // Error 4
                return -1;
            }
            else if ('1' <= *p && *p <= '8')
                row = *p - '1';
            else
            {
				cout << "\tERROR: Rows must be between 1 and 8\n"; // Error 8
                return -1;
            }
        }
        else
        {
			cout << "\tERROR: Unknown letter\n"; // Error 9
            return -1;
        }
    }

    if (row == -1)
    {
		cout << "\tERROR: You must specify a row\n"; // Error 5
        return -1;
    }
    else if (col == -1)
    {
		cout << "\tERROR: You must specify a column\n"; // Error 6
        return -1;
    }

    return row * 8 + col;
}


/**************************************
 * TEST GET POSITION
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1   0  1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/
void test_getPosition()
{
    try
    {
        assert(27 == getPosition("d4"));
        cout << "\tgetPosition(\"d4\") passed\n";
    }
    catch (...) {
        cout << "\tERROR: Exception thrown for valid input d4\n";
    }

    try
    {
        assert(27 == getPosition("4d"));
        cout << "\tgetPosition(\"4d\") passed\n";
    }
    catch (...)
    {
        cout << "\tERROR: Exception thrown for valid input 4d\n";
    }

    try
    {
        assert(0 == getPosition("a1"));
        cout << "\tgetPosition(\"a1\") passed\n";
    }
    catch (...)
    {
        cout << "\tERROR: Exception thrown for valid input a1\n";
    }

    try
    {
        assert(63 == getPosition("h8"));
        cout << "\tgetPosition(\"h8\") passed\n";
    }
    catch (...)
    {
        cout << "\tERROR: Exception thrown for valid input h8\n";
    }

    try
    {
        assert(7 == getPosition("h1"));
        cout << "\tgetPosition(\"h1\") passed\n";
    }
    catch (...)
    {
        cout << "\tERROR: Exception thrown for valid input h1\n";
    }

    try
    {
        assert(56 == getPosition("a8"));
        cout << "\tgetPosition(\"a8\") passed\n";
    }
    catch (...)
    {
        cout << "\tERROR: Exception thrown for valid input a8\n";
    }

    try
    {
        assert(-1 == getPosition(nullptr));
        cout << "\texpected output for getPosition(nullptr)\n";

    }
    catch (...)
    {
        cout << "\tERROR: Exception thrown for valid input nullptr\n";
    }

    try
    {
        assert(-1 == getPosition("D4"));
        cout << "\texpected output for getPosition(D4)\n";
    }
    catch (...)
    {
        cout << "\tERROR: should have thrown an error\n";
    }

    try
    {
        assert(-1 == getPosition("dd4"));
		cout << "\texpected output for getPosition(dd4)\n";
    }
    catch (...)
    {
        cout << "\tERROR: should have thrown an error\n";
	}

    try
    {
        assert(-1 == getPosition("d44"));
		cout << "\texpected output for getPosition(d44)\n";
    }
    catch (...)
    {
        cout << "\tERROR: should have thrown an error\n";
	}

    try
    {
        assert(-1 == getPosition("d"));
		cout << "\texpected output for getPosition(d)\n";
    }
    catch (...)
    {
        cout << "\tERROR: should have thrown an error\n";
	}

    try
    {
        assert(-1 == getPosition("4"));
		cout << "\texpected output for getPosition(4)\n";
    }
    catch (...)
    {
        cout << "\tERROR: should have thrown an error\n";
	}

    try
    {
        assert(-1 == getPosition("i8"));
		cout << "\texpected output for getPosition(i8)\n";
    }
    catch (...)
    {
        cout << "\tERROR: should have thrown an error\n";
    }

    try
    {
        assert(-1 == getPosition("h9"));
		cout << "\texpected output for getPosition(h9)\n";
    }
    catch (...)
    {
        cout << "\tERROR: should have thrown an error\n";
	}

    try
    {
        assert(-1 == getPosition("d4^"));
		cout << "\texpected output for getPosition(d4^)\n";
    }
    catch (...)
    {
        cout << "\tERROR: should have thrown an error\n";
    }
}

/**************************************
 * MAIN
 **************************************/
int main()
{
    test_getPosition();
    cout << "Tests pass\n";

    return 0;
}