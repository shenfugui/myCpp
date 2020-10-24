#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100005;
struct node
{
    vector<int> num, w;
    int s = 0;
} desk[MAX];

int main()
{
    int n, q;
    cin >> n >> q;
    while (q--)
    {
        int x, a, b, c;
        cin >> x;
        if (x == 1)
        {
            cin >> a >> b >> c;
            desk[a].s++;
            desk[a].num.push_back(b);
            desk[a].w.push_back(c);
        }
        else
        {
            cin >> a >> b;
            for (int i = desk[a].s - 1; i >= 0; i--)
            {
                if (desk[a].num[i] == b)
                {
                    cout << desk[a].w[i] << endl;
                    break;
                }
            }
        }
    }
    
    return 0;
}