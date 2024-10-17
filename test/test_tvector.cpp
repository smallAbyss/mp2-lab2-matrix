#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

/*
* remooved because using size_t
TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}
*/

TEST(TDynamicVector, can_create_copied_vector)
{
	TDynamicVector<int> v(10);

	ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> v1(v);

	EXPECT_EQ(v1, v);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> v1(v);

	v[0] = 1;
	v1[0] = 123456;
	EXPECT_NE(v1[0], v[0]);
}

TEST(TDynamicVector, can_get_size)
{
	TDynamicVector<int> v(4);

	EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
	TDynamicVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(10);

	EXPECT_ANY_THROW(v.at(-1));
}
///

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(10);

	EXPECT_ANY_THROW(v.at(100));
}

///
TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(10);
	v[0] = 123;
	v = v;
	EXPECT_EQ(v[0], 123);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v1(3), v2(3);
	v1[0] = 1;
	v1[1] = 100;
	v1[2] = 789;
	v2 = v1;

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v1(10), v2(2);
	v2 = v1;

	EXPECT_EQ(v2.size(), 10);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v1(2), v2(3);
	v1[0] = 1;
	v1[1] = 789;
	v2 = v1;

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v1(2), v2(2);
	v1[0] = 1; v1[1] = 789;
	v2[0] = 1; v2[1] = 789;

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v1(2);
	v1[0] = 1; v1[1] = 789;

	EXPECT_EQ(v1, v1);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v1(2), v2(3);
	v1[0] = 1; v1[1] = 789;
	v2[0] = 1; v2[1] = 5; v2[2] = 789;

	EXPECT_NE(v1, v2);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v1(2), v2(2);
	v1[0] = 1; v1[1] = 789;
	for (int i = 0; i < 2; i++)
		v2[i] = v1[i] + 5;

	v1 = v1 + 5;

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v1(2), v2(2);
	v1[0] = 1; v1[1] = 789;
	for (int i = 0; i < 2; i++)
		v2[i] = v1[i] - 5;

	v1 = v1 - 5;

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v1(2), v2(2);
	v1[0] = 1; v1[1] = 789;
	for (int i = 0; i < 2; i++)
		v2[i] = v1[i] * 5;

	v1 = v1 * 5;

	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2), v2(2), v3(2), v4(2);
	v1[0] = 1; v1[1] = 789;
	v2[0] = 10; v2[1] = 35;
	for (int i = 0; i < 2; i++)
		v4[i] = v1[i] + v2[i];
	v3 = v1 + v2;

	EXPECT_EQ(v3, v4);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(2), v2(3);
	v1[0] = 1; v1[1] = 789;
	v2[0] = 10; v2[1] = 35;  v2[2] = 35;

	EXPECT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2), v2(2), v3(2), v4(2);
	v1[0] = 1; v1[1] = 789;
	v2[0] = 10; v2[1] = 35;
	for (int i = 0; i < 2; i++)
		v4[i] = v1[i] - v2[i];

	v3 = v1 - v2;

	EXPECT_EQ(v3, v4);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(2), v2(3);
	v1[0] = 1; v1[1] = 789;
	v2[0] = 10; v2[1] = 35;  v2[2] = 35;

	EXPECT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2), v2(2);
	int mult = 0, ans = 0;
	v1[0] = 1; v1[1] = 789;
	v2[0] = 10; v2[1] = 35;

	for (int i = 0; i < 2; i++)
		ans += v1[i] * v2[i];

	mult = v1 * v2;

	EXPECT_EQ(ans, mult);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(2), v2(3);
	v1[0] = 1; v1[1] = 789;
	v2[0] = 10; v2[1] = 35; v2[2] = 35;

	EXPECT_ANY_THROW(v1 * v2);
}