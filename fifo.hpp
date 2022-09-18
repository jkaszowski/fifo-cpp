#ifndef _FIFO_H_
#define _FIFO_H_

#include <cstdint>
#include <iostream>

constexpr const uint32_t maxsize = 128;

class Fifo
{
	public:
		Fifo();
		~Fifo();
		friend bool operator<<(Fifo&, int&&);
		friend std::ostream& operator<<(std::ostream&, Fifo&);
		const int getFirst();

	private:
		int container [maxsize] {0};
		int* current = nullptr;
		int* first_empty = container;
};

#endif
