#include <ratexpr/expression.hpp>
#include <utility>
using namespace ratexpr;

Const::Const(const Fraction& value)
	: a(value) {}

Fraction Const::evaluate() const{
	return a;
}

void Const::print(std::ostream& os) const {
	os << a;
}

Negative::Negative(std::unique_ptr<Expression> operand) 
	: p(std::move(operand)) {}
Fraction Negative::evaluate() const {
	return -p->evaluate();
}
void Negative::print(std::ostream& os) const {
	os << "(-";
	p->print(os);
	os << ')';
}

BinaryExpression::BinaryExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
	: m(std::move(lhs)), n(std::move(rhs)) {}

Add::Add(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs) 
	: BinaryExpression(std::move(lhs), std::move(rhs)) {}

Fraction Add::evaluate() const {
	return m->evaluate() + n->evaluate();
}

void Add::print(std::ostream& os) const {
	os << '(';
	m->print(os);
	os << " + ";
	n->print(os);
	os << ')';
}

Sub::Sub(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
	: BinaryExpression(std::move(lhs), std::move(rhs)) {
}

Fraction Sub::evaluate() const {
	return m->evaluate() - n->evaluate();
}

void Sub::print(std::ostream& os) const {
	os << '(';
	m->print(os);
	os << " - ";
	n->print(os);
	os << ')';
}

Mul::Mul(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
	: BinaryExpression(std::move(lhs), std::move(rhs)) {
}

Fraction Mul::evaluate() const {
	return m->evaluate() * n->evaluate();
}

void Mul::print(std::ostream& os) const {
	os << '(';
	m->print(os);
	os << " * ";
	n->print(os);
	os << ')';
}

Div::Div(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
	: BinaryExpression(std::move(lhs), std::move(rhs)) {
}

Fraction Div::evaluate() const {
	return m->evaluate() / n->evaluate();
}

void Div::print(std::ostream& os) const {
	os << '(';
	m->print(os);
	os << " / ";
	n->print(os);
	os << ')';
}

std::ostream& ratexpr::operator<<(std::ostream& os, const Expression& e) {
	e.print(os);
	return os;
}





