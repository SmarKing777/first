#include <iostream>
using namespace std;

class Vector {
private:
	int vc[5];
public:
	void InputMatrix(int s) {
		cin >> vc[s];
	}
	void Vector1(int s) {
		static int arr = 0;
		vc[arr] = s;
		if (arr == 4) arr = -1;
		arr++;
	}

	int* GetVector() {
		return vc;
	}

	friend void OutputVector(Vector* S, int h);


	void margain(int start, int middle, int end) {
		int a[5];
		int i = start, j = middle + 1, g = 0;

		while (i <= middle && j <= end) {
			if (this->vc[i] >= this->vc[j]) {
				a[g] = this->vc[i];
				g++;
				i++;
			}
			else {
				a[g] = this->vc[j];
				g++;
				j++;
			}
		}

		while (i <= middle) {
			a[g] = this->vc[i];
			g++;
			i++;
		}

		while (j <= end) {
			a[g] = this->vc[j];
			g++;
			j++;
		}
		for (i = start; i <= end; i++) {
			this->vc[i] = a[i - start];
		}
	}

	void Sort(int start, int end) {

		if (start < end) {
			int middle = (start + end) / 2;
			Sort(start, middle);
			Sort(middle + 1, end);
			margain(start, middle, end);
		}

	}
};

void OutputVector(Vector* vc, int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << vc->vc[i];
	}
	cout << endl;
}


int main() {
	Vector matrix[5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			matrix[j].InputMatrix(i);
		}
	Vector matrix1;
	for (int i = 0; i < 5; i++)
		matrix[i].Sort(0, 4);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << matrix[j].GetVector()[i] << "\t ";
			matrix1.Vector1(matrix[j].GetVector()[i]);
		}
		cout << endl;
	}
	float sum = 0.0;
	float sum1 = 1.0, sum2 = 1.0, sum3 = 1.0, sum4 = 1.0;
	for (int i = 1; i < 5; i++) {
		sum1 *= matrix[i].GetVector()[0];
	}
	for (int i = 2; i < 5; i++) {
		sum2 *= (matrix[i].GetVector()[1]);

	}
	for (int i = 3; i < 5; i++) {
		sum3 *= (matrix[i].GetVector()[2]);

	}
	for (int i = 4; i < 5; i++) {
		sum4 *= (matrix[i].GetVector()[3]);
	}

	float q1 = sqrt(sqrt(fabs(sum1)));
	float q2 = pow(sum2, 1 / 3.0);
	float q3 = sqrt(fabs(sum3));

	cout << "\n";
	sum = (q1 + q2 + q3 + sum4);
	cout << "f(1): " << q1 << "\n" << "f(2): " << q2 << "\n" << "f(3): " << q3 << "\n" << "f(4): " << sum4 << "\n\n";
	cout << "F(f): " << sum << "\n";

	return 0;
}