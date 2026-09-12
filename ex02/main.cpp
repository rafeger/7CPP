#include "Array.hpp"


//point a noter cest que les templates pour un type particulier ne compile que
//si on les appelle CAD
//si tas un overload de merde pour un operator= sur array<std::string>,
//mais que tappelles jamais cette templateclass avec T as std::string, eh bah ca compile
//sans soucis
int main(void)
{
	std::cout <<CYAN<< "-- default constructor --" << DEFAULT<< std::endl;
	Array<int> empty;
	std::cout << "empty.size() = " << empty.size() << std::endl;
	try
	{
		std::cout << empty[0] << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << BOLDRED << "caught: " << e.what() << DEFAULT << std::endl;
	}

	std::cout << std::endl <<CYAN<< "-- parametric constructor with n = 0 --" << DEFAULT<< std::endl;
	Array<int> zero(0);
	std::cout << "zero.size() = " << zero.size() << " (same as default constructor)" << std::endl;

	std::cout << std::endl <<CYAN<< "-- parametric constructor (zero-init check) --" << DEFAULT<< std::endl;
	//le compilateur prends le patron template donc : template <typename T> class Array {...}
	//et remplis ce quon lui donne
	// CAD : chaque T est remplace par un int, donc on genere une instance de classe Array<int>
	//en gros mtn on a une classe avec dedans a la place de T *_array, int *_array
	//et TOUS les T sont devenus des ints OK ? ok
	Array<int> nums(5);
	std::cout << "nums.size() = " << nums.size() << std::endl;
	std::cout << "nums values: ";
	for (unsigned int i = 0; i < nums.size(); ++i)
		std::cout << nums[i] << " ";
	std::cout << std::endl;

	for (unsigned int i = 0; i < nums.size(); ++i)
		nums[i] = (i + 1) * 10;

	std::cout << std::endl <<CYAN<< "-- copy constructor: deep-copy check --"<< DEFAULT << std::endl;
	Array<int> copy(nums);
	nums[0] = 999;
	std::cout << "nums[0] = " << nums[0] << " (modified original)" << std::endl;
	std::cout << "copy[0] = " << copy[0] << " (should be untouched)" << std::endl;
	copy[3] = 555;
	std::cout << "copy[3] = " << copy[3] << " (modified copy)" << std::endl;
	std::cout << "nums[3] = " << nums[3] << " (should be untouched)" << std::endl;

	std::cout << std::endl <<CYAN<< "-- assignment operator: deep-copy check --" << DEFAULT<< std::endl;
	Array<int> assigned;
	assigned = nums;
	nums[1] = 777;
	std::cout << "nums[1] = " << nums[1] << " (modified original)" << std::endl;
	std::cout << "assigned[1] = " << assigned[1] << " (should be untouched)" << std::endl;
	assigned[4] = 111;
	std::cout << "assigned[4] = " << assigned[4] << " (modified assigned)" << std::endl;
	std::cout << "nums[4] = " << nums[4] << " (should be untouched)" << std::endl;

	std::cout << std::endl <<CYAN<< "-- self-assignment (a = a) --" << DEFAULT<< std::endl;
	assigned = assigned;
	std::cout << "assigned.size() = " << assigned.size() << " (still valid after self-assignment)" << std::endl;
	std::cout << "assigned[4] = " << assigned[4] << " (unchanged)" << std::endl;

	std::cout << std::endl <<CYAN<< "-- out-of-range access --" <<  DEFAULT<< std::endl;
	try
	{
		std::cout << nums[100] << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << BOLDRED << "caught: " << e.what() <<  DEFAULT << std::endl;
	}
	try
	{
		std::cout << nums[-1] << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << BOLDRED <<"caught: " << e.what() << DEFAULT << std::endl;
	}
	try
	{
		// off-by-one: the last valid index is size() - 1, so size() itself
		// must already be rejected
		std::cout << nums[nums.size()] << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << BOLDRED << "caught: " << e.what() << DEFAULT << std::endl;
	}

	std::cout << std::endl <<CYAN<< "-- const correctness --" << DEFAULT<< std::endl;
	Array<int> const &constRef = nums;
	std::cout << "constRef.size() = " << constRef.size() << std::endl;
	std::cout << "constRef[2] = " << constRef[2] << std::endl;
	try
	{
		// exercises the const overload of operator[] specifically
		std::cout << constRef[100] << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << BOLDRED << "caught: " << e.what() << DEFAULT << std::endl;
	}

	std::cout << std::endl <<CYAN<< "-- works with a non-primitive type --" <<  DEFAULT<< std::endl;
	Array<std::string> words(3);
	std::cout << "doit etre vide \"" << words[0] << "\"" << std::endl;
	words[0] = "Moloch";
	words[1] = "Baal";
	words[2] = "Akemi Homura";
	for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << words[i] << " ";
	std::cout << std::endl;

	return (0);
}
