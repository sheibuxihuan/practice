#include <iostream>

using namespace std;
#include<string>


template<class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		//cout<<"�вι������"<<endl;
		this->Capacity=capacity;
		this->Size=0;
		this->Address=new T[this->Capacity];
		
	}
	
	//���
	MyArray(const MyArray& arr)
	{
		//cout<<"�����������"<<endl;
		this->Capacity=arr.Capacity;
		this->Size=arr.Size;
		this->Address=new T[arr.Capacity];
		
		for(int i=0;i<this->Size;i++)
		{
			this->Address[i]=arr.Address[i];
		}
	}
	
	//a=b=c  ��ֹǳ��������
	MyArray& operator=(const MyArray& arr)
	{
		//cout<<"operator=����"<<endl;
		if(this->Address!=NULL)
		{
			delete[] this->Address;
			this->Address=NULL;
			this->Capacity=0;
			this->Size=0;
		}
		
		this->Capacity=arr.Capacity;
		this->Size=arr.Size;
		this->Address=new T[arr.Capacity];
		
		for(int i=0;i<this->Size;i++)
		{
			this->Address[i]=arr.Address[i];
		}
		return *this;
	}
	
	//β�巨
	void Push_Back(const T & val)
	{
		if(this->Capacity==this->Size)
		{
			return;
		}
		//������β����������
		this->Address[this->Size]=val;
		//���������С
		this->Size++;
	}
	
	//βɾ��
	void Pop_Back()
	{
		if(this->Size==0)
		{
			return;
		}
		this->Size--;
	}
	
	T& operator[](int index)
	{
		return this->Address[index];
	}
	
	//������������
	int getCapacity()
	{
		return this->Capacity;
	}
	
	//���������С
	int getSize()
	{
		return this->Size;
	}
	
	
	~MyArray()
	{
		if(this->Address!=NULL)
		{
			//cout<<"������������"<<endl;
			delete [] this->Address;
			this->Address=NULL;
		}
		
	}
	
private:
	T *Address;
	int Capacity;
	int Size;
	
};

void printIntArray(MyArray<int>& arr)
{
	for(int i=0;i<arr.getSize();i++)
	{
		cout<<arr[i]<<"  ";
	}
}


void test1()
{
	MyArray<int> arr1(5);
	
	for(int i=0;i<5;i++)
	{
		arr1.Push_Back(i);
	}
	cout<<"arr1�Ĵ�ӡ���Ϊ��"<<endl;
	
	printIntArray(arr1);
	
	cout<<"\narr1������Ϊ��"<<arr1.getCapacity()<<endl;
	cout<<"arr1�Ĵ�СΪ��"<<arr1.getSize()<<endl;
	
	
	MyArray<int>arr2(arr1);
	
	cout<<"arr2�Ĵ�ӡ���Ϊ��"<<endl;
	
	printIntArray(arr2);
	
	arr2.Pop_Back();
	
	cout<<"\narr2βɾ��"<<endl;
	cout<<"arr2������Ϊ��"<<arr2.getCapacity()<<endl;
	cout<<"arr2�Ĵ�СΪ��"<<arr2.getSize()<<endl;
	
	
	
	
	//MyArray<int>arr3(100);
	//arr3=arr1;
}


class Person
{
public:
	
	Person(){};
	Person(string name,int age)
	{
		this->Name=name;
		this->Age=age;
	}
	
		string Name;
		int Age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for(int i=0;i<arr.getSize();i++)
	{
		cout<<"������"<<arr[i].Name
			<<"���䣺"<<arr[i].Age<<endl;
	}
}

void test2()
{
	MyArray<Person>arr(10);
	
	Person p1("Tom",8);
	Person p2("list",17);
	Person p3("wangwu",15);
	Person p4("zhaoliu",14);
	Person p5("shangqi",13);
	
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	
	printPersonArray(arr);
	
	cout<<"arr3������Ϊ��"<<arr.getCapacity()<<endl;
	cout<<"arr3�Ĵ�СΪ��"<<arr.getSize()<<endl;
	
}


int main() {
	
	//test1();
	
	test2();
	
	return 0;
}
