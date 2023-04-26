/**************************
이 문제의 핵심
1. 포화이진트리, 완전이진트리를 파악하는 것

2. 이진수를 만들고 앞에 0을 붙여서 임시로 완전 이진트리를 만드는 것

3.재귀함수를 통해 분할정복하여 속도를 높임
**************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string getBinary(int num)
{
    string ret;
    while(num != 0)
    {
        ret += (num % 2 == 0 ? '0' : '1');
        num /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string getFullBinary(long long num)
{
    string binary = getBinary(num);

    int binaryLen = binary.length();
    int level = 1;
    int totalNode = 1;

    while(true)
    {
        if(binaryLen <= totalNode) 
        {
            break;
        }
        level *= 2;
        totalNode += level;
    }

    int offset = totalNode - binaryLen;

    string ret = "";
    for(int i = 0; i < offset; i++)
    {
        ret += "0";
    }
    return ret + binary;
}

bool isOneTree(string binary)
{
    int binaryLen = binary.length();
    if(binaryLen == 0)
    {
        return true;
    }

    int root = binaryLen /2;
    string leftSubTree = binary.substr(0, root);
    string rightSubTree = binary.substr(root+1);

    if(binary.at(root) == '1')
    {
        return false;
    }

    return isOneTree(leftSubTree) && isOneTree(rightSubTree);
}

bool isBinaryTree(string binary)
{
    int binaryLen = binary.length();
    if(binaryLen == 0)
    {
        return true;
    }

    int root = binaryLen / 2;
    string leftSubTree = binary.substr(0, root);
    string rightSubTree = binary.substr(root+1);

    if(binary.at(root) == '0')
    {
        return isOneTree(leftSubTree) && isOneTree(rightSubTree);
    }

    return isBinaryTree(leftSubTree) && isBinaryTree(rightSubTree);
}

int main()
{
    long long number = 95;

    string binary = getFullBinary(number);

    int answer = -1;
    if(isBinaryTree(binary))
    {   
        answer = 1;
    }
    else
    {
        answer = 0;
    }
    
    cout << answer;
    return 0;
}