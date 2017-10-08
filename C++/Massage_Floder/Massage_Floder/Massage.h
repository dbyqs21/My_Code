#include <string>
#include <set>
#include <Floder.h>
using namespace std;

class Massage{
	friend Floder;
public:
	explicit Massage(string &str = "") :content(str){};
	Massage(const Massage&);  //定义拷贝构造函数

	Massage& operator=(const Massage&);

	void save(Floder &);
	void remove(Floder &);

	~Massage(){};
private:
	string content;
	set<Floder*> floders;

	void add_to_Floders(const Massage&);
	void remove_form_Floders();

};

void Massage::save(Floder &f)
{
	floders.insert(&f);
	f.addMsg(this);
}