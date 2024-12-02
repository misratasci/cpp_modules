#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int value;
		static const int fractional_bits;

	public:
		Fixed();
		~Fixed();

};

#endif