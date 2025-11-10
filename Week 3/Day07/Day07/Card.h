#pragma once
#include <string>
class Card
{
public:

	Card(const std::string& face, const std::string& suit)
		: face_(face), suit_(suit)
	{
	}

	const std::string& Face() const	{ return face_;	}
	void Face(const std::string& face) {
		if (face.size() > 0)
			face_ = face;
	}
	const std::string& Suit() const	{ return suit_;	}
	void Suit(const std::string& suit) {
		if (suit.size() > 0)
			suit_ = suit;
	}

	int Value() const;
	void Print() const;

private:
	std::string face_, suit_;

};

