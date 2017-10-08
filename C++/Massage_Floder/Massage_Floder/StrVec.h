#include <string>
using namespace std;

class StrVec{
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr){}  //默认构造函数
	StrVec(StrVec &);   //拷贝构造函数
	StrVec& operator=(StrVec &);   //拷贝赋值运算符
	~StrVec();   //析构函数

	void push_back(const string&);

	rsize_t size() const { return first_free - elements; }
	rsize_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }


private:
	static allocator<string> alloc;   //分配元素

	string * elements;   //指向第一个元素之前位置的指针
	string * first_free;   //指向第一个空闲位置的指针
	string * cap;   //指向数组尾后位置的指针

	//工具函数，
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	void free();  //销毁元素并释放内存
	void reallocate();  //当内存不够用时重新分配内存

	
};

void StrVec::push_back(const string &s)
{
	chk_n_alloc();  //确保还有可以分配的内存空间
	alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string*b, const string*e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements; alloc.destroy(--p));
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(StrVec &s)
{
	//调用alloc_n_copy来分配空间以容纳与s中一样多的元素
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
}

StrVec::~StrVec()   //析构函数
{
	free();
}

StrVec& StrVec::operator=(StrVec &rhs)   //拷贝赋值运算符
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	return *this;
}

void StrVec::reallocate()
{
	// 分配当前大小两倍的空间
	auto newsize = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newsize);
	auto dest = newdata;
	auto elem = elements;

	// 移动原来空间的元素
	for (size_t k = 0; k != size(); ++k)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	//销毁原来空间的元素，并释放空间
	free();

	elements = newdata;
	first_free = dest;
	cap = elements + newsize;

}