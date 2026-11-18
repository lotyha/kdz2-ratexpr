#include <ratexpr/fraction.hpp>
#include <stdexcept>
#include <cstdlib>

void ratexpr::Fraction::normalize() {
	if (denominator_ == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
	}

    std::int64_t a = abs(numerator_);
    std::int64_t b = abs(denominator_);

    while (b != 0) {
        int64_t r = a % b;
        a = b;
        b = r;
    }

    numerator_ /= a;
    denominator_ /= a;

    if (denominator_ < 0) {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }
}

ratexpr::Fraction::Fraction() 
    : numerator_(0), denominator_(1) {}

ratexpr::Fraction::Fraction(std::int64_t numerator, std::int64_t denominator) 
    : numerator_(numerator), denominator_(denominator) {
    normalize();
}

ratexpr::Fraction& ratexpr::Fraction::operator+=(const Fraction& o) {
    numerator_ = numerator_ * o.denominator_ + o.numerator_ * denominator_;
    denominator_ = denominator_ * o.denominator_;

    normalize();

    return *this;
}

ratexpr::Fraction& ratexpr::Fraction::operator+=(std::uint32_t k) {
    numerator_ = numerator_ + k * denominator_;

    normalize();

    return *this;
}

ratexpr::Fraction& ratexpr::Fraction::operator-=(const Fraction& o) {
    numerator_ = numerator_ * o.denominator_ - o.numerator_ * denominator_;
    denominator_ = denominator_ * o.denominator_;

    normalize();

    return *this;
}

ratexpr::Fraction& ratexpr::Fraction::operator-=(std::uint32_t k) {
    numerator_ = numerator_ - k * denominator_;

    normalize();

    return *this;
}

ratexpr::Fraction& ratexpr::Fraction::operator*=(const Fraction & o){
    numerator_ = numerator_ * o.numerator_;
    denominator_ = denominator_ * o.denominator_;

    normalize();

    return *this;
}

ratexpr::Fraction& ratexpr::Fraction::operator*=(std::uint32_t k) {
    numerator_ = numerator_ * k;

    normalize();

    return *this;
}

ratexpr::Fraction& ratexpr::Fraction::operator/=(const Fraction& o) {
    if (o.numerator_ == 0) {
        throw std::invalid_argument("Division by zero");
    }

    const std::int64_t k = o.numerator_;

    numerator_ = numerator_ * o.denominator_;
    denominator_ = denominator_ * k;

    normalize();

    return *this;
}

ratexpr::Fraction& ratexpr::Fraction::operator/=(std::uint32_t k) {
    if (k == 0) {
        throw std::invalid_argument("Division by zero");
    }

    denominator_ = denominator_ * k;

    normalize();

    return *this;
}

ratexpr::Fraction ratexpr::Fraction::operator-() const {
    Fraction m;
    m.numerator_ = -this->numerator_;
    m.denominator_ = this->denominator_;
    return m;
}

ratexpr::Fraction ratexpr::operator+(const Fraction& a, const Fraction& b) {
    Fraction m = a;
    m += b;
    return m;
}

ratexpr::Fraction ratexpr::operator+(const Fraction& a, std::uint32_t k) {
    Fraction m = a;
    m += k;
    return m;
}

ratexpr::Fraction ratexpr::operator+(std::uint32_t k, const Fraction& a) {
    Fraction m = a;
    m += k;
    return m;
}

ratexpr::Fraction ratexpr::operator-(const Fraction& a, const Fraction& b) {
    Fraction m = a;
    m -= b;
    return m;
}

ratexpr::Fraction ratexpr::operator-(const Fraction& a, std::uint32_t k) {
    Fraction m = a;
    m -= k;
    return m;
}

ratexpr::Fraction ratexpr::operator-(std::uint32_t k, const Fraction& a) {
    Fraction m = -a;
    m += k;
    return m;
}

ratexpr::Fraction ratexpr::operator*(const Fraction& a, const Fraction& b) {
    Fraction m = a;
    m *= b;
    return m;
}

ratexpr::Fraction ratexpr::operator*(const Fraction& a, std::uint32_t k) {
    Fraction m = a;
    m *= k;
    return m;
}

ratexpr::Fraction ratexpr::operator*(std::uint32_t k, const Fraction& a) {
    Fraction m = a;
    m *= k;
    return m;
}

ratexpr::Fraction ratexpr::operator/(const Fraction& a, const Fraction& b) {
    Fraction m = a;
    m /= b;
    return m;
}

ratexpr::Fraction ratexpr::operator/(const Fraction& a, std::uint32_t k) {
    Fraction m = a;
    m /= k;
    return m;
}

ratexpr::Fraction ratexpr::operator/(std::uint32_t k, const Fraction& a) {
    Fraction m = Fraction(a.denominator_, a.numerator_);
    m *= k;
    return m;
}

std::ostream& ratexpr::operator<<(std::ostream& os, const Fraction& f) {
    if (f.denominator_ == 1) {
        os << f.numerator_;
    }
    else {
        os << f.numerator_ << '/' << f.denominator_;
    }
    return os;
}