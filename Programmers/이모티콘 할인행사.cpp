/**************************
문제의 핵심
1. discount에 대한 emoticons의 size 길이 만큼의 중복순열을 구할 것

2. 중복 순열을 모두 돌면서 가격 및 서비스 가입자 계산

3. sort를 이용한 가장 큰 수 구하기
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int discount[4] = {
    10,
    20,
    30,
    40
};

static const int RATE = 0;
static const int PRICE = 1;

bool cmp(vector<int> &lvalue, vector<int> &rvalue)
{
    if(lvalue[0] == rvalue[0])
    {
        return lvalue[1] > rvalue[1];
    }
    return lvalue[0] > rvalue[0];
}

//create product with dfs
void createProduct(vector<vector<int>> &product, vector<int> list, int depth, int emotSize)
{
    if(depth == emotSize)
    {
        product.emplace_back(list);
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        list[depth] = discount[i];
        createProduct(product, list, depth+1, emotSize);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    vector<vector<int>> answer;
    vector<vector<int>> product;
    vector<int> list(emoticons.size(), -1);

    createProduct(product, list, 0, emoticons.size());

    for(const auto& discountList : product)
    {
        int subscriber = 0;
        int price = 0;
        for(const auto& user : users)
        {
            int curSubscriber = 0;
            int curPrice = 0;
            for(int idx = 0; idx < emoticons.size(); idx++)
            {
                //isBuy
                if(user[RATE] <= discountList[idx])
                {
                    //calculate Price
                    curPrice += emoticons[idx] / 100 * (100 - discountList[idx]);
                }

                if(user[PRICE] <= curPrice)
                {
                    curSubscriber++;
                    break;
                }
            }

            if(curSubscriber == 1)
            {
                subscriber++;
            }
            else
            {
                price += curPrice;
            }
        }
        vector<int> result;
        result.emplace_back(subscriber);
        result.emplace_back(price);

        answer.emplace_back(result);
    }

    sort(answer.begin(), answer.end(), cmp);

    return answer[0];
}

int main()
{
    vector<vector<int>> users;
    vector<int>user;
    //get user
    user.emplace_back(1);
    user.emplace_back(10000);
    users.emplace_back(user);

    vector<int> emot;
    //get emoticons
    emot.emplace_back(1300);
    emot.emplace_back(1500);
    emot.emplace_back(1600);
    emot.emplace_back(4900);

    vector<int> result = solution(users, emot);

    cout << result[0] << " " << result[1] << endl;  

    return 0;
}