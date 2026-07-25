
#include <iostream>
#include<iterator>
#include<algorithm>
#include<utility>

template <typename T>
struct dnode {
	T val;
	dnode<T>* next;
	dnode<T>* prev;
};
template <typename T>
class list {
private:
	dnode<T>* h;
	int n;
public:
	list() {
		this->h = new dnode<T>;
		this->n = 0;
		this->h->next = this->h;
		this->h->prev = this->h;

	}
	~list() {
		while (!empty())
		{
			pop_front();
		}
		delete h;

	}

	T &operator (const T&v)
	{
		this->val = v;
		return *this;
	}
	bool operator==(const list<T> & rhs)
	{
		return this.ptr = rhs.ptr;
	}
	bool operator!= (const list < T& rhs)
	{
		return !(his->ptr = rhs.ptr);
	}
	bool operator<=(const list<T>& rhs)
	{
		return (this.ptr < rhs.ptr|| this.ptr=rhs.ptr);
	}
	
	bool operator >(const list<T>& rhs)
	{
		return !(*this <= rhs);
	}
	bool operator <(const list<T>& rhs)
	{
		return (is.ptr < rhs.ptr);
	}

	class iterator {
			private:
			dnode<T>* ptr;

		public:
		T& operator*() {
			return this->ptr->val;
							}

			T* operator->() {
			return &(this->ptr->val);
			}

		bool operator==(const iterator& rhs) const {
			return (this->ptr == rhs.ptr);
							}
		iterator& operator++() {
		this->ptr = this->ptr->next;
			return *this;
				}

	iterator operator++(int) {
		iterator old = *this;
			this->ptr = this->ptr->next;
			return old;
							}

			iterator& operator--() {
		this->ptr = this->ptr->prev;
		return *this;
				}

