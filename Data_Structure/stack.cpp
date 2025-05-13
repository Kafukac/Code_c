#include <iostream>
using namespace std;

// 链栈节点定义
struct LinkNode
{
    char data;
    LinkNode *next;
    LinkNode(char val) : data(val), next(nullptr) {}
};

// 链栈类定义
class LinkedStack
{
private:
    LinkNode *topNode; // 栈顶指针

public:
    // 构造函数
    LinkedStack() : topNode(nullptr) {}

    // 析构函数
    ~LinkedStack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    // 判断栈是否为空
    bool isEmpty() const
    {
        return topNode == nullptr;
    }

    // 入栈操作
    void push(char item)
    {
        LinkNode *newNode = new LinkNode(item);
        newNode->next = topNode;
        topNode = newNode;
    }

    // 出栈操作
    char pop()
    {
        if (isEmpty())
        {
            cerr << "Stack is empty!" << endl;
            return '\0';
        }
        char topData = topNode->data;
        LinkNode *temp = topNode;
        topNode = topNode->next;
        delete temp;
        return topData;
    }

    // 获取栈顶元素
    char peek() const
    {
        if (isEmpty())
        {
            cerr << "Stack is empty!" << endl;
            return '\0';
        }
        return topNode->data;
    }
};

// 括号匹配检查函数
bool BracketCheck(const char str[], int length)
{
    LinkedStack stack;

    for (int i = 0; i < length; i++)
    {
        // 如果是左括号，则入栈
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            stack.push(str[i]);
        }
        // 如果是右括号
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            // 栈为空，右括号多余
            if (stack.isEmpty())
            {
                return false;
            }

            char topElem = stack.pop();

            // 检查括号是否匹配
            if ((str[i] == ')' && topElem != '(') ||
                (str[i] == ']' && topElem != '[') ||
                (str[i] == '}' && topElem != '{'))
            {
                return false;
            }
        }
        // 非括号字符，忽略
    }

    // 栈不为空，左括号多余
    return stack.isEmpty();
}

int main()
{
    char test[] = "{[()]}";
    cout << "Bracket check result: "
         << (BracketCheck(test, sizeof(test) - 1) ? "Valid" : "Invalid")
         << endl;
    return 0;
}
