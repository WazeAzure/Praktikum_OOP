#include "AddExpression.hpp"
#include <iostream>

AddExpression::AddExpression(Expression *x, Expression *y) : BinaryExpression(x, y) {}

int AddExpression::solve() {
	return x->solve() + y->solve();
}