			iterator operator--(int) {
		iterator old = *this;
		this->ptr = this->ptr->prev;
			return old;
				}
			};
				};
	iterator begin() {
		iterator it;
		it.ptr = this->h->next;
		return it;
	}
	iterator end() {
		iterator it;
		it.ptr = nullptr;
		return it;
	}
	reverse_iterator rbegin() {
		reverse_iterator it;
		it.ptr = this->h->prev;
		return it;
	}
	reverse_iterator rend() {
		reverse_iterator it;
		it.ptr = this->h;

	}
	T& front() {
		return this->h->next->val;
	}
	T& back()
	{
		return  this->h->prev->val;
	}
	iterator insert(iterator pos, const T& v)
	{
		dnode<T>* temp;
		temp = new dnode<T>;
		temp->val = v;
		temp->next = pos.ptr;
		temp->prev = pos.ptr->prev;
		pos.ptr->prev = temp;
		temp->prev->next = temp;
		temp->next->prev = temp;
		++this->n;
		--pos;
		return pos;
		

	} 
	iterator erase(iterator pos)
	{
		itertor temp = pos;
		++temp;
		pos.ptr->prev->next = pos.ptr->next;
		pos.ptr->next->prev = pos.ptr->prev;
		delete pos.ptr;
		--this->n;
		return temp;

	}
	void push_front(const T& v)
	{
		dnode<T>* temp;
		temp = dnode<T>;
		temp = temp->val;
		temp->next = this->h->next;
		temp->prev = this->h;
		temp->next->prev = temp;
		this->h->next = temp;
		this->n++


	}
	int size()const {
		return this->n;
	}
	bool empty() const {
		return this->n = 0;
	}
	T front() const {
		return this->h ->ext->val;
	}
	void clear() {
		while (!empty)
			pop_front();
	}
	 
	void push_back(const T& v) {
		dnode<T>* temp;
		temp = new dnode<T>;
		temp->val = v;
		temp->next = this->h;
		temp->prev = this->h->prev;
		this->h->prev = temp;
		temp->prev->next = temp;
		this->n++;
	}
	void pop_front() {
		dnode<T>* temp;
		temp = this->h->next;
		temp->prev->next = temp->next;
		this->h->next = temp->next;
		temp->next->prev = this->h;
		delete temp;
		this->n--;
	}
	void pop_back() {
		dnode<T>* temp;
		temp = this->h->prev;
		temp->prev->next = this->h;
		this->h->prev = temp->prev;
		delete temp;
		this->n--;
	}                                               
	void resize(int ns, const T& v = T())
	{
		if (ns > this->n) {
			dnode<T>* temp, * last;
			last = h->prev;
			for (int i = 0; i < ns - this->n; ++i)
			{
				temp = new dnode<T>;
				temp->val v;
				temp->next = this->h;
				temp->prev = last;
				last->next = temp;
				this->h->prev = temp;
				this->n++;
				last = temp;
		else if (ns < this->n)
		{
			for (int i = 0; i < this->n - ns; ++i)
			{
				pop_back();
			}
		}
			}
		}
	}
	void merge(list<T>& other)
	{
		dnode<T>* p1, * p2;
		if (this == &other)
		{
			return;
			p1 = this->h->next;
			p2 = other.h->next;
		} 
		while (p1 != this->h)
			if (p2->val < p1->va)
				other.h.next = p2->next;
		p2->next->prev = other->h;
		p2.next = p1;
		p2.prev = p1->prev;
		p1->prev->next = p2;
		p1->prev = p2;
		p2 = other->h->next;
			else {
				p1 = p1->next;
			}
		if (other->h->next != other->h){
			p1 = this->h->prev;
		p1 - .next = p2;
		p2->prev = p1;
		p2 = other.h->prev;
		p2->next = this->h;
		this->h->prev = p2;
		other.h->next = other.h->prev = other.h;
	}
		this->n += other.n;
			
	}
	void swap(list& other) {
		std::swap(this->h, other.h);
		std::swap(this->n, other.h);


	}
	void reverse()
	{
		if (this->n <= 1)
			return;

		dnode<T>* curr = this->h;
		dnode<T>* temp;

		do
		{
			temp = curr->next;

			curr->next = curr->prev;
			current->prev = temp;

			curr = temp;

		} while (curr != this->h);
	}
	void sort()
	{
		if (this->n < 1)
		{
			return;
		}
		dnode<T>* p1, * p2; 

		for (int p1 = this->h->next; p1 != this->h; p1 = p1->next)
		{
			for (p2 = p1->next; p2 != this->h; p2 = p2->next)
			{
				if (p1->val2->val
				{
					swap(p1->val2->val;
				}
			}
		}

		}

	}

void sort() {
	if (this->n <= 1)
		return;
	dnode<T>* p1, * p2;
	for (p1 = this->h->next; p1 != this->h; p1 = p1->next) {
		for (p2 = p1 - .next; p2 != this->h; p2 = p2->next)
		{
			if (p1->val > p2->val)
			{
				T temp = p1->val;
				p1->val = p2->val;
				p2->val = temp;
			}
		}
	}
}
void unique()
{
	if (this->n <= 1)
		return;

	dnode<T>* current = this->h->next;
	dnode<T>* temp;

	while (current->next != this->h)
	{
		if (current->val == current->next->val)
		{
			temp = current->next;

			current->next = temp->next;
			temp->next->prev = current;

			delete temp;
			this->n--;
		}
		else
		{
			current = current->next;
		}
	}
}

};
int main()
{
	list<int> l1;
	list<int> l2;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(20);
	l1.push_back(10);

	l1.push_front(5);
	l1.push_front(1);

	std::cout << "List l1: ";
	for (auto it = l1.begin(); it != l1.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Front: " << l1.front() << std::endl;
	std::cout << "Back: " << l1.back() << std::endl;

	std::cout << "Size: " << l1.size() << std::endl;

	l1.pop_front();
	l1.pop_back();

	std::cout << "After pop operations: ";
	for (auto it = l1.begin(); it != l1.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	auto it = l1.begin();
	++it;
	l1.insert(it, 99);

	std::cout << "After insert: ";
	for (auto i = l1.begin(); i != l1.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	it = l1.begin();
	++it;
	l1.erase(it);

	std::cout << "After erase: ";
	for (auto i = l1.begin(); i != l1.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	l1.sort();

	std::cout << "After sort: ";
	for (auto i = l1.begin(); i != l1.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	l1.unique();

	std::cout << "After unique: ";
	for (auto i = l1.begin(); i != l1.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	l1.reverse();

	std::cout << "After reverse: ";
	for (auto i = l1.begin(); i != l1.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	l1.resize(10, 7);

	std::cout << "After resize(10,7): ";
	for (auto i = l1.begin(); i != l1.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	l1.resize(3);

	std::cout << "After resize(3): ";
	for (auto i = l1.begin(); i != l1.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	l2.push_back(100);
	l2.push_back(200);

	l1.swap(l2);

	std::cout << "l1 after swap: ";
	for (auto i = l1.begin(); i != l1.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::cout << "l2 after swap: ";
	for (auto i = l2.begin(); i != l2.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	l1.clear();

	std::cout << "Size after clear: " << l1.size() << std::endl;

	return 0;
}

	