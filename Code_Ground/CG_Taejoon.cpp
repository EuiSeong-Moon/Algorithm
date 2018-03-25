/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	int m, a, d, gap, s = 0, times = 0;

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> m >> a >> d;
		gap = m - a;
		s = 0, times = 0;

		while (1)
		{
			times += 1;
			if (d - (m + s) <= 0)
			{
				cout << "Case #" << test_case + 1 << endl;
				cout << times << endl;
				break;
			}
			s += gap;
		}

		// Print the answer to standard output(screen).

	}

	return 0;//Your program should return 0 on normal termination.
}