// CS106B: Programming Abstractions Assignment 6 Problem 4

#include <iostream>
#include <queue>

using namespace std;

struct movieT {
	string title;
	string genre;
	int rating;
};

void printMovieQueue(queue<movieT> q) {
	while (!q.empty()) {
		cout << q.front().title << endl;
		q.pop();
	}

	cout << endl;
}

bool isBadComedy(movieT & m) {
	return (m.genre == "comedy" && m.rating < 7);
}

bool isGoodAction(movieT & m) {
	return (m.genre == "action" && m.rating > 8);
}

template <typename Type>
void filter(queue<Type> & q, bool f(Type & t)) {
	queue<Type> filteredQueue;

	while (!q.empty()) {
		if (f(q.front())) {
			// do nothing
		} else {
			filteredQueue.push(q.front());
		}

		q.pop();
	}

	q = filteredQueue;
}

int main() {
	movieT test1;
	test1.title = "Generic Comedy 2: The Punchline";
	test1.genre = "comedy";
	test1.rating = 5;

	movieT test2;
	test2.title = "Good Comedy";
	test2.genre = "comedy";
	test2.rating = 8;

	movieT test3;
	test3.title = "Bames Jond: Peasant Casino";
	test3.genre = "action";
	test3.rating = 9;

	movieT test4;
	test4.title = "Harry Potter and the Invisibility Spell";
	test4.genre = "fantasy";
	test4.rating = 7;

	queue<movieT> myMovies;
	myMovies.push(test1);
	myMovies.push(test2);
	myMovies.push(test3);
	myMovies.push(test4);

	cout << "My original queue of movies:" << endl;
	printMovieQueue(myMovies);

	filter(myMovies, isBadComedy);
	cout << "After filtering out bad comedies:" << endl;
	printMovieQueue(myMovies);

	filter(myMovies, isGoodAction);
	cout << "After filtering out good action movies:" << endl;
	printMovieQueue(myMovies);
	
	return 0;
}