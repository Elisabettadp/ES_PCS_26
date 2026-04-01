#pragma once

#include <iostream>
#include <numeric>
#include <concepts>

template<typename I> requires std::integral<I> 
class rational 
{

    I num_; 
    I den_; 
    
    void normalizza() {
        if (den_ == I{0}) {
            if (num_ > I{0}) num_ = I{1};
            else if (num_ < I{0}) num_ = I{-1};
            return;
        }

        I mcd = std::gcd(num_, den_); //semplifica
        num_ /= mcd;
        den_ /= mcd;

        if (den_ < I{0}) {  //gestisce negativi
            den_ = -den_;
            num_ = -num_;
        }
    }

public:
	/* Costruttore di default */
    rational() : num_(I{0}), den_(I{1}) {}
    
	/* Costruttore user-defined */
    rational(const I& pnum, const I& pden) : 
		num_(pnum), den_(pden) {
        normalizza();
    }
	
    /* Restituiscono i valori di num e den */
    I num() const { return num_; }
    I den() const { return den_; }
    
	
    bool is_inf() const { return den_ == I{0} && num_ != I{0}; }
    bool is_nan() const { return den_ == I{0} && num_ == I{0}; }

    // Operatore per inversione di segno
    rational operator-() const {
        if (is_nan()) return *this;
        return rational(-num_, den_);
    }
	
	/* Implementazione canonica dell'incremento */
    rational& operator+=(const rational& other) {
        if (is_nan() || other.is_nan()) { 
            num_ = I{0}; den_ = I{0}; 
            return *this; 
        }
        
        if (is_inf() && other.is_inf()) {
            if ((num_ > I{0}) != (other.num_ > I{0})) {
                num_ = I{0}; den_ = I{0}; // +Inf + -Inf = NaN
            }
            return *this;
        }
        
        if (is_inf()) return *this;
        if (other.is_inf()) { 
            *this = other; 
            return *this; 
        }

        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;
        normalizza();
        return *this;
    }

    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }

    rational& operator-=(const rational& other) {
        *this += (-other);
        return *this;
    }

    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }

    rational& operator*=(const rational& other) {
        if (is_nan() || other.is_nan()) { 
            num_ = I{0}; den_ = I{0}; 
            return *this; 
        }
        
        // 0 * Inf = NaN
        if ((is_inf() && other.num_ == I{0}) || (num_ == I{0} && other.is_inf())) {
            num_ = I{0}; den_ = I{0}; 
            return *this; 
        }

        num_ *= other.num_;
        den_ *= other.den_;
        normalizza();
        return *this;
    }

    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;
    }

    rational& operator/=(const rational& other) {
        if (is_nan() || other.is_nan()) { 
            num_ = I{0}; den_ = I{0}; 
            return *this; 
        }
        
        // Inf / Inf = NaN
        if (is_inf() && other.is_inf()) {
            num_ = I{0}; den_ = I{0}; 
            return *this; 
        }

        num_ *= other.den_;
        den_ *= other.num_;
        normalizza();
        return *this;
    }

    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        return ret;
    }
};

template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& rat) {   
    if (rat.is_nan()) {
        os << "NaN";
    }
    else if (rat.is_inf()) {
        if (rat.num() > 0) os << "+Inf";
        else os << "-Inf";
    }
    else {
        os << rat.num() << "/" << rat.den();
    }
    return os;
}