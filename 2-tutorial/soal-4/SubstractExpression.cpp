#include "SubstractExpression.hpp"
#include <iostream>

SubstractExpression::SubstractExpression(Expression *x, Expression *y) : BinaryExpression(x, y) {}

int SubstractExpression::solve() {
	return x->solve() - y->solve();
}