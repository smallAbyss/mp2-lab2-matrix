#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
	TDynamicMatrix<int> m(5);
	ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(m);
	EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(m);
	m1[0][0] = 789;

	EXPECT_NE(m[0][0], 789);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(5);

	EXPECT_EQ(m.size(), 5);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(5);
	m[3][3] = 789;

	EXPECT_EQ(m[3][3], 789);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(5);

	ASSERT_ANY_THROW(m.at(2).at(-1));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(3).at(100));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(5);
	m[0][0] = 789;
	m = m;

	EXPECT_EQ(m[0][0], 789);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	int** p = new int* [3];
	for (int i = 0; i < 3; i++)
		p[i] = new int[3] {5, 6, 7};

	TDynamicMatrix<int> m(3), m1(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m[i][j] = p[i][j];

	m1 = m;

	EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	int** p = new int* [3];
	for (int i = 0; i < 3; i++)
		p[i] = new int[3] {5, 6, 7};

	TDynamicMatrix<int> m(3), m1(30);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m[i][j] = p[i][j];

	m1 = m;


	EXPECT_EQ(m1.size(), 3);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	int** p = new int* [3];
	for (int i = 0; i < 3; i++)
		p[i] = new int[3] {5, 6, 7};

	TDynamicMatrix<int> m(3), m1(30);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m[i][j] = p[i][j];

	m1 = m;
	
	EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	int** p = new int* [3];
	for (int i = 0; i < 3; i++)
		p[i] = new int[3] {5, 6, 7};

	TDynamicMatrix<int> m(3), m1(30);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m1[i][j] = m[i][j] = p[i][j];

	m1 = m;
	EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	int** p = new int* [3];
	for (int i = 0; i < 3; i++)
		p[i] = new int[3] {5, 6, 7};

	TDynamicMatrix<int> m(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m[i][j] = p[i][j];

	EXPECT_EQ(m, m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	int** p = new int* [3];
	for (int i = 0; i < 3; i++)
		p[i] = new int[3] {5, 6, 7};

	TDynamicMatrix<int> m(3), m1(4);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m1[i][j] = m[i][j] = p[i][j];
	m1[3][3] = 110;

	EXPECT_NE(m, m1);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	int** p = new int* [3];
	for (int i = 0; i < 3; i++)
		p[i] = new int[3] {5, 6, 7};

	TDynamicMatrix<int> m(3), m1(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = p[i][j];
			m1[i][j] = 10;
		}

	TDynamicMatrix<int> m2(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			m2[i][j] = p[i][j] + 10;
		}

	EXPECT_EQ(m2, m1 + m);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	int** p = new int* [3];
	for (int i = 0; i < 3; i++)
		p[i] = new int[3] {5, 6, 7};

	TDynamicMatrix<int> m(3), m1(4);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = p[i][j];
			m1[i][j] = 10;
		}

	EXPECT_ANY_THROW(m1 + m);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	int** p = new int* [3];
	for (int i = 0; i < 3; i++)
		p[i] = new int[3] {5, 6, 7};

	TDynamicMatrix<int> m(3), m1(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = p[i][j];
			m1[i][j] = 10;
		}

	TDynamicMatrix<int> m2(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			m2[i][j] = 10 - p[i][j];
		}

	EXPECT_EQ(m2, m1 - m);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	int** p = new int* [3];
	for (int i = 0; i < 3; i++)
		p[i] = new int[3] {5, 6, 7};

	TDynamicMatrix<int> m(3), m1(4);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = p[i][j];
			m1[i][j] = 10;
		}

	EXPECT_ANY_THROW(m - m1);
}