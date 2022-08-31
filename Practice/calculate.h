#ifndef CALCULATE_H_
#define CALCULATE_H_
namespace sdds
{
	template <typename t>
	t& mult(const t* x, int n) {
		t mult = 1.0;
		for (int i = 0; i < n; i++)
			mult *= x[i];
		return mult;
	}
}
#endif // !SEARCH_H_
