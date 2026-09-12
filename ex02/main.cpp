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
	std::cout << "zero.size() = " << zero.size() << std::endl;

	std::cout << std::endl <<CYAN<< "-- nums--" << DEFAULT<< std::endl;
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
		nums[i] = (i + 1);

	std::cout << std::endl <<CYAN<< "-- copy constructor check --"<< DEFAULT << std::endl;
	Array<int> copy(nums);
	std::cout << "nums[]" << std::endl;
	for (unsigned int i = 0; i < nums.size(); i++)
		std::cout << "nums[" << i << "] = "<< nums[i] << " | " ;
	std::cout << std::endl;
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << "copy[" << i << "] = "<< copy[i] << " | " ;
	std::cout << std::endl;
	nums[0] = 42;
	std::cout << "nums[0] = " << nums[0] << " (modified original)" << std::endl;
	std::cout << "copy[0] = " << copy[0] << " (should be untouched)" << std::endl;
	copy[1] = 42;
	std::cout << "copy[1] = " << copy[3] << " (modified copy)" << std::endl;
	std::cout << "nums[1] = " << nums[3] << " (should be untouched)" << std::endl;

	std::cout << std::endl <<CYAN<< "-- overload = check --" << DEFAULT<< std::endl;
	Array<int> assigned;
	assigned = nums;
	nums[1] = 777;
	std::cout << "nums[1] = " << nums[1] << " (modified original)" << std::endl;
	std::cout << "assigned[1] = " << assigned[1] << " (should be untouched)" << std::endl;
	assigned[4] = 111;
	std::cout << "assigned[4] = " << assigned[4] << " (modified assigned)" << std::endl;
	std::cout << "nums[4] = " << nums[4] << " (should be untouched)" << std::endl;

	std::cout << std::endl <<CYAN<< "oor access" <<  DEFAULT<< std::endl;
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

	std::cout << std::endl <<CYAN<< "const" << DEFAULT<< std::endl;
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

	// try
	// {
	// 	constRef[1] = 150;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	

	std::cout << std::endl <<CYAN<< "types plus complexes nuhuhuhuhuh" <<  DEFAULT<< std::endl;
	Array<std::string> words(3);
	std::cout << "doit etre vide \"" << words[0] << "\"" << std::endl;
	words[0] = "Moloch";
	words[1] = "Baal";
	words[2] = "Akemi Homura";
	for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << words[i] << " - ";
	std::cout << std::endl;

	return (0);
}
