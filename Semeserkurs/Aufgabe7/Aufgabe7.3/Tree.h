enum Operator{ ADD, SUB, MULT, DIV};

class Tree{
  protected:
    Tree *left;
    Tree *right;

  public:
    Tree(Tree *left, Tree *right) : left(left), right(right) {}
    Tree() : left(nullptr), right(nullptr) {}
    virtual int eval() = 0;
};

class OperatorElement : public Tree{
  private:
    int operatorElement;
    virtual int eval(){
      return operatorElement;
    }
};

class NumberElement : public Tree{
  private:
     enum Operator op;
     virtual int eval(){
       switch(op){
         case ADD: return left-> eval() + right->eval();
         case SUB: return left-> eval() - right->eval();
         case MULT: return left-> eval() * right->eval();
         case DIV: return left-> eval() / right->eval();
       }
     }
};
