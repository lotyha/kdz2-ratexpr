#pragma once
#include <ratexpr/fraction.hpp>
#include <memory>

namespace ratexpr {
	class Expression {
	public:
		virtual ~Expression() = default;
		virtual Fraction evaluate() const = 0;
		virtual void print(std::ostream& os) const = 0;
	};
	std::ostream& operator<<(std::ostream& os, const Expression& e);
	class Const : public Expression {
		Fraction a;
	public:
		explicit Const(const Fraction& value);
		Fraction evaluate() const override;
		void print(std::ostream & os) const override;

	};
	class Negative : public Expression {
		std::unique_ptr<Expression> p;
	public:
		explicit Negative(std::unique_ptr<Expression> operand);
		Fraction evaluate() const override;
		void print(std::ostream& os) const override;
	};
	class BinaryExpression : public Expression {
	protected:
		std::unique_ptr<Expression> m;
		std::unique_ptr<Expression> n;
	public:
		BinaryExpression(std::unique_ptr<Expression> lhs,
			std::unique_ptr<Expression> rhs);
	};
	class Add : public BinaryExpression { 
	public:
		Add(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs);
		Fraction evaluate() const override;
		void print(std::ostream& os) const override;
	};
	class Sub : public BinaryExpression {
	public:
		Sub(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs);
		Fraction evaluate() const override;
		void print(std::ostream& os) const override;
	};
	class Mul : public BinaryExpression {
	public:
		Mul(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs);
		Fraction evaluate() const override;
		void print(std::ostream& os) const override;
	};
	class Div : public BinaryExpression {
	public:
		Div(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs);
		Fraction evaluate() const override;
		void print(std::ostream& os) const override;
	};
}