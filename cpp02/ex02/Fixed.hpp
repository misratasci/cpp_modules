#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int value;
		static const int fractional_bits = 8;

	public:
		Fixed();
		Fixed(Fixed const &src);
		Fixed(int const num);
		Fixed(float const flo);
		~Fixed();

		Fixed& operator=(Fixed const &obj);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int	 toInt(void) const;
		bool operator>(Fixed const obj);
		bool operator<(Fixed const obj);
		bool operator>=(Fixed const obj);
		bool operator<=(Fixed const obj);
		bool operator==(Fixed const obj);
		bool operator!=(Fixed const obj);
		float operator+(Fixed const obj);
		float operator-(Fixed const obj);
		float operator*(Fixed const obj);
		float operator/(Fixed const obj);
		Fixed operator++(void);
		Fixed operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

};

std::ostream& operator<<(std::ostream& o, Fixed const &obj);

#endif