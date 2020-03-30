#include <vector>
#include <map>
#include <iostream>
#include <memory>
#include <assert.h>
#include <stdexcept>
using namespace std;

class TreeNode
{
public:
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val{v}, left{NULL}, right{NULL} {}
};

enum class OPTYPE
{
    NUM,
    OPER,
};
struct OP
{
    char c;
    int n;
    OPTYPE type;
};

class Solution
{
public:
    vector<int> diffWaysToCompute(string input)
    {
        auto ops = resolveExpress(input);
        printExpress(ops);
        int size = ops.size();

        return get_expresss_value(ops, 0, size - 1);
    }

    vector<int> get_expresss_value(vector<OP> &ops, int start, int end)
    {
        if (start > end)
        {
            throw(logic_error("start >= end"));
        }
        vector<int> ans;
        if (start == end)
        {
            ans.push_back(ops[start].n);
            return ans;
        }

        for (int i = start; i <= end; i++)
        {
            if (ops[i].type == OPTYPE::NUM)
            {
                continue;
            }
            
            auto lvalues = get_expresss_value(ops, start, i - 1);
            auto rvalues = get_expresss_value(ops, i + 1, end);
            for (auto &&l : lvalues)
            {
                for (auto &&r : rvalues)
                {
                    int val;
                    switch (ops[i].c)
                    {
                    case '+':
                        val = l + r;
                        break;
                    case '-':
                        val = l - r;
                        break;
                    case '*':
                        val = l * r;
                        break;
                    default:
                        break;
                    }
                    ans.push_back(val);
                }
            }
        }
        return ans;
    }

    vector<OP> resolveExpress(const string &input)
    {
        vector<OP> ops;
        int size = input.size();
        for (int start = 0; start < size;)
        {
            OP new_op;
            //数字
            int end = start;
            while (input[end] >= '0' && input[end] <= '9')
            {
                end++;
            }

            if (start < end)
            {
                new_op.n = atoi(input.substr(start, end - start).c_str());
                new_op.type = OPTYPE::NUM;
                start = end;
            }
            else
            {
                new_op.c = input[start];
                new_op.type = OPTYPE::OPER;
                start++;
            }
            ops.push_back(new_op);
        }

        return ops;
    }

    void printExpress(vector<OP> &ops)
    {
        for (auto &&e : ops)
        {
            if (e.type == OPTYPE::NUM)
            {
                cout << e.n << " ";
            }
            else
            {
                cout << e.c << " ";
            }
        }
        cout << endl;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1)
    {
        length = list.size();
    }

    if (length == 0)
    {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++)
    {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string input = stringToString(line);

        vector<int> ret = Solution().diffWaysToCompute(input);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}