#pragma once

namespace pbl
{
	template <class ForwardIterator, class Function>
	void adjacent_for_each(ForwardIterator first, ForwardIterator last, Function func)
	{
		if (first == last)
			return;
		ForwardIterator previous = first++;
		while (first != last)
		{
			func(*previous, *first);
			++previous;
			++first;
		}
	}
}
