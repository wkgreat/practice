#ifndef VECTOR_H_
#define VECTOR_H_

#include<iostream>


namespace VECTOR
{
	class Vector
	{
		private:
			enum Mode {RECT, POL};
			double x;
			double y;
			double mag;
			double ang;
			Mode mode;

			void set_x();
			void set_y();
			void set_mag();
			void set_ang();

		public:
			Vector();
			Vector(double n1, double n2, Mode form = RECT);
			void reset(double n1, double n2);
			~Vector();
			double xval() const { return x; }
			double yval() const { return y; }
			double magval() const { return mag; }
			double angval() const { return ang; }
			void rect_mode() { mode=RECT; }
			void pol_mode() { mode=POL; }

			//operator overload
			Vector operator+(const Vector & vector) const;
			Vector operator-(const Vector & vector) const;
			Vector operator-() const;
			Vector operator*(double n) const;

			//friend
			friend Vector operator*(double n, const Vector & vector) { return vector*n; }
			friend std::ostream & operator<<(std::ostream & os, const Vector & vector);
			friend Mode getMode(int n);
			

	};
}

#endif
