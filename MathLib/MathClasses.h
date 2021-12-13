#pragma once
namespace Math {
	class Vector3D;
	Template < class T>

	class Matrix
	{
		int numL;
		int numC;
		T** Matx;

	public:

		Matrix(unsigned int numC, unsigned int numL) {
			assert(numC != 0 && numL != 0);
			this->numC = numC;
			this->numL = numL;
			this->Matx = new T* [numL];
			for (int i = 0; i < numL; i++)
			{
				this->Matx[i] = new T[numC]();
			}
		}

		Matrix(const Matrix&) = delete;


		void Matrix<T>::Remplissage(T elem)
		{
			for (int i = 0; i < this->numL; i++)
			{
				for (int j = 0; j < this->numC; j++)
				{
					this->Matx[i][j] = elem;
				}
			}
		}

		Matrix& operator=(const Matrix&)const = delete;

		Matrix* Matrix<T>::operator+(const Matrix& R) const
		{
			assert(this->numC == R.numC && this->numL == R.numC);
			Matrix* pt = new Matrix(this->numC, this->numL);
			for (int i = 0; i < this->numL; i++)
			{
				for (int j = 0; j < this->numC; j++)
				{
					pt->Matx[i][j] = this->Matx[i][j] + R.Matx[i][j];
				}
			}
			return pt;
		}


		Matrix* Matrix<T>::operator-(const Matrix& R) const
		{
			assert(this->numC == R.numC && this->numL == R.numC);
			Matrix* pt = new Matrix(this->numC, this->numL);
			for (int i = 0; i < this->numL; i++)
			{
				for (int j = 0; j < this->numC; j++)
				{
					pt->Matx[i][j] = this->Matx[i][j] - R.Matx[i][j];
				}
			}
			return pt;
		}
		Matrix* Matrix<T>::operator*(const Matrix& R) const
		{
			assert(this->numC == R.numL);

			Matrix* nM = new Matrix(R.numC, this->numL);
			for (int i = 0; i < nM->numL; i++)
			{
				for (int j = 0; j < nM->numC; j++)
				{
					nM->Matx[i][j] = 0;
					for (int k = 0; k < this->numC; k++)
					{
						nM->Matx[i][j] += this->Matx[i][k] * R.Matx[k][j];
					}
				}
			}
			return nM;
		}

		Matrix* Matrix<T>::operator*(int elem) const
		{
			Matrix* pt = new Matrix(this->numC, this->numL);
			for (int i = 0; i < this->numL; i++)
			{
				for (int j = 0; j < this->numC; j++)
				{
					pt->Matx[i][j] = this->Matx[i][j] * elem;
				}
			}
			return pt;
		}
		Matrix* operator[](int i) {
			assert(this->numL > i);
			return this->Matx[i];
		}

		Vector3D* TurnToVect() {
			assert(this->numL == 1 && this->numC == 3);
			Vector3D* E = new Vector3D();
			for (int i = 0; i < 3; i++)
			{
				(*E)[i] = (*this)[0][i];
			}
			return E;
		}

		void Matrix<T>::Print() const
		{
			cout << endl << "{ ";
			for (int i = 0; i < this->numL; i++)
			{
				for (int j = 0; j < this->numC; j++)
				{
					cout << this->Matx[i][j];
					if (j != this->numC - 1) cout << ",";
				}
				if (this->numL - 1 != i)cout << endl << "  ";
			}
			cout << " }";
		}

		Matrix::~Matrix()
		{
			for (int i = 0; i < this->numL; i++)
			{
				delete[] this->Matx[i];
				this->Matx[i] = NULL;
			}
			delete this->Matx;
			this->Matx = NULL;
		}

	};
	template<class F>
	class Vector3D
	{
		F Vect[3];
	public:
		Vector3D(const Vector3D&) = delete;

		Math::Vector3D::Vector3D(F x, F y, F z)
		{
			this->Vect[0] = x;
			this->Vect[1] = y;
			this->Vect[2] = z;
		}



		void Math::Vector3D::Print()
		{
			cout << "{ " << this->Vect[0] << ", " << this->Vect[1] << ", " << this->Vect[2] << " }";
		}


		float Math::Vector3D::at(unsigned int a)const
		{
			try
			{
				if (a >= 0 && a <= 2)return this->Vect[a];
				throw "range error";
			}
			catch (string S)
			{
				cout << S << endl;
			}
			float b = 0.0;
			return b;
		}

		float& Math::Vector3D::operator[](unsigned int a)
		{
			try
			{
				if (a >= 0 && a <= 2)return this->Vect[a];
				throw "range error";
			}
			catch (string S)
			{
				cout << S << endl;
			}
			float b = 0.0;
			return b;
		}

		bool Math::Vector3D::operator==(const Vector3D& B)const
		{
			for (int i = 0; i < 3; i++)
			{
				if (this->Vect[i] != B.Vect[i])return false;
			}
			return true;
		}


		bool Math::Vector3D::operator!=(const Vector3D& B)const
		{
			return !(*this == B);
		}

		Vector3D& operator=(const Vector3D&) = delete;

		Matrix* Math::Vector3D::TurnToMatrix()
		{
			Matrix<T>* New = new Matrix<T>(3, 1);
			for (int i = 0; i < 3; i++)
			{
				(*New)[0][i] = (*this)[i];
			}
			return New;
		}

	};
};