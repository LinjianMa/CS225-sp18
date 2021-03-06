/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */
#include <ostream>

namespace QuackFun {

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 *  values.
 * @note You may use only two local variables of type T in your function.
 *  Note that this function is templatized on the stack's type, so stacks of
 *  objects overloading the + operator can be summed.
 * @note We are using the Standard Template Library (STL) stack in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint Think recursively!
 */
template <typename T>
T sum(stack<T>& s)
{

    // Your code here
	if (s.empty())
	{
		return 0;
	}
	T value = s.top();
	s.pop();
	T sumvalue= value+sum(s);
	s.push(value);
    return sumvalue; // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
}

/**
 * Checks whether the given string (stored in a queue) has balanced brackets. 
 * A string will consist of 
 * square bracket characters, [, ], and other characters. This function will return
 * true if and only if the square bracket characters in the given
 * string are balanced. For this to be true,
 * all brackets must be matched up correctly, with no extra, hanging, or unmatched
 * brackets. For example, the string "[hello][]" is balanced, "[[][[]a]]" is balanced,
 * "[]]" is unbalanced, "][" is unbalanced, and "))))[cs225]" is balanced.
 *
 * You are allowed only the use of one stack in this function, and no other local variables.
 *
 * @param input The queue representation of a string to check for balanced brackets in
 * @return Whether the input string had balanced brackets
 */
bool isBalanced(queue<char> input)
{
	stack<char> s;
	while (input.size() != 0)
	{
		char A = input.front();
		input.pop();
		if (A == '[')
		{
			s.push(A);
		}
		if (A == ']')
		{
			if (s.size() == 0)
			{
				return false;
			}
			if (s.size() != 0)
			{
				s.pop();
			}
		}
	}
	if (s.size()!=0)
	{
		return false;
	}
    // @TODO: Make less optimistic
    return true;
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was
 *  complete.
 * @note We are using the Standard Template Library (STL) queue in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void scramble(queue<T>& q)
{
    stack<T> s;
    // optional: queue<T> q2;
	queue<T> q2;    // empty queue
	int length = q.size();
	int i = 1;
	int sum = 0;
	while (sum+i<length)
	{
		sum = sum+i;
		if ( int(i%2)!= 0 )
		{
			for (int j=0; j<i ; j++)
			{
				T value = q.front();
				q.pop();
				q2.push(value);
			}
		}
		if ( int(i%2)== 0 ){
			for (int j=0; j<i ; j++)
			{
				s.push(q.front());
				q.pop();
			}
			for (int j=0; j<i ; j++)
			{
				q2.push(s.top());
				s.pop();
			}
		}
		i= i+1;
	}
	//i = i-1;
	int di = length - sum;
		if ( int(i%2)!= 0 )
		{
			for (int j=0; j<di ; j++)
			{
				T value = q.front();
				q.pop();
				q2.push(value);
			}
		}
		if ( int(i%2)== 0 ){
			for (int j=0; j<di ; j++)
			{
				s.push(q.front());
				q.pop();
			}
			for (int j=0; j<di ; j++)
			{
				q2.push(s.top());
				s.pop();
			}
		}



	q = q2;

    // Your code here
}

/**
 * @return true if the parameter stack and queue contain only elements of
 *  exactly the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note The back of the queue corresponds to the top of the stack!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 */
template <typename T>
bool verifySame(stack<T>& s, queue<T>& q)
{
    bool retval = true; // optional

    T temp_s; // rename me
    T temp_q; // rename :)
	temp_s = s.top();
	s.pop();
	if (s.size()!=0)
	{
		retval = verifySame(s,q);
	}
	s.push(temp_s);
	temp_q = q.front();
	if (temp_s!=temp_q)
	{
		retval = false;
	}
	q.pop();
	q.push(temp_q);

    return retval;
	
}

}
