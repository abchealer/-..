/*42点问题（dfs递归，vector容器+map）*/

////vector容器+map（最后一行测试点没通过）
#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<string,int> mp{{"A",1},{"2",2},{"3",3},{"4",4},{"5",5},{"6",6},
	{"7",7},{"8",8},{"9",9},{"J",11},{"Q",12},{"K",13}};
	vector<vector<int>> arr;
	vector<int> tlm;
	arr.resize(6);
    //数据输入
	string x;
	for (int i = 0; i < 6; i++)
	{
		cin >> x;
		tlm.push_back(mp[x]);
	}

    //vector容器
	arr[0].push_back(tlm[0]);
	for (int j = 1; j <= 5; j++)
	{
		for (int k = 0; k < arr[j-1].size(); k++)
		{
			arr[j].push_back(arr[j-1][k] + tlm[j]);
			arr[j].push_back(arr[j-1][k] - tlm[j]);
			arr[j].push_back(arr[j-1][k] * tlm[j]);
			arr[j].push_back(arr[j-1][k] / tlm[j]);
		}
	}
    //输出
	int flag = 0;
	for (int p = 0; p < arr[5].size(); p++)
	{
		if (arr[5][p] == 42)
		{
			flag = 1;
			break;
		}
	}

	if (flag)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}



////vector容器（无map）（未通过）
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int arr[100];
int i,j;
vector <int> ans[10];

int main(){
    //数据输入
    for(i=0;i<6;i++){
        char c;
        cin>>c;
        if(c=='A')
            arr[i]=1;
        else if(c=='K')
            arr[i]=13;
        else if(c=='J')
            arr[i]=11;
        else if(c=='Q')
            arr[i]=12;
        else
        {
            arr[i]=(c-'0');
            //stoi接收的是字符串  ,stoi:"string to integer"
            /*string str(1,c);
            arr[i]=stoi(str);*/
            
        }
            
        
    }
    //vector容器，类似栈动态储存
    ans[0].push_back(arr[0]);
    for( i=1;i<6;i++){
        for( j=0;j<ans[i-1].size();j++){
            ans[i].push_back(ans[i-1][j]+arr[i]);
            ans[i].push_back(ans[i-1][j]-arr[i]);
            ans[i].push_back(ans[i-1][j]*arr[i]);
            ans[i].push_back(ans[i-1][j]/arr[i]);

        }
    }
    //输出‘
    int pt=0;
    for(i=0; i<ans[5].size();i++){
        if(ans[5][i]==42){
            pt=1;
            break;
        }
            

    
    }
    if(pt==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
////dfs递归（最后一行测试点未过）
#include <bits/stdc++.h>
using namespace std;
int stk[6], top = 0;
int a[14];
bool ans = false;

void dfs(int dep)
{
    // 递归边界
    if (dep == 6) {
        int cnt = a[1];
        for (int i = 2, j = 1; i <= 6; i++) {
            if (stk[j] == 1)
                cnt += a[i];
            else if (stk[j] == 2)
                cnt -= a[i];
            else if (stk[j] == 3)
                cnt *= a[i];
            else
                cnt /= a[j];
            j++;
        }
        if (cnt == 42)
            ans = true;
        return;
    }
    // 递归关系式
    for (int i = 1; i <= 4; i++) {
        stk[++top] = i;
        dfs(dep + 1);
        top--;
    }
}

int main()
{
    char s[10];
    for (int i = 1; i <= 6; i++)
        cin >> s[i];
    for (int i = 1; i <= 6; i++){
        if(s[i]>'1'&& s[i]<= '9')a[i]= s[i]- '0';
        else{
            if(s[i]=='A')
                a[i]=1;
            else if(s[i]=='J')
                a[i]=11;
            else if(s[i]=='Q')
                a[i]=12;
            else if(s[i]=='K')
                a[i]=13;
        }
    }
    dfs(1);
    cout<<(ans?"YES":"NO");

        return 0;
}