#include "tqueue.h"

#include <gtest.h>

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> s);
}

TEST(TQueue, can_push)
{
	TQueue<int> q;
	ASSERT_NO_THROW(q.Push(1));
}

TEST(TQueue, no_throw_when_push_into_full_queue)
{
	TQueue<int> q(3);
	q.Push(1);
	q.Push(2);
	q.Push(3);
	ASSERT_NO_THROW(q.Push(4));
}

TEST(TQueue, can_pop)
{
	TQueue<int> q(5);
	q.Push(1);
	ASSERT_NO_THROW(q.Pop());
}

TEST(TQueue, throws_when_pop_from_empty_stack)
{
	TQueue<int> q;
	ASSERT_ANY_THROW(q.Pop());
}

TEST(TQueue, no_throw_when_many_pushes_and_pops)
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	q.Pop();
	q.Push(6);
	ASSERT_NO_THROW(q.Pop());
}

TEST(TQueue, works_correctly)
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	q.Pop();
	q.Push(6);
	EXPECT_EQ(6, q[4]);
}

TEST(TQueue, throws_when_wrong_position)
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	q.Pop();
	ASSERT_ANY_THROW(q[4]);
}

TEST(TQueue, can_return_element)
{
	TQueue<int> q(5);
	q.Push(1);
	ASSERT_NO_THROW(q[0]);
}
