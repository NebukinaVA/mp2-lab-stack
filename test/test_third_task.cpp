#include "third_task.h"

#include <gtest.h>

TEST(Minumim, can_create_stack)
{
	ASSERT_NO_THROW(StackWithMinimum<int> s);
}

TEST(Minimum, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(StackWithMinimum<int> s(-5));
}

TEST(Minimum, can_check_if_stack_is_empty)
{
	StackWithMinimum<int> s;

	EXPECT_TRUE(s.IsEmpty());
}

TEST(Minimum, can_push)
{
	StackWithMinimum<int> s;

	ASSERT_NO_THROW(s.Push(1));
}
TEST(Minimum, can_pop)
{
	StackWithMinimum<int> s;

	s.Push(1);

	ASSERT_NO_THROW(s.Pop());
}

TEST(Minimum, throws_when_pop_from_empty_stack)
{
	StackWithMinimum<int> s;

	ASSERT_ANY_THROW(s.Pop());
}

TEST(Minimum, can_check_whether_stack_is_empty)
{
	StackWithMinimum<int> s;

	EXPECT_TRUE(s.IsEmpty());
}

TEST(Minimum, can_check_if_stack_is_full)
{
	StackWithMinimum<int> s(3);

	s.Push(1);
	s.Push(1);
	s.Push(1);

	EXPECT_TRUE(s.IsFull());
}

TEST(Minimum, throws_when_get_minimum_from_empty_stack)
{
	StackWithMinimum<int> s;

	ASSERT_ANY_THROW(s.GetMin());
}

TEST(Minimum, can_get_minimum_with_push_only)
{
	StackWithMinimum<int> s;

	s.Push(1);
	s.Push(2);
	s.Push(3);

	EXPECT_EQ(1, s.GetMin());
}

TEST(Minimum, can_get_minimum_with_push_and_pop)
{
	StackWithMinimum<int> s;

	s.Push(1);
	s.Push(10);
	s.Push(0);
	s.Push(-2);
	s.Pop();

	EXPECT_EQ(0, s.GetMin());
}