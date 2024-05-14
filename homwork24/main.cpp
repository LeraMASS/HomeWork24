#include <iostream>;
#include <cstdlib>
#include <ctime>

template <typename T>
void fill_arr(T arr[], int const length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
//Задача 2.
template <typename T>
void resize_arr(T*& arr, int& length, int n_length) {
	if (n_length <= 0) {
		delete[] arr;
		arr = nullptr;
		return;
	}
	T* tmp = new T[n_length]{};
	for (int i = 0; i < n_length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
	length = n_length;
}

int main() {
	setlocale(LC_ALL, "Russian");

	//Задача 1.
	int n, m;
	std::cout << "Задача 1\n Введите длины массивов -> ";
	std::cin >> n >> m;
	int* A = new int[n];
	int* B = new int[m];

	fill_arr(A, n, 10, 21);
	fill_arr(B, m, 20, 31);
	std::cout << "Массив A:\n";
	print_arr(A, n);
	std::cout << "Массив B:\n";
	print_arr(B, m);

	int* C = new int[n + m];
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = n; i < n + m; i++)
		C[i] = B[i - n];
	std::cout << "Полученные массивы:\n";
	print_arr(C, n + m);
	delete[] A;
	delete[] B;

	//Задача 2.
	std::cout << "Задача 2.\n Введите размер массива:\n";
	int size;
	std::cin >> size;
	int* d_arr = new int[size];
	fill_arr(d_arr, size, 10, 21);
	print_arr(d_arr, size);
	std::cout << "Введите новый размер массива:\n";
	int n_size;
	std::cin >> n_size;
	resize_arr(d_arr, size, n_size);
	std::cout << "Итоговый массив:\n";
	print_arr(d_arr, size);





	return 0;
}