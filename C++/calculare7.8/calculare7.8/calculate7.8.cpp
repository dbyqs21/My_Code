
#include "std_lib_facilities.h"
//*****************************************************************************************************
const char name = 'a';     //name token 
const char let = 'L';   //declaration token
const string declkey = "let";   //declaration keyword

//*****************************************************************************************************
class Variable {
public:
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) {}
};
//*****************************************************************************************************
vector<Variable> var_table;
//*****************************************************************************************************

class Token {
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	string name;     //
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
	Token(char ch, string n) :kind(ch), name(n){}
};

//*****************************************************************************************************

class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
	void ignore(char c);   //discard characters up to and including a c
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

//*****************************************************************************************************
void Token_stream::ignore(char c)
{
	if (full && buffer.kind)
	{
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (cin>>ch)
	if (ch == c)
		return;
}

//*****************************************************************************************************
double delaration()	   //assume woe can seen "let"
//handle: name = expression
//declear a variable called "name" with the initial value "experience"
{
	Token t = ts.get();
	if (t.kind != name)
		error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=')
		error("= missing in declaration of ", var_name);

	double d = expression();
	define_name(var_name, d)
    return d;
}



//*****************************************************************************************************
double get_value(string s)	//找到变量名所对应的值
{
	for (int i = 0; i < var_table.size(); ++i)
	{
		if (var_table[i].name == s)
			return var_table[i].value;
	}
	error("get:undefined variable", s);
}

//*****************************************************************************************************
void set_value(string s,double n) //给变量赋值
{
	  for (int i = 0; i < var_table.size(); ++i)
	{
		if (var_table[i].name == s)
			var_table[i].value = n;
		return;
	}
	  error("set:undefined variable", s);
}
//*****************************************************************************************************
bool is_declared(string var)
{
	    for (int i = 0; i < var_table.size(); ++i)
	{
		if (var_table[i].name == var )
		return true;
	}
		return false;
}
//*****************************************************************************************************
double define_name(string var, double val)
{
	if (is_declared(var))
		error(var, "declared twice");
	var_table.push_back(Variable(var, val));
	return val;
}




//*****************************************************************************************************
double factorial(double k)			   //calculate the factorial
{
	int cnt = (int)k;
	if (0 == cnt)
		return 1;
	else
		return (double)(cnt*factorial(cnt - 1));
}
//*****************************************************************************************************
double statement()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}


//*****************************************************************************************************
void clean_up_mess()  //naive
{
	while (true)
	{
		Token t = ts.get();
		if (t.kind == print)
			return;
	}
}



//*****************************************************************************************************

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//*****************************************************************************************************

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//*****************************************************************************************************

Token Token_stream::get()
{
	if (full) {       // do we already have a Token ready?
		// remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) 
	{													    
	     case ';':    // for "print"
	     case 'q':    // for "quit"
	     case '(': case ')': case '{': case '}': case '+': case '-': case '*': case '/':
	     	return Token(ch);        // let each character represent itself
	    case '.':
	       {

				cin.putback(ch);         // put digit back into the input stream
				double val;
				cin >> val;              // read a floating-point number
				return Token('8', val);   // let '8' represent "a number"
	        }
	    case '0': case '1': case '2': case '3': case '4':
	    case '5': case '6': case '7': case '8': case '9':
	        {
				  cin.putback(ch);         // put digit back into the input stream
				  double val;
				  cin >> val;              // read a floating-point number

				  char ch;					//判断是否有阶乘
				  cin >> ch;
				  if ('!' == ch)
				  {
					  return Token('8', factorial(val));
				  }
				  else
				  {
					  cin.putback(ch);
				  }
				  return Token('8', val);   // let '8' represent "a number"
	       }
	  default:
		if (isalpha(ch))
		  {
			cin.putback(ch);
			string s;
			s += ch;
			
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;

			cin.putback(ch);

			if (s == declkey)
				return Token(let);
			return Token(name, s);
		  }
		error("Bad token");
	  }
}

//*****************************************************************************************************

Token_stream ts;        // provides get() and putback() 

//*****************************************************************************************************
double expression();    // declaration so that primary() can call expression()

//*****************************************************************************************************

// deal with numbers and parentheses
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
	{
					 double d = expression();
					 t = ts.get();
					 if (t.kind != ')') error("')' expected");
					 return d;
	}
	case '{':    // handle '(' expression ')'
	{
					 double d = expression();
					 t = ts.get();
					 if (t.kind != '}') error("'}' expected");
					 return d;
	}
	case '8':            // we use '8' to represent a number
		return t.value;  // return the number's value
	case '-':
		return -primary();
	case '+':
		return +primary();
	default:
		error("primary expected");
	}
}

//*****************************************************************************************************

// deal with *, /, and %
double term()
{
	double left = primary();
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':  //处理乘法运算
			left *= primary();
			t = ts.get();
			break;
		case '/':	//处理除法运算
		{
						double d = primary();
						if (d == 0) error("divide by zero");
						left /= d;
						t = ts.get();
						break;
		}
		case '%':	//处理模运算
		{
						double d = primary();
						int cnt1 = (int)left;
						if (cnt1 != left)
							cout << "left-hand operand of % not int";
						int cnt2 = (int)d;
						if (cnt2 != d)
							cout << "right-hand operand of % not int";
						if (cnt2 == 0)
							cout << "divided by zero!!";
						left = cnt1%cnt2;

						t = ts.get();
						break;
		}

		default:
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}

//*****************************************************************************************************

// deal with + and -
double expression()
{
	double left = term();      // read and evaluate a Term
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}

//*****************************************************************************************************
void calculate()
{
	cout << "**********************Welcome to our simple calculator.************************" << endl;
	cout << "   //Please enter expressions using flating-point numbers." << endl;
	cout << "   //You can use ';' to end your input and press 'enter' to get the result" << endl;
	cout << "********************************************************************************" << endl;

	double val = 0;
	while (cin) {
		try
		{

			cout << prompt;

			Token t = ts.get();
			while (t.kind == print)  t = ts.get(); //吃掉一个；

			if (t.kind == quite)
				return;

			ts.putback(t);
			cout << "=" << expression() << endl;	 //用 = 来表示计算结果的输出	   
		}
		catch (exception & e)
		{
			cerr << e.what() << endl;
			clear_up _mess();
		}
	}
}
//****************************************************************************************************
int main()
try
{
	//predefinr names
	define_name("pi", 3.14159265354);
	define_name("e", 2.7182818284);

	calculate();

	keep_window_open();	 //保持程序窗口打开
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	//提示出错信息
	cout << "Please enter the characer ~ to close the window.\n";
	char ch;
	while (cin >> ch)
	if (ch == '~') return 1;

	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}

//------------------------------------------------------------------------------
