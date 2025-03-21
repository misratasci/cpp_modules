#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int value;
		static const int fractional_bits = 8;

	public:
		Fixed();
		Fixed(Fixed const &src);
		~Fixed();

		Fixed& operator=(Fixed const &obj);
		int getRawBits(void) const;
		void setRawBits(int const raw);

};

#endif