#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;


class Matrix
{
public:

	vector<vector<float> >  arr;
	int rows;
	int column;


};

class Complex
{
public:

	float real, img;
	string subR;
	string subI;



	vector<vector<float> >  arr;
	int rows;
	int column;

	///////////////////////
	//////////SET//////////
	///////////////////////

	void initialize()
	{
		real = 0;
		img = 0;
		subR = "";
		subI = "";
	}
	void setReal(float r)
	{
		real = r;
	}
	void setImg(float i)
	{
		img = i;
	}
	void setComplex(float r, float i)
	{
		real = r;
		img = i;
	}

	void set_STR_complex(string subinput)
	{
		int s = 1;
		for (int i = 0; i < subinput.length(); i++)
		{
			if ((i != 0 && (subinput[i] == '+' || subinput[i] == '-')))
				break;
			subR += subinput[i];
		}
		for (int i = 1; i < subinput.length(); i++)
		{
			if (subinput[i] == '+' || subinput[i] == '-')
			{
				s = i;
				break;
			}
		}
		for (int i = s; i < subinput.length(); i++)
		{
			if (subinput[i] == '-')
				subI = "-";
			if (i != s)
			{
				string SS;
				SS += subinput[i];
				subI += subinput[i];
			}
		}
	}



	///////////////////////
	//////////GET//////////
	///////////////////////

	string getsubR()
	{
		return subR;
	}
	string getsubI()
	{
		return subI;
	}

	float getReal()
	{
		return real;
	}
	float getImg()
	{
		return img;
	}

	float get_STR_Real()
	{
		real = atof(subR.c_str());
		return real;
	}
	float get_STR_Img()
	{
		img = atof(subI.c_str());
		return img;
	}


	/*float getComplex()
	{
	return real;
	return Img;
	}*/

	Complex()
	{
		real = 0;
		img = 0;
		subR = "";
		subI = "";
	}

};

/*
bool img(string subinput)
{
for (int i = 0; i < subinput.length(); i++)
{
if ((subinput[i] == 'i'))
return true;
else
return false;
}
}
bool real(string subinput)
{
for (int i = 1; i < subinput.length(); i++)
{
if ((subinput[i] == 'i'))
{

if ((subinput[i] == '+'))
return true;
else
return false;
}
}
}*/

vector<vector<float> > convert_to_REAL_vector(string input)
{
	vector<vector<float> >arr;
	string value = "";
	Complex strvalue;




	float real;

	int row_number = -1;
	for (int i = 0; i<input.length(); i++)
	{
		if (input[i] == '[' || input[i] == ';')
		{
			if (input[i] == ';')
			{
				strvalue.set_STR_complex(value);
				real = strvalue.get_STR_Real();
				arr[row_number].push_back(real);
				strvalue.initialize();
				value = "";
			}
			arr.push_back(vector<float>());
			row_number += 1;
		}
		else if (input[i] != ' ' && input[i] != ']')
		{
			value += input[i];
		}
		else if (input[i] == ' ')
		{
			strvalue.set_STR_complex(value);
			real = strvalue.get_STR_Real();
			arr[row_number].push_back(real);
			strvalue.initialize();
			value = "";

		}
		else if (input[i] == ']')
		{
			strvalue.set_STR_complex(value);
			real = strvalue.get_STR_Real();
			arr[row_number].push_back(real);
			strvalue.initialize();
			value = "";
		}
	}
	return arr;
}

vector<vector<float> > convert_to_IMG_vector(string input)
{
	vector<vector<float> >arr;
	string value = "";
	Complex strvalue;

	float img;

	int row_number = -1;
	for (int i = 0; i<input.length(); i++)
	{
		if (input[i] == '[' || input[i] == ';')
		{
			if (input[i] == ';')
			{
				strvalue.set_STR_complex(value);
				img = strvalue.get_STR_Img();
				arr[row_number].push_back(img);
				strvalue.initialize();
				value = "";
			}
			arr.push_back(vector<float>());
			row_number += 1;
		}
		else if (input[i] != ' ' && input[i] != ']')
		{
			value += input[i];
		}
		else if (input[i] == ' ')
		{
			strvalue.set_STR_complex(value);
			img = strvalue.get_STR_Img();
			arr[row_number].push_back(img);
			strvalue.initialize();
			value = "";

		}
		else if (input[i] == ']')
		{
			strvalue.set_STR_complex(value);
			img = strvalue.get_STR_Img();
			arr[row_number].push_back(img);
			strvalue.initialize();
			value = "";
		}
	}
	return arr;
}


bool check_rows(vector<vector<float> >  input)
{
	for (int i = 0; i<input.size() - 1; i++)
	{

		if (input[i].size() != input[i + 1].size())
			return false;
	}
	return true;
}

/*

float ​d = 1.55;
string ​str1;
ostringstream ​s;
​s << ​d;
​str = ​s.str();

cout << str << endl;

*/

float Complex_REAL_multiplcation(Complex one, Complex two)
{
	Complex res;
	res.real = one.real * two.real - one.img * two.img;
	return res.real;
}
float Complex_IMG_multiplcation(Complex one, Complex two)
{
	Complex res;
	res.img = one.img * two.real + one.real * two.img;
	return res.img;
}

Matrix REAL_multiplcation(Matrix R_matrix1, Matrix R_matrix2, Matrix I_matrix1, Matrix I_matrix2)
{
	Matrix R_result;

	bool check1 = check_rows(R_matrix1.arr);
	bool check2 = check_rows(R_matrix2.arr);

	Complex one;
	Complex two;
	Complex res;


	if (check1 && check2)
	{
		R_matrix1.rows = R_matrix1.arr.size();
		R_matrix1.column = R_matrix1.arr[0].size();
		I_matrix1.rows = I_matrix1.arr.size();
		I_matrix1.column = I_matrix1.arr[0].size();


		R_matrix2.rows = R_matrix2.arr.size();
		R_matrix2.column = R_matrix2.arr[0].size();
		I_matrix2.rows = I_matrix2.arr.size();
		I_matrix2.column = I_matrix2.arr[0].size();

		R_result.rows = R_matrix1.rows;
		R_result.column = R_matrix1.column;

		if (R_matrix1.column == I_matrix2.rows)
		{
			R_result.rows = R_matrix1.rows;
			R_result.column = R_matrix2.column;

			for (int i = 0; i < R_result.rows; i++)
			{
				R_result.arr.push_back(vector<float>());
				for (int j = 0; j < R_result.column; j++)
				{

					for (int k = 0; k < R_matrix1.arr[i].size(); k++)
					{
						if (k == 0)
						{
							R_result.arr[i].push_back(0);
						}
						one.real = R_matrix1.arr[i][k];
						one.img = I_matrix1.arr[i][k];

						two.real = R_matrix2.arr[k][j];
						two.img = I_matrix2.arr[k][j];


						/*float aR = R_matrix1.arr[i][j];
						float aI = I_matrix1.arr[i][j];
						float bR = R_matrix2.arr[i][j];
						float bI = I_matrix2.arr[i][j];*/

						R_result.arr[i][j] += Complex_REAL_multiplcation(one, two);
						//I_result.arr[i][j] += Complex_IMG_multiplcation(one, two);

						float cR = R_result.arr[i][j];


						//R_result.arr[i][j] += R_matrix1.arr[i][k] * I_matrix2.arr[k][j];
					}
					//cout << R_result.arr[i][j] << " ";
				}
				//cout << endl;
			}


		}
		else
		{
			cout << "ERROR";
		}


	}
	else
	{
		cout << "ERROR";
	}
	return R_result;
}
Matrix IMG_multiplcation(Matrix R_matrix1, Matrix R_matrix2, Matrix I_matrix1, Matrix I_matrix2)
{
	Matrix I_result;

	bool check1 = check_rows(R_matrix1.arr);
	bool check2 = check_rows(R_matrix2.arr);

	Complex one;
	Complex two;
	Complex res;


	if (check1 && check2)
	{
		R_matrix1.rows = R_matrix1.arr.size();
		R_matrix1.column = R_matrix1.arr[0].size();
		I_matrix1.rows = I_matrix1.arr.size();
		I_matrix1.column = I_matrix1.arr[0].size();


		R_matrix2.rows = R_matrix2.arr.size();
		R_matrix2.column = R_matrix2.arr[0].size();
		I_matrix2.rows = I_matrix2.arr.size();
		I_matrix2.column = I_matrix2.arr[0].size();

		I_result.rows = R_matrix1.rows;
		I_result.column = R_matrix1.column;

		if (R_matrix1.column == I_matrix2.rows)
		{
			I_result.rows = R_matrix1.rows;
			I_result.column = R_matrix2.column;

			for (int i = 0; i < I_result.rows; i++)
			{
				I_result.arr.push_back(vector<float>());
				for (int j = 0; j < I_result.column; j++)
				{

					for (int k = 0; k < R_matrix1.arr[i].size(); k++)
					{
						if (k == 0)
						{
							I_result.arr[i].push_back(0);
						}
						one.real = R_matrix1.arr[i][k];
						one.img = I_matrix1.arr[i][k];

						two.real = R_matrix2.arr[k][j];
						two.img = I_matrix2.arr[k][j];


						/*float aR = R_matrix1.arr[i][j];
						float aI = I_matrix1.arr[i][j];
						float bR = R_matrix2.arr[i][j];
						float bI = I_matrix2.arr[i][j];*/

						//R_result.arr[i][j] += Complex_REAL_multiplcation(one, two);
						I_result.arr[i][j] += Complex_IMG_multiplcation(one, two);

						float cR = I_result.arr[i][j];


						//R_result.arr[i][j] += R_matrix1.arr[i][k] * I_matrix2.arr[k][j];
					}
					//cout << R_result.arr[i][j] << " ";
				}
				//cout << endl;
			}


		}
		else
		{
			cout << "ERROR";
		}


	}
	else
	{
		cout << "ERROR";
	}
	return I_result;
}
Matrix m(Matrix R_matrix1, Matrix I_matrix2)
{
	string OUTPUT;

	Matrix R_result;
	bool check1 = check_rows(R_matrix1.arr);
	bool check2 = check_rows(I_matrix2.arr);



	if (check1 && check2)
	{
		R_matrix1.rows = R_matrix1.arr.size();
		R_matrix1.column = R_matrix1.arr[0].size();

		I_matrix2.rows = I_matrix2.arr.size();
		I_matrix2.column = I_matrix2.arr[0].size();

		if (R_matrix1.column == I_matrix2.rows)
		{
			R_result.rows = R_matrix1.rows;
			R_result.column = I_matrix2.column;

			for (int i = 0; i < R_result.rows; i++)
			{
				R_result.arr.push_back(vector<float>());
				for (int j = 0; j < R_result.column; j++)
				{

					for (int k = 0; k < R_matrix1.arr[i].size(); k++)
					{
						if (k == 0)
						{
							R_result.arr[i].push_back(0);
						}
						R_result.arr[i][j] += R_matrix1.arr[i][k] * I_matrix2.arr[k][j];

						float ress = R_result.arr[i][j];
					}
					//cout << R_result.arr[i][j] << " ";
				}
				//cout << endl;
			}

		}
		else
		{
			cout << "ERROR";
		}


	}
	else
	{
		cout << "ERROR";
	}
	return R_result;
}
Matrix power(Matrix R_matrix1, Matrix I_matrix1, int p)
{
	string OUTPUT;

	Matrix R_result;
	Matrix I_result;
	bool check1 = check_rows(R_matrix1.arr);



	if (check1)
	{
		R_matrix1.rows = R_matrix1.arr.size();
		R_matrix1.column = R_matrix1.arr[0].size();

		I_matrix1.rows = I_matrix1.arr.size();
		I_matrix1.column = I_matrix1.arr[0].size();


		if (R_matrix1.rows == R_matrix1.column)
		{
			R_result.rows = R_matrix1.rows;
			R_result.column = R_matrix1.column;

			I_result.rows = I_matrix1.rows;
			I_result.column = I_matrix1.column;


			for (int i = 1; i < p; i++)
			{
				if (i == 1)
				{
					R_result = REAL_multiplcation(R_matrix1, R_matrix1, I_matrix1, I_matrix1);
					I_result = IMG_multiplcation(R_matrix1, R_matrix1, I_matrix1, I_matrix1);
				}
				else
				{
					R_result = REAL_multiplcation(R_result, R_matrix1, I_result, I_matrix1);
					I_result = IMG_multiplcation(R_result, R_matrix1, I_result, I_matrix1);
				}
			}
			cout << "[";
			float valueR;
			float valueI;

			for (int i = 0; i < R_result.arr.size(); i++)
			{

				for (int j = 0; j<R_result.arr[i].size(); j++)
				{
					if (j != 0)
					{
						cout << " ";
					}
					valueR = R_result.arr[i][j];
					valueI = I_result.arr[i][j];

					if (valueI >= 0)
						cout << R_result.arr[i][j] << "+" << I_result.arr[i][j] << "i";
					else
						cout << R_result.arr[i][j] << I_result.arr[i][j] << "i";
				}

				if (i != R_result.arr.size() - 1)
					cout << ";";
				else
					cout << "]";
			}
		}
		else
		{
			cout << "ERROR";
		}


	}
	else
	{
		cout << "ERROR";
	}
	return R_result;
}



Complex Complex_multiplcation(Complex one, Complex two)
{
	Complex res;

	res.real = one.real * two.real - one.img * two.img;

	res.img = one.img * two.real + one.real * two.img;

	return res;
}
Complex Complex__IMG_multiplcation(Complex one, Complex two)
{
	Complex res;
	res.img = one.img * two.real + one.real * two.img;
	return res;
}

Complex determinant(Matrix R_matrix1, Matrix I_matrix1, int r1)
{



	R_matrix1.rows = R_matrix1.arr.size();
	R_matrix1.column = R_matrix1.arr[0].size();
	I_matrix1.rows = I_matrix1.arr.size();
	I_matrix1.column = I_matrix1.arr[0].size();


	Complex one;
	Complex two;
	Complex three;
	Complex four;

	Complex five;
	Complex six;

	Complex res;

	Complex det;
	Complex sub_det1;
	Complex sub_det2;

	Matrix R_submatrix;
	Matrix I_submatrix;


	if (r1 == 2)
	{
		one.real = R_matrix1.arr[0][0];
		one.img = I_matrix1.arr[0][0];

		two.real = R_matrix1.arr[1][1];
		two.img = I_matrix1.arr[1][1];

		three.real = R_matrix1.arr[1][0];
		four.img = I_matrix1.arr[1][0];

		two.real = R_matrix1.arr[0][1];
		two.img = I_matrix1.arr[0][1];

		five.real = Complex_REAL_multiplcation(one, two);
		five.img = Complex_IMG_multiplcation(one, two);

		six.real = Complex_REAL_multiplcation(three, four);
		six.img = Complex_IMG_multiplcation(three, four);

		res.real = five.real - six.real;
		res.img = five.img - six.img;

		return res;
	}
	else {
		for (int x = 0; x < r1; x++)
		{

			int subi = 0;
			for (int i = 1; i < r1; i++)
			{
				R_submatrix.arr.push_back(vector<float>());
				I_submatrix.arr.push_back(vector<float>());
				int subj = 0;
				for (int j = 0; j < r1; j++)
				{
					if (j == x)
						continue;
					R_submatrix.arr[subi].push_back(0);
					R_submatrix.arr[subi].push_back(0);

					R_submatrix.arr[subi][subj] = R_matrix1.arr[i][j];
					I_submatrix.arr[subi][subj] = I_matrix1.arr[i][j];
					subj++;
				}
				subi++;

			}
			sub_det1 = determinant(R_submatrix, R_submatrix, r1 - 1);

			sub_det2.real = R_matrix1.arr[0][x];
			sub_det2.img = I_matrix1.arr[0][x];

			det.real = det.real + (pow(-1, x) * Complex_REAL_multiplcation(sub_det2, sub_det1));
			det.img = det.img + (pow(-1, x) * Complex_IMG_multiplcation(sub_det2, sub_det1));
		}
	}
	return det;

}
/*
Matrix sub_det(Matrix R_matrix1, int x, int y)
{
	Matrix sub_R_result;

	int subi = 0, subj = 0;

	R_matrix1.rows = R_matrix1.arr.size();
	R_matrix1.column = R_matrix1.arr[0].size();

	sub_R_result.rows = 0;
	sub_R_result.column = -1;

	subi = 0;
	for (int i = 0; i < R_matrix1.rows; i++)
	{
		subj = 0;

		if (i != y)
		{
			sub_R_result.arr.push_back(vector<float>());
			sub_R_result.rows++;
		}

		for (int j = 0; j < R_matrix1.rows; j++)
		{
			if (j == 0)
				sub_R_result.column++;

			if (i != y && j != x)
			{
				sub_R_result.arr[subi].push_back(0);
				float num = R_matrix1.arr[i][j];
				sub_R_result.arr[subi][subj] = R_matrix1.arr[i][j];
				//cout << sub_R_result.arr[subi][subj] << " ";
				subj++;

			}
		}
		if (i != y)
			subi++;

		//cout << endl;
	}
	//cout << endl;
	return sub_R_result;
}
Matrix Inverse(Matrix R_matrix1, Matrix I_matrix1)
{
	Complex det;
	Matrix R_result;
	Matrix I_result;

	Matrix R_sub_R_result;
	Matrix I_sub_R_result;

	Matrix R_inverse;
	Matrix I_inverse;

	R_matrix1.rows = R_matrix1.arr.size();
	R_matrix1.column = R_matrix1.arr[0].size();

	det = determinant(R_matrix1, R_matrix1.rows);

	if (R_matrix1.rows == 2)
	{
		float a = R_matrix1.arr[0][1];
		float b = R_matrix1.arr[1][0];
		R_matrix1.arr[0][1] = -1 * b;
		R_matrix1.arr[1][0] = -1 * a;

		for (int i = 0; i < R_matrix1.rows; i++)
		{
			R_result.arr.push_back(vector<float>());
			for (int j = 0; j < R_matrix1.rows; j++)
			{
				R_result.arr[i].push_back(0);
				inverse.arr[i][j] = (1 / det) * R_matrix1.arr[i][j];
			}
		}

	}
	else
	{
		for (int i = 0; i < R_matrix1.rows; i++)
		{
			R_result.arr.push_back(vector<float>());
			for (int j = 0; j < R_matrix1.rows; j++)
			{
				R_result.rows = R_matrix1.arr.size();
				R_result.column = R_matrix1.arr[0].size();

				R_result.arr[i].push_back(0);

				sub_R_result = sub_det(R_matrix1, j, i);

				float sub_det = determinant(sub_R_result, (R_result.rows - 1));

				R_result.arr[i][j] = sub_det;
			}
		}
		for (int i = 0; i < R_matrix1.rows; i++)
		{
			for (int j = 0; j < R_matrix1.rows; j++)
			{
				R_result.arr[i][j] *= pow(-1, j + i);

			}
		}

		for (int i = 0; i < R_result.rows; i++)
		{
			inverse.arr.push_back(vector<float>());

			for (int j = 0; j < R_result.column; j++)
			{
				inverse.arr[i].push_back(0);
				inverse.arr[i][j] = R_result.arr[j][i];
			}
		}

		for (int i = 0; i < R_result.rows; i++)
		{
			for (int j = 0; j < R_result.column; j++)
			{
				inverse.arr[i][j] *= (1 / det);
			}
		}


		cout << "[";
		float value;

		for (int i = 0; i < inverse.arr.size(); i++)
		{

			for (int j = 0; j < inverse.arr[i].size(); j++)
			{
				if (j != 0)
				{
					cout << " ";
				}
				value = inverse.arr[i][j];

				cout << inverse.arr[i][j];
			}


			if (i != inverse.arr.size() - 1)
				cout << ";";
			else
				cout << "]";

		}
	}
	return inverse;
}


Matrix Division(Matrix R_matrix1, Matrix I_matrix2)
{
	float det;
	Matrix R_result;
	Matrix sub_R_result;
	Matrix inverse;
	Matrix div;

	R_matrix1.rows = R_matrix1.arr.size();
	R_matrix1.column = R_matrix1.arr[0].size();

	I_matrix2.rows = I_matrix2.arr.size();
	I_matrix2.column = I_matrix2.arr[0].size();

	div.rows = I_matrix2.arr.size();
	div.column = I_matrix2.arr[0].size();

	det = determinant(I_matrix2, I_matrix2.rows);

	if (I_matrix2.rows == 2)
	{
		float a = I_matrix2.arr[0][1];
		float b = I_matrix2.arr[1][0];
		I_matrix2.arr[0][1] = -1 * b;
		I_matrix2.arr[1][0] = -1 * a;

		for (int i = 0; i < I_matrix2.rows; i++)
		{
			R_result.arr.push_back(vector<float>());
			for (int j = 0; j < I_matrix2.rows; j++)
			{
				R_result.arr[i].push_back(0);
				inverse.arr[i][j] = (1 / det) * I_matrix2.arr[i][j];
			}
		}

	}
	else
	{
		for (int i = 0; i < I_matrix2.rows; i++)
		{
			R_result.arr.push_back(vector<float>());
			for (int j = 0; j < I_matrix2.rows; j++)
			{
				R_result.rows = I_matrix2.arr.size();
				R_result.column = I_matrix2.arr[0].size();

				R_result.arr[i].push_back(0);

				sub_R_result = sub_det(I_matrix2, j, i);

				float sub_det = determinant(sub_R_result, (R_result.rows - 1));

				R_result.arr[i][j] = sub_det;
			}
		}
		for (int i = 0; i < I_matrix2.rows; i++)
		{
			for (int j = 0; j < I_matrix2.rows; j++)
			{
				R_result.arr[i][j] *= pow(-1, j + i);

			}
		}

		for (int i = 0; i < R_result.rows; i++)
		{
			inverse.arr.push_back(vector<float>());

			for (int j = 0; j < R_result.column; j++)
			{
				inverse.arr[i].push_back(0);
				inverse.arr[i][j] = R_result.arr[j][i];
			}
		}

		for (int i = 0; i < R_result.rows; i++)
		{
			for (int j = 0; j < R_result.column; j++)
			{
				inverse.arr[i][j] *= (1 / det);
			}
		}
	}

	multiplcation(R_matrix1, inverse);

	return div;
}
*/
int main()
{

	///LEVEL ONE
	string input1, input2, OUTPUT;
	getline(cin, input1);

	Matrix R_matrix1;
	Matrix I_matrix1;

	Matrix R_matrix2;
	Matrix I_matrix2;

	Matrix R_result;
	Matrix I_result;



	R_matrix1.arr = convert_to_REAL_vector(input1);
	I_matrix1.arr = convert_to_IMG_vector(input1);

	/*for (int i = 0; i < R_matrix1.arr.size(); i++)
	{
	for (int j = 0; j < R_matrix1.arr[i].size(); j++)
	{
	float r = R_matrix1.arr[i][j];
	cout << R_matrix1.arr[i][j] << " ";
	}
	cout << endl;
	}

	cout << endl;

	for (int i = 0; i < I_matrix1.arr.size(); i++)
	{
	for (int j = 0; j < I_matrix1.arr[i].size(); j++)
	{
	cout << I_matrix1.arr[i][j] << " ";
	}
	cout << endl;
	}*/

	/*Complex strc;

	string str = "1255i";
	string s = "7";
	size_t f = str.find(s);

	cout << f << endl;

	string str1("There are two needles in this haystack with needles.");
	string str2("needle");
	size_t found = str1.find(str2);

	cout << found;

	strc.set_STR_complex(str);

	string R, I;

	R = strc.getsubR();

	//cout << R;
	//cout << I;*/

	/* vector<vector<float> >  arr{ {1 , 2, 3} , {4 ,5, 6} };
	cout << arr[0][1];
	cout << arr[1][0];*/
	/*string k="2.5";
	float s=atof(k.c_str());*/

	char operation;
	cin >> operation;
	cin.ignore();


	if (operation == '+')
	{

		getline(cin, input2);


		R_matrix1.arr = convert_to_REAL_vector(input1);
		I_matrix1.arr = convert_to_IMG_vector(input1);

		R_matrix2.arr = convert_to_REAL_vector(input2);
		I_matrix2.arr = convert_to_IMG_vector(input2);

		bool check1 = check_rows(R_matrix1.arr);
		bool check2 = check_rows(I_matrix2.arr);

		if (check1 && check2)
		{
			R_matrix1.rows = R_matrix1.arr.size();
			R_matrix1.column = R_matrix1.arr[0].size();
			I_matrix1.rows = I_matrix1.arr.size();
			I_matrix1.column = I_matrix1.arr[0].size();


			R_matrix2.rows = R_matrix2.arr.size();
			R_matrix2.column = R_matrix2.arr[0].size();
			I_matrix2.rows = I_matrix2.arr.size();
			I_matrix2.column = I_matrix2.arr[0].size();

			R_result.rows = R_matrix1.rows;
			R_result.column = R_matrix1.column;

			if ((R_matrix1.rows == I_matrix2.rows) && (R_matrix1.column == I_matrix2.column))
			{

				for (int i = 0; i < R_matrix1.rows; i++)
				{
					R_result.arr.push_back(vector<float>());
					I_result.arr.push_back(vector<float>());
					for (int j = 0; j < R_matrix1.column; j++)
					{
						float aR = R_matrix1.arr[i][j];
						float aI = I_matrix1.arr[i][j];
						float bR = R_matrix2.arr[i][j];
						float bI = I_matrix2.arr[i][j];

						R_result.arr[i].push_back(R_matrix1.arr[i][j] + R_matrix2.arr[i][j]);
						I_result.arr[i].push_back(I_matrix1.arr[i][j] + I_matrix2.arr[i][j]);

						float cR = R_result.arr[i][j];
						float cI = I_result.arr[i][j];
						//cout << R_result.arr[i][j] << " ";

					}
					//cout << endl;

				}

				cout << "[";
				float valueR;
				float valueI;

				for (int i = 0; i < R_result.arr.size(); i++)
				{

					for (int j = 0; j<R_result.arr[i].size(); j++)
					{
						if (j != 0)
						{
							cout << " ";
						}
						valueR = R_result.arr[i][j];
						valueI = I_result.arr[i][j];

						if (valueI >= 0)
							cout << R_result.arr[i][j] << "+" << I_result.arr[i][j] << "i";
						else
							cout << R_result.arr[i][j] << I_result.arr[i][j] << "i";
					}

					if (i != R_result.arr.size() - 1)
						cout << ";";
					else
						cout << "]";
				}
			}
			else
			{
				cout << "ERROR";
			}
		}
		else
		{
			cout << "ERROR";
		}

	}

	if (operation == '-')
	{

		getline(cin, input2);


		R_matrix1.arr = convert_to_REAL_vector(input1);
		I_matrix1.arr = convert_to_IMG_vector(input1);

		R_matrix2.arr = convert_to_REAL_vector(input2);
		I_matrix2.arr = convert_to_IMG_vector(input2);

		bool check1 = check_rows(R_matrix1.arr);
		bool check2 = check_rows(I_matrix2.arr);

		if (check1 && check2)
		{
			R_matrix1.rows = R_matrix1.arr.size();
			R_matrix1.column = R_matrix1.arr[0].size();
			I_matrix1.rows = I_matrix1.arr.size();
			I_matrix1.column = I_matrix1.arr[0].size();


			R_matrix2.rows = R_matrix2.arr.size();
			R_matrix2.column = R_matrix2.arr[0].size();
			I_matrix2.rows = I_matrix2.arr.size();
			I_matrix2.column = I_matrix2.arr[0].size();

			R_result.rows = R_matrix1.rows;
			R_result.column = R_matrix1.column;

			if ((R_matrix1.rows == I_matrix2.rows) && (R_matrix1.column == I_matrix2.column))
			{

				for (int i = 0; i < R_matrix1.rows; i++)
				{
					R_result.arr.push_back(vector<float>());
					I_result.arr.push_back(vector<float>());
					for (int j = 0; j < R_matrix1.column; j++)
					{
						float aR = R_matrix1.arr[i][j];
						float aI = I_matrix1.arr[i][j];
						float bR = R_matrix2.arr[i][j];
						float bI = I_matrix2.arr[i][j];

						R_result.arr[i].push_back(R_matrix1.arr[i][j] - R_matrix2.arr[i][j]);
						I_result.arr[i].push_back(I_matrix1.arr[i][j] - I_matrix2.arr[i][j]);

						float cR = R_result.arr[i][j];
						float cI = I_result.arr[i][j];
						//cout << R_result.arr[i][j] << " ";

					}
					//cout << endl;

				}

				cout << "[";
				float valueR;
				float valueI;

				for (int i = 0; i < R_result.arr.size(); i++)
				{

					for (int j = 0; j<R_result.arr[i].size(); j++)
					{
						if (j != 0)
						{
							cout << " ";
						}
						valueR = R_result.arr[i][j];
						valueI = I_result.arr[i][j];

						if (valueI >= 0)
							cout << R_result.arr[i][j] << "+" << I_result.arr[i][j] << "i";
						else
							cout << R_result.arr[i][j] << I_result.arr[i][j] << "i";
					}

					if (i != R_result.arr.size() - 1)
						cout << ";";
					else
						cout << "]";
				}
			}
			else
			{
				cout << "ERROR";
			}
		}
		else
		{
			cout << "ERROR";
		}

	}

	else if (operation == '*')
	{
		getline(cin, input2);

		R_matrix2.arr = convert_to_REAL_vector(input2);
		I_matrix2.arr = convert_to_IMG_vector(input2);

		bool check1 = check_rows(R_matrix1.arr);
		bool check2 = check_rows(R_matrix2.arr);

		if (check1 && check2)
		{
			R_matrix1.rows = R_matrix1.arr.size();
			R_matrix1.column = R_matrix1.arr[0].size();
			I_matrix1.rows = I_matrix1.arr.size();
			I_matrix1.column = I_matrix1.arr[0].size();


			R_matrix2.rows = R_matrix2.arr.size();
			R_matrix2.column = R_matrix2.arr[0].size();
			I_matrix2.rows = I_matrix2.arr.size();
			I_matrix2.column = I_matrix2.arr[0].size();

			R_result.rows = R_matrix1.rows;
			R_result.column = R_matrix1.column;

			if (R_matrix1.column == I_matrix2.rows)
			{
				R_result = REAL_multiplcation(R_matrix1, R_matrix2, I_matrix1, I_matrix2);
				I_result = IMG_multiplcation(R_matrix1, R_matrix2, I_matrix1, I_matrix2);

				cout << "[";
				float valueR;
				float valueI;

				for (int i = 0; i < R_result.arr.size(); i++)
				{

					for (int j = 0; j < R_result.arr[i].size(); j++)
					{
						if (j != 0)
						{
							cout << " ";
						}
						valueR = R_result.arr[i][j];
						valueI = I_result.arr[i][j];

						if (valueI >= 0)
							cout << R_result.arr[i][j] << "+" << I_result.arr[i][j] << "i";
						else
							cout << R_result.arr[i][j] << I_result.arr[i][j] << "i";
					}

					if (i != R_result.arr.size() - 1)
						cout << ";";
					else
						cout << "]";
				}
			}
			else
			{
				cout << "ERROR";
			}
		}
		else
		{
			cout << "ERROR";
		}

	}

	else if (operation == '^')
	{
		int p;
		cin >> p;
		power(R_matrix1, I_matrix1, p);
	}

	else if (operation == 'T')
	{
		bool check1 = check_rows(R_matrix1.arr);

		if (check1)
		{
			R_matrix1.rows = R_matrix1.arr.size();
			R_matrix1.column = R_matrix1.arr[0].size();

			R_result.rows = R_matrix1.column;
			R_result.column = R_matrix1.rows;

			I_matrix1.rows = R_matrix1.arr.size();
			I_matrix1.column = R_matrix1.arr[0].size();

			I_result.rows = R_matrix1.column;
			I_result.column = R_matrix1.rows;


			for (int i = 0; i < R_result.rows; i++)
			{
				R_result.arr.push_back(vector<float>());
				R_result.arr.push_back(vector<float>());

				for (int j = 0; j < R_result.column; j++)
				{
					R_result.arr[i].push_back(0);
					I_result.arr[i].push_back(0);
					R_result.arr[i][j] = R_matrix1.arr[j][i];
					I_result.arr[i][j] = R_matrix1.arr[j][i];
				}
			}
			cout << "[";
			float valueR;
			float valueI;

			for (int i = 0; i < R_result.arr.size(); i++)
			{

				for (int j = 0; j< R_result.arr[i].size(); j++)
				{
					if (j != 0)
					{
						cout << " ";
					}
					valueR = R_result.arr[i][j];
					valueI = I_result.arr[i][j];

					if (valueI >= 0)
						cout << R_result.arr[i][j] << "+" << I_result.arr[i][j] << "i";
					else
						cout << R_result.arr[i][j] << I_result.arr[i][j] << "i";
				}

				if (i != R_result.arr.size() - 1)
					cout << ";";
				else
					cout << "]";

			}

		}
		else
		{
			cout << "ERROR";
		}

	}

	else if (operation == 'D')
	{

		bool check1 = check_rows(R_matrix1.arr);

		R_matrix1.rows = R_matrix1.arr.size();
		if (check1)
		{
			R_matrix1.rows = R_matrix1.arr.size();
			R_matrix1.column = R_matrix1.arr[0].size();

			if (R_matrix1.rows == R_matrix1.column)
			{
				Complex det = determinant(R_matrix1, I_matrix1, R_matrix1.rows);

				float valueI = det.img;
				if (valueI >= 0)
					cout << det.real << "+" << det.img << "i";
				else
					cout << det.real << det.img << "i";
			}
			else
			{
				cout << "ERROR";
			}
		}
		else
		{
			cout << "ERROR";
		}
	}
/*
	else if (operation == 'I')
	{
		
		bool check1 = check_rows(R_matrix1.arr);

		R_matrix1.rows = R_matrix1.arr.size();
		I_matrix1.rows = I_matrix1.arr.size();
		if (check1)
		{
			R_matrix1.rows = R_matrix1.arr.size();
			R_matrix1.column = R_matrix1.arr[0].size();

			I_matrix1.rows = I_matrix1.arr.size();
			I_matrix1.column = I_matrix1.arr[0].size();

			if (R_matrix1.rows == R_matrix1.column)
			{
				Inverse(R_matrix1, I_matrix1);
			}
			else
			{
				cout << "ERROR";
			}
		}
		else
		{
			cout << "ERROR";
		}
	}

	else if (operation == '/')
	{
		getline(cin, input2);


		R_matrix1.arr = convert_to_vector(input1);
		I_matrix2.arr = convert_to_vector(input2);

		bool check1 = check_rows(R_matrix1.arr);
		bool check2 = check_rows(I_matrix2.arr);

		R_matrix1.rows = R_matrix1.arr.size();
		I_matrix2.rows = I_matrix2.arr.size();

		if (check1)
		{
			R_matrix1.rows = R_matrix1.arr.size();
			R_matrix1.column = R_matrix1.arr[0].size();

			I_matrix2.rows = I_matrix2.arr.size();
			I_matrix2.column = I_matrix2.arr[0].size();

			if (R_matrix1.column == I_matrix2.rows)
			{
				Division(R_matrix1, I_matrix2);
			}
			else
			{
				cout << "ERROR";
			}
		}
		else
		{
			cout << "ERROR";
		}
	}
	*/


	/*
	[1 1;1 1]
	[7 5 6;7 10 2;5 6 20]
	[123 123;123 123]
	[7 4 0 11;10 17 1 19;9 14 6 10;9 12 8 18]
	[1 0 0;0 1 0;0 0 1]
	[0+17i 2+15i 15+3i 12+1i 1+19i 13+11i;2+17i 14+0i 7+16i 4+10i 19+7i 6+3i;10+11i 4+12i 0+11i 15+11i 15+19i 13+13i;9+1i 15+15i 9+0i 10+12i 0+0i 13+10i]
	+
	[3+18i 10+18i 18+14i 5+10i 10+4i 15+3i;7+9i 7+0i 9+2i 8+12i 18+9i 3+6i;4+14i 4+1i 1+0i 1+15i 1+0i 0+2i;18+17i 15+4i 9+19i 0+2i 11+3i 2+5i]


	[-16.19-8i 1+0i 5+0i 1-18i 9-14.15i;6-3i 14+2i 16+12i -5.12+18i -5.16-2.11i;-18+7i 16+19.12i 17.16+14i 16-7i 0.16+2i;13.11+5.16i 18+9i 0.15+15.17i 10+17.17i -8+15i]
	+
	[7.11+0i -19.16-2i 9+0i -3-3.12i -6+4i;13.13+4.16i 17-6.16i 16+1i 11+7i 5.11+8.18i;16-11i 6.11-4i 12.13+17.11i 17+8i 18-4.13i;4+9i -2-18i 7+13.19i 17+0i -6.13+8.19i]
	*/

	system("pause");
}