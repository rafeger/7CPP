#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &value)
{
	std::cout << value << " ";
}

//en gros on demande un tableau de N elements de type T
//a la compil on passe que par exemple (ints)
//nmais comment c possible ?? 
//eh bien en realite on passe int[5] et donc T devient int et N devient [5]
//et juste on retourne N donc ya quasi aucun travail en interne ca se la touche un peu
template <typename T, size_t N>
size_t arraySize(T (&)[N])
{
	return N;
}


void square(int &value)
{
	value *= value;
}

void half(double &value)
{
	value /= 2;
}

struct Doubler
{
	void operator()(int &value) const
	{
		value *= 2;
	}
};

struct Point
{
	int x;
	int y;
};

void printPoint(Point const &p)
{
	std::cout << "(" << p.x << "," << p.y << ") ";
}


//tasvucest style jutilise un autre template pour print selon le type
//dcp faut juste passer le type a print avant pour resolve T a la compil
//jai mis du temps a comprendre parceque dans ma tete e passant une liste de int 
//jsp pk jpensais que ca laurait deduit
//c bon jai compris ca marche si jassigne un pointeur de fonction deja type mais la 
//ya pas de cible pour guider le choix vu que je 
//passe ca apres que jappelle print avec iter, meme si dans iter je specifie ca marche pas vu
//que jappelle print avant bref
int main(void)
{
	int ints[] = {1, 2, 3, 4, 5};
	//on divise le nombre de ints par la taille de chaque int pour trouver le nombre delements
	//mais c moche jtrouve dcp jai aussi fait un autre template
	//si on etait pas bloque en 98 on aurait juste pu faire std::size(ints); MAIS BON je disgresse
	// size_t const intsSize = sizeof(ints) / sizeof(ints[0]);
	size_t const intsSize = arraySize(ints);
	int const constInts[] = {1, 2, 3};
	// size_t const constIntsSize = sizeof(constInts) / sizeof(constInts[0]);
	size_t const constIntsSize = arraySize(constInts);


	std::cout << CYAN <<"-------------INTS--------------" << DEFAULT <<std::endl;
	std::cout << "ints: ";
	iter(ints, intsSize, print<int>);
	std::cout << std::endl;

	std::cout << "constInts: ";
	iter(constInts, constIntsSize, print<int>);
	std::cout << std::endl;

	iter(ints, intsSize, square);
	std::cout << "ints after square: ";
	iter(ints, intsSize, print<int>);
	std::cout << std::endl;

	iter(ints, intsSize, Doubler());
	std::cout << "ints after Doubler: ";
	iter(ints, intsSize, print<int>);
	std::cout << std::endl;

	//cette ligne marche pas dcp parceque si on passe a iter des consts, il peut pas acceder a 
	// iter(constInts, constIntsSize, square);


	std::cout << CYAN <<"-------------DOUBLES--------------" << DEFAULT <<std::endl;
	double doubles[] = {1.0, 3.0, 9.0, 27.0};
	// size_t const doublesSize = sizeof(doubles) / sizeof(doubles[0]);
	size_t const doublesSize = arraySize(doubles);

	std::cout << "doubles :";
	iter(doubles, doublesSize, print<double>);
	std::cout << std::endl;
	iter(doubles, doublesSize, half);
	std::cout << "doubles after half: ";
	iter(doubles, doublesSize, print<double>);
	std::cout << std::endl;


	std::cout << CYAN <<"-------------DEMONS (trouver lintrus)--------------" << DEFAULT <<std::endl;
	std::string words[] = {"Sarkozy", "Baal", "Moloch", "Bush", "Homura Akemi", "Miki Sayaka"};
	// size_t const wordsSize = sizeof(words) / sizeof(words[0]);
	size_t const wordsSize = arraySize(words);

	std::cout << "words: ";
	iter(words, wordsSize, print<std::string>);
	std::cout << std::endl;


	std::cout << CYAN <<"-------------points (tableau)--------------" << DEFAULT <<std::endl;
	Point points[] = {{0, 0}, {10, 20}, {30, 444}};
	// size_t const pointsSize = sizeof(points) / sizeof(points[0]);
	size_t const pointsSize = arraySize(points);

	std::cout << "points: ";
	iter(points, pointsSize, printPoint);
	std::cout << std::endl;

	return (0);
}
