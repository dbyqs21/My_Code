#include <string>
using namespace std;

class StrVec{
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr){}  //Ĭ�Ϲ��캯��
	StrVec(StrVec &);   //�������캯��
	StrVec& operator=(StrVec &);   //������ֵ�����
	~StrVec();   //��������

	void push_back(const string&);

	rsize_t size() const { return first_free - elements; }
	rsize_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }


private:
	static allocator<string> alloc;   //����Ԫ��

	string * elements;   //ָ���һ��Ԫ��֮ǰλ�õ�ָ��
	string * first_free;   //ָ���һ������λ�õ�ָ��
	string * cap;   //ָ������β��λ�õ�ָ��

	//���ߺ�����
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	void free();  //����Ԫ�ز��ͷ��ڴ�
	void reallocate();  //���ڴ治����ʱ���·����ڴ�

	
};

void StrVec::push_back(const string &s)
{
	chk_n_alloc();  //ȷ�����п��Է�����ڴ�ռ�
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
	//����alloc_n_copy������ռ���������s��һ�����Ԫ��
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
}

StrVec::~StrVec()   //��������
{
	free();
}

StrVec& StrVec::operator=(StrVec &rhs)   //������ֵ�����
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	return *this;
}

void StrVec::reallocate()
{
	// ���䵱ǰ��С�����Ŀռ�
	auto newsize = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newsize);
	auto dest = newdata;
	auto elem = elements;

	// �ƶ�ԭ���ռ��Ԫ��
	for (size_t k = 0; k != size(); ++k)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	//����ԭ���ռ��Ԫ�أ����ͷſռ�
	free();

	elements = newdata;
	first_free = dest;
	cap = elements + newsize;

}