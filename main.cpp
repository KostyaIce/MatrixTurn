#include <iostream>

//--------------------------------------------------
//Функция преобразования массива
template <class T>
void matrixTurn(T *matrix, int N)
{ 
	T *temp = new T[N*N];
	for (int f = 1; f <= N; f++)
		for (int s = 0; s < N; s++)
		{
			temp[N-f+N*s] = matrix[f*N-(N-s)];
		}
	for (int i = 0; i < N*N; i++)
		matrix[i] = temp[i];
	delete[] temp;
}
//---------------------------------------------------
//функция отображения массива для теста
template <class T>
void showMatrix(T *matrix, int N)
{
	for (int i = 0; i < N*N; i++)
	{
		if (i%N == 0) std::cout<<"\n";
		std::cout << matrix[i] << " ";
	}
}

int main()
{
	int n = 10;
	int* mas = new int[n*n];
	for (int i = 0; i < n*n; i++)
		mas[i] = rand()%256;
	showMatrix(mas, n);
	matrixTurn(mas, n);
	std::cout << "\n";
	showMatrix(mas, n);
	delete[] mas;
	return 0;
}
