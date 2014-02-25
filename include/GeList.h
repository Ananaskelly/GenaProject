#pragma once

template<typename T> class GeList
{
	struct node{
		T data;
		node *next;
	};

	node *_first;
	node *_current;
public:
	GeList(void){ _first = 0; _current = 0;};
	~GeList(void);
	void add(T);
	void clear();
	unsigned  size()const;

	void rewind(); // Возвращает _current к первому элементу
	void next(); // Перемещает _current к следующему элементу
	T getData();// Получение данных, соответствующих _current 
	bool canMove();
};


template<typename T> GeList<T>::~GeList(void)
{  
	clear();
}
template<typename T> void GeList<T>::clear()
{
	if (_first) {
	node *ptr = _first;
	while (ptr){
		node *next = ptr->next;
		delete ptr;
		ptr = next; 
	}
	}
}

template<typename T> void GeList<T>::add(T new_one)
{
	if (_first==0)
   {    _first = new node;
		_first->data=new_one;
		_first->next = 0; 
	}
	else 
	{   node *new_str = new node;
		new_str->data = new_one;
	    new_str->next = 0; 
		
		node *p = _first;
		while (p->next)  p=p->next;
		
		p->next = new_str;
    };
}

template<typename T> void GeList<T>::rewind()
{
	_current=_first;
}

template<typename T> void GeList<T>::next()
{
	_current = _current->next;
}
template<typename T> T GeList<T>::getData()
{ T new_ob;
new_ob = _current->data;
return new_ob;
}
template<typename T> bool GeList<T>::canMove()
{
	if (_current->next) return true;
	return false;
}