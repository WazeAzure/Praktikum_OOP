#ifndef NEGATIVE_EXPRESSION_H
#define NEGATIVE_EXPRESSION_H

#include "Expression.hpp"
#include <iostream>

class NegativeExpression : public UnaryExpression {
public:
	NegativeExpression(Expression *x);
	int solve();
};

#endif