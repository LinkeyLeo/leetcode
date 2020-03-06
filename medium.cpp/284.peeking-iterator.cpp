/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 */

// @lc code=start
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator
{
	struct Data;
	Data *data;

public:
	Iterator(const vector<int> &nums);
	Iterator(const Iterator &iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator
{
private:
	vector<int> members;
	int count;
	int pointer;

public:
	PeekingIterator(const vector<int> &nums) : Iterator(nums)
	{
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		pointer = 0;
		count = nums.size();
		members = nums;
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek()
	{
		return members[pointer];
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next()
	{
		pointer++;
		return members[pointer - 1];
	}

	bool hasNext() const
	{
		return pointer < count;
	}
};
// @lc code=end
