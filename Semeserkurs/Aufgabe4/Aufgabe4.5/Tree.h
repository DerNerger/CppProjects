#ifndef TREE
  #define TREE

#include <sstream>
#include <string>
#include <iostream>
#include <vector>
enum Operator{ ADD, SUB, MULT, DIV};

class VisualTree{
	private:
	std::vector<std::string> v;
	int middle;
	public:
	VisualTree(int a) :v(1), middle(0){
		std::ostringstream ss;
		ss << "--("<< a << ")";
		v[0]=ss.str();
	}

	VisualTree& append(VisualTree &b, char c){
		int i;
		for (i = 0; i < v.size(); ++i) {
			if(i==middle)
				v[i]="    /"+v[i];
			else if(i>middle)
				v[i]="    |"+v[i];
			else
				v[i]="     "+v[i];
		}
		middle = i;
		std::ostringstream ss;
		ss << "--(" << c << ")";
		v.push_back(ss.str());

		for (int i = 0; i < b.v.size(); ++i) {
			if(i==b.middle)
				v.push_back("    \\"+b.v[i]);
			else if( i < b.middle)
				v.push_back("    |"+b.v[i]);
			else
				v.push_back("     "+b.v[i]);
		}
		return *this;
	}

	VisualTree& operator+(VisualTree &b){
		return append(b, '+');
	}
	VisualTree& operator-(VisualTree &b){
		return append(b, '-');
	}
	VisualTree& operator*(VisualTree &b){
		return append(b, '*');
	}
	VisualTree& operator/(VisualTree &b){
		return append(b, '/');
	}

    friend std::ostream& operator<<(std::ostream& out, VisualTree& t){
    	for (int i = 0; i < t.v.size(); ++i) {
			out << t.v[i] << std::endl;
		}
    	return out;
    }
};

class Tree{
  protected:
    Tree *left;
    Tree *right;

  public:
    Tree(Tree *left, Tree *right) : left(left), right(right) {}
    Tree() : left(0), right(0) {}
    virtual ~Tree(){
    	delete left;
    	delete right;
    }
    virtual int eval() = 0;
    virtual std::string getInfixNotation() = 0;
    virtual bool isSum() = 0;
    virtual VisualTree visual() = 0;

    friend std::ostream& operator<<(std::ostream& out, Tree& r){
      return out << r.getInfixNotation();
    }
};

class NumberElement : public Tree{
  private:
    int number;
  public:
    NumberElement(int pNumber) : Tree(), number(pNumber) {} 
    //virtual ~NumberElement() {Tree::~Tree();}
    virtual int eval(){
    	//std::cout << "return " << number << std::endl;
      return number;
    }

    virtual std::string getInfixNotation(){
        std::ostringstream ss;
        if(number<0)
        	ss << "(" << number << ")";
        else
        	ss << number;
        return ss.str();
    }

    virtual bool isSum(){
    	return false;
    }

    virtual VisualTree visual(){
    	return VisualTree(number);
    }
};

class OperatorElement : public Tree{
  private:
     enum Operator op;

  public:
    OperatorElement(Tree *l, enum Operator pOp, Tree *r) : Tree(l,r), op(pOp) {}
    OperatorElement(Tree *l, char pOp, Tree *r) : Tree(l,r){
      switch(pOp){
        case '+' : op = ADD;  break; 
        case '-' : op = SUB; break; 
        case '*' : op = MULT; break; 
        case '/' : op = DIV; break; 
      }
    }
    //virtual ~OperatorElement() {Tree::~Tree();}

    virtual int eval(){
       int a = left->eval();
       int b = right->eval();
       //std::cout << "return " << a << op << b << std::endl;
       switch(op){
         case ADD: return a + b;
         case SUB: return a - b;
         case MULT: return a * b;
         case DIV: return a / b;
       }
    }

    virtual std::string getInfixNotation(){
        std::ostringstream ss;
        if(left->isSum()) ss << "(";
    	ss << left->getInfixNotation();
    	if(left->isSum()) ss << ")";
        switch(op){
          case ADD: ss << '+'; break;
          case SUB: ss << '-'; break;
          case MULT: ss << '*'; break;
          case DIV: ss << '/'; break;
        }
        if(right->isSum()) ss << "(";
    	ss << right->getInfixNotation();
    	if(right->isSum()) ss << ")";
    	return ss.str();
    }

    virtual bool isSum(){
    	return op==ADD || op==SUB;
    }

    virtual VisualTree visual(){
    	VisualTree lVisual = left->visual();
    	VisualTree rVisual = right->visual();
        switch(op){
          case ADD: return lVisual + rVisual;
          case SUB: return lVisual - rVisual;
          case MULT: return lVisual * rVisual;
          case DIV: return lVisual / rVisual;
        }
    }
};

#endif //define tree
