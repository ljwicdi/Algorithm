#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
#define MAX_SIZE 1000
typedef struct _stack
{
    int top;
    char data[MAX_SIZE];
} STACK;

void Init(STACK * s)
{
    s->top = -1;
}
bool IsEmpty(STACK * s)
{
    if(s->top == -1)
        return true;
    else
        return false;
}

char Pop(STACK * s)
{
    if(IsEmpty(s))
        cout<<"비어있음"<<endl;
    return s->data[s->top--];

}
void Push(STACK * s, char data)
{
    s->data[++(s->top)] = data;
}

char Peek(STACK * s)
{
    return s->data[s->top];
}
int main(void)
{
    int idx = 0;
    char temp;
    char str[MAX_SIZE];
    STACK * s = (STACK *)malloc(sizeof(STACK));
    Init(s);
    cin>>str;
    char newStr[MAX_SIZE];
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>=65 && str[i]<=90)
        {
            newStr[idx++] = str[i];
        }
        else
        {
            if(IsEmpty(s))
            {
                Push(s,str[i]);
                continue;
            }
            else
            {
                temp = Peek(s);
                if(str[i] == '+' || str[i] == '-')
                {
                    if(temp == '*' || temp == 47 || temp == '+' || temp == '-')
                    {
                        while(!IsEmpty(s) && Peek(s) != '(')
                            newStr[idx++] = Pop(s);
                        Push(s,str[i]);
                        continue;
                    }
                    Push(s,str[i]);
                    continue;
                }
                if(str[i] == '(')
                {
                    Push(s,str[i]);
                    continue;
                }
                if(str[i] == ')')
                {
                    while(Peek(s)!='(')
                        newStr[idx++] = Pop(s);
                    Pop(s);
                    continue;
                }
                if(str[i]=='*' || str[i] == 47)
                {
                    if(temp == '*' || temp == 47)
                    {
                        while(!IsEmpty(s) && Peek(s) != '(' && Peek(s) != '+' && Peek(s) != '-')
                            newStr[idx++] = Pop(s);
                        Push(s,str[i]);
                        continue;
                    }
                    Push(s,str[i]);
                    continue;
                }
            }
            
        }
    }
    while(!IsEmpty(s))
        newStr[idx++] = Pop(s);
    newStr[strlen(newStr)] = '\0';
    cout<<newStr<<endl;
    return 0;
}