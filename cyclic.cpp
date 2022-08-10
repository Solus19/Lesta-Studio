// cyclic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

bool DEBUG = false;



template<typename Type>
class cyclic_ptr
{
public:
	cyclic_ptr(int n);
	~cyclic_ptr()=default;
	void push(Type elem);
	Type get();
	
	void print()
	{
		Node<Type>*ptr = curr;
		cout << ptr->data << ' ';
		ptr = ptr->next_p;
		while (ptr != curr)
		{
			cout << ptr->data<<' ';
			ptr = ptr->next_p;
		}




	}


private:
	template<typename Type>
	struct Node
	{
		Type data = Type();
		Node* next_p = nullptr;

	};
	Node<Type>* curr= nullptr;
	Node<Type>* last= nullptr;
	vector<Node<Type>>v;
};

template<typename Type>
cyclic_ptr<Type>::cyclic_ptr(int n)
{
	v.resize(n);


	last = curr = &(v[0]);
	


	for (int i = 0; i < v.size()-1; i++) 
	{
		v[i].next_p= &(v[i+1]);
	}
	(v[v.size() - 1]).next_p = &(v[0]);
}

template<typename Type>
void cyclic_ptr<Type>::push(Type elem)
{
	curr = curr->next_p;
	if (curr == last)
		last = last->next_p;
	if (DEBUG)
		cout << curr->next_p << endl;
	curr->data = elem;


}

template<typename Type>
Type cyclic_ptr<Type>::get()
{
	auto res= (* curr).data;
	curr = curr->next_p;
	return res;


}



template<typename Type>
class cyclic_arr
{
public:
	cyclic_arr(int n);
	~cyclic_arr() = default;
	void push(Type elem);
	Type get();

	void print()
	{
		for (int i = 0; i < v.size(); i++)
			cout << (v[ ((i + curr) % (v.size() )) ]) << ' ';
		cout << endl;
	}


private:
	int curr = 0;
	int last = 0;
	vector<Type>v;
};

template<typename Type>
cyclic_arr<Type>::cyclic_arr(int n)
{
	v.resize(n);
}

template<typename Type>
void cyclic_arr<Type>::push(Type elem)
{
	curr=((curr+1)%(v.size()));
	if (curr == last)
		last = ((last+1) % (v.size() ));
	if (DEBUG)
		cout << curr << endl;
	v[curr] = elem;


}

template<typename Type>
Type cyclic_arr<Type>::get()
{
	auto res = v[curr];
	curr = ((curr + 1) % (v.size()));
	return res;


}
int main()
{
    std::cout << "Hello World!\n";
	cyclic_arr<int> test(5);
	cyclic_ptr<int> test1(5);

	cout << "cyclic_arr:\n";
	test.push(1);
	test.print();
	test.push(2);
	test.print();
	test.push(3);
	test.print();
	test.push(4);
	test.print();
	test.push(4);
	test.print();
	test.push(4);
	test.print();
	cout << test.get()<<endl;
	test.print();

	cout << "cyclic_ptr:\n";
	test1.push(1);
	test1.push(2);
	test1.push(3);
	test1.push(4);
	test1.push(4);
	test1.push(4);
	cout << test1.get() << endl;
	test1.print();
}


