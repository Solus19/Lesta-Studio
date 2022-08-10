// merge sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include <vector>

template<typename Type>
void print_arr(vector<Type> v)
{
    for (auto i : v)
        cout << i << ' ';
}

template<typename Type>
void Merge(vector<Type>* t, int p, int r)
{
    int q = (p + r) / 2;
    int i, j, k;
     
    vector<Type> L(q - p + 1), R(r - q);

    for (i = 0; i < L.size(); i++)
    {
        L[i] = (*t)[p + i];
    }

    for (j = 0; j < R.size(); j++)
    {
        R[j] = (*t)[q + j + 1];
    }

    i = 0, j = 0;

    for (k = p; i < L.size() && j < R.size(); k++)
    {
        if (L[i] < R[j])
        {
            (*t)[k] = L[i++];
        }
        else
        {
            (*t)[k] = R[j++];
        }
    }

    //Left arr bigger than Right arr
    while (i < L.size())
    {
        (*t)[k++] = L[i++];
    }

    //Right arr bigger than Left arr
    while (j < R.size())
    {
        (*t)[k++] = R[j++];
    }
}


template<typename Type>
void MergeSort(vector<Type> *A, int first, int last)
{
    {
        if (first < last)
        {
            MergeSort<Type>(A, first, (first + last) / 2); //сортировка левой части

            MergeSort<Type>(A, (first + last) / 2 + 1, last); //сортировка правой части

            Merge<Type>(A, first, last); //слияние двух частей
        }
    }
};


template<typename Type>
void MergeSort(vector<Type> *A)
{
    MergeSort(A, 0, (*A).size()-1);
}

void main()
{
    setlocale(LC_ALL, "Rus");
    int i, n=40;
    cout << "Размер массива > "; //cin >> n;

    vector<int> A(n);

    for (i = 0; i < n; i++)
    {
         A[i] = rand() % 10;;
    }

    cout << "Не упорядоченный массив: "; 
    for (auto a:A) cout << a << " ";
    cout << endl;

    MergeSort(&A); //вызов сортирующей процедуры

    cout << "Упорядоченный массив: "; 
    for (auto a : A) cout << a << " ";
    system("pause>>void");
}


