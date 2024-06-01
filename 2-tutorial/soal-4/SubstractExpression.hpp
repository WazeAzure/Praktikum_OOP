#ifndef SUBSTRACT_EXPRESSION_H
#define SUBSTRACT_EXPRESSION_H

#include "Expression.hpp"
#include <iostream>

class SubstractExpression : public BinaryExpression {
public:
	SubstractExpression(Expression *x, Expression *y);
	int solve();
};

#endif