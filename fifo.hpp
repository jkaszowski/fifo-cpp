#ifndef _FIFO_H_
#define _FIFO_H_

#include <cstdint>
#include <iostream>


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
		int* current = nullptr;
		int* first_empty = container;
};

#endif
