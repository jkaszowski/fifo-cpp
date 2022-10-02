#ifndef _FIFO_H_
#define _FIFO_H_

#include <cstdint>
#include <iostream>

enum class State : uint8_t {
	EMPTY,
	NORMAL,
	FULL   
};

class Fifo
{
	public:
		Fifo();
		~Fifo();
		friend bool operator>>(Fifo& ent, const int& input);
		friend std::ostream& operator<<(std::ostream&, Fifo&);
		const int getFirst();

	private:
		static const uint32_t maxsize = 128;
		int container [maxsize] {0};
		int* current;
		int* first_empty;
		bool isEmpty;
		bool isFull;
		uint32_t counter;
		State state;
		bool increment_pointer(int**);
};

#endif